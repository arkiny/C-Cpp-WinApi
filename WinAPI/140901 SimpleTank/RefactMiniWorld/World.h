/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	WORLD 관리 클래스
	Object들을 관리하며 각 object간의 상호작용, 

	셀의 위치가 30, 30이거나 플레이어 위치가 거기이거나 한다면
	움직이는 놈이 위치가 있으면
	충동영역들을 비교할수 있다.


*/

#pragma once

#include <Windows.h>
#include <vector>
#include <mutex>
#include <queue>
#include "Object.h"


using std::vector;
using std::queue;


class World{
public:
	World(){
		_player = new Player();
		_vEnemy.clear();
	}

	World(int nRow, int nColumn){
		_player = new Player();
		_numRow = nRow + 1;
		_numColumn = nColumn +1 ;
		
	}

	~World(){
		Enemy* ptr;
		while (!_vEnemy.empty()){
			ptr = _vEnemy.back();
			if (ptr != nullptr){
				delete ptr;
			}
			_vEnemy.pop_back();
			_vEnemy.shrink_to_fit();
		}				

		Bullet* bptr;
		while (!_qbullets.empty()){
			bptr = _qbullets.front();
			if (bptr != nullptr){
				delete bptr;
			}
			_qbullets.pop();			
		}

		if (_player != nullptr){
			delete _player;
			_player = nullptr;
		}
	}

	void updateMap(RECT &clientRect){
		_tile.left = clientRect.left;
		_tile.top = clientRect.top;
		_tile.right = (clientRect.right-200) / _numColumn ;
		_tile.bottom = clientRect.bottom / _numRow;
		
		_tileWidth = _tile.right - _tile.left;
		_tileHeight = _tile.bottom - _tile.top;

		_tileMap.left = clientRect.left + (_tileWidth / 2);
		_tileMap.top = clientRect.top + (_tileHeight / 2);
		_tileMap.right = _tileMap.left + (_tileWidth * (_numColumn-1));
		_tileMap.bottom = _tileMap.top + (_tileHeight * (_numRow-1));
	}

	void update(float delta){
		// 플레이어 맵 충돌처리
		if (_player->checkBound(_tileMap)){
			POINT pp = _player->getPos();
			if (_player->getPos().x - _player->getSize() <= _tileMap.left){
				_player->setPos(pp.x + 1, pp.y);
			}
			else if (_player->getPos().x + _player->getSize() >= _tileMap.right){
				_player->setPos(pp.x - 1, pp.y );
			}

			else if (_player->getPos().y - _player->getSize() <= _tileMap.top){
				_player->setPos(pp.x, pp.y+1);
			}
			else if (_player->getPos().y + _player->getSize() >= _tileMap.bottom){
				_player->setPos(pp.x, pp.y -1);
			}
		} 
		else {
			_player->update(delta);
		}

		///////////
		// 장대한 삽질의 결과... 쉽게 Array로 하려다가 시간만 버림
		//////////
		//Bullet* ptr = nullptr;
		//if (_qbullets.size() <= 0){
		//	ptr = new Bullet(_player->getPos().x, _player->getPos().y, _player->getLastdir());
		//	_vbullets.push_back(ptr);
		//}
		//else {
		//	ptr = _qbullets.front();
		//	_qbullets.pop();
		//}
		//if (ptr != NULL)
		//{
		//	ptr->update(delta);
		//}


		//if (!_vbullets.empty()){
		//	for (int i = 0; i < _vbullets.size(); i++){
		//		_vbullets[i]->update(delta);
		//		//
		//		if (!_cobjects.empty()){
		//			for (int j = 0; j < _cobjects.size(); j++){
		//				if (_cobjects[j] != NULL){						
		//					if (_vbullets.size()>0 ){ // 이건 아무래도 동기화 에러인가 보다								
		//						if (_cobjects[j]->isHittedbyBullet(*_vbullets[i])){

		//							Enemy* ptr = _cobjects[j];
		//							delete ptr;
		//							ptr = nullptr;
		//							_cobjects.erase(_cobjects.begin() + j);


		//							// 포탄 삭제처리해야함...
		//							if (_vbullets[i] != NULL){
		//								Bullet* ptr2 = _vbullets[i];
		//								delete ptr2;
		//								ptr2 = nullptr;
		//								_vbullets.erase(_vbullets.begin() + i);
		//							}
		//						}
		//					}
		//				}
		//			}
		//			_cobjects.shrink_to_fit(); // resizing after the loop
		//		}
		//	}
		//	_vbullets.shrink_to_fit(); // resizing here, after the for loop
		//}		

		// queue와 stack을 이용한 데이터 주고받기를 통해 조건 업데이트 실시
		// 가장 원초적인 건데 왜 안쓰려고 하고 있었을까.....
		// updating and border check
		// 강사님이 가르쳐준 다른 방법으로는
		// 45개를 미리 queue에 넣어두고
		// vector를 이용해서 그 45개를 순환시키는 방법이 있다.
		Bullet* ptr = nullptr;
		Enemy* eptr = nullptr;
		while (!_qbullets.empty()){
			ptr = _qbullets.front();
			_qbullets.pop();
			ptr->update(delta);
			if (ptr->checkBound(_tileMap)){
				delete ptr;
			}
			else{
				_vbullets.push_back(ptr);
			}

			while (!_vEnemy.empty()){
				eptr = _vEnemy.back();
				_vEnemy.pop_back();
				if (eptr->isHittedbyBullet(*ptr)){	
					_vbullets.pop_back();
					delete eptr;
					delete ptr;
				}
				else {
					_qEnemy.push(eptr);
				}
			}

			while (!_qEnemy.empty()){
				eptr = _qEnemy.front();
				_qEnemy.pop();
				_vEnemy.push_back(eptr);
			}
		}
		while (!_vbullets.empty()){
			ptr = _vbullets.back();
			_vbullets.pop_back();
			_qbullets.push(ptr);
		}

		ptr = nullptr;
		eptr = nullptr;
	}

	void render(HDC hdc){		
		TCHAR in[20];
		wsprintf(in, L"포탄수 : %d", _qbullets.size());
		::TextOut(hdc, 828, 200, in, wcslen(in));
		wsprintf(in, L"적타일 수 : %d", _vEnemy.size());
		::TextOut(hdc, 828, 220, in, wcslen(in));

		for (int i = 0; i < getNumRow() - 1; i++){
			for (int j = 0; j < getNumColumn() - 1; j++){
				::Rectangle(hdc,
					(getTile().left + (i*getTile().right) + (getTile().right / 2)),
					(getTile().top + (j*getTile().bottom) + (getTile().bottom / 2)),
					(getTile().right + (i*getTile().right) + (getTile().right / 2)),
					(getTile().bottom + (j*getTile().bottom) + (getTile().bottom / 2)));
			}
		}

		HBRUSH myBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		if (!getObjects().empty()){
			for (int i = 0; i < getObjects().size(); i++){
				RECT obj = getTileRect(getObjects()[i]->getPos().x, getObjects()[i]->getPos().y);
				::Rectangle(hdc, obj.left, obj.top, obj.right, obj.bottom);
			}
		}

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

		_player->render(hdc);

		Bullet* ptr = nullptr;
		while (!_qbullets.empty()){
			ptr = _qbullets.front();
			_qbullets.pop();
			ptr->render(hdc);

			_vbullets.push_back(ptr);
		}
		while (!_vbullets.empty()){
			ptr = _vbullets.back();
			_vbullets.pop_back();
			_qbullets.push(ptr);
		}		
	}



	// getter
	RECT getTile(){	return _tile;}
	int getNumRow(){ return _numRow; }
	int getNumColumn(){	return _numColumn;	}
	vector<Enemy*> getObjects(){ return _vEnemy; }
	BOOL isMoving(){ return move; }

	//setter
	void setMoving(BOOL in){ in = move; }

	void mbLbuttonDown(int x, int y){
		if (!inList(getTileCoordinate(x, y).x,
			getTileCoordinate(x, y).y)){
			addObject(x, y);
		}
	}
	
	void mbRbuttonDowns(int x, int y){
		if (inList(getTileCoordinate(x, y).x,
			getTileCoordinate(x, y).y)){
			deleteObject(x, y);
		}
	}


	void kbDown(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player->setDir(RIGHT);
			break;
		case VK_LEFT:
			_player->setDir(LEFT);
			break;
		case VK_UP:
			_player->setDir(UP);
			break;
		case VK_DOWN:
			_player->setDir(DOWN);
			break;
		case VK_SPACE:
			//맵 위에 총알 생성
			Bullet* ptr = new Bullet(_player->getPos().x, _player->getPos().y, _player->getLastdir());
			_qbullets.push(ptr);			
			ptr = nullptr;
			break;
		}
	}

	void kbUp(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player->unsetDir(RIGHT);
			break;
		case VK_LEFT:
			_player->unsetDir(LEFT);
			break;
		case VK_UP:
			_player->unsetDir(UP);
			break;
		case VK_DOWN:
			_player->unsetDir(DOWN);
			break;
		}
	}

private:	
	void addObject(int x, int y){
		if (isCurInside(x, y))
		{
			// 이부분 차후 어레이로 수정
			Enemy* ptr = new Enemy(getTileRect(getTileCoordinate(x, y).x, getTileCoordinate(x, y).y));
			ptr->setPos(getTileCoordinate(x, y));
			_vEnemy.push_back(ptr);
			ptr = nullptr;
			// 이부분 차후 어레이로 수정
		}
	}

	void deleteObject(int x, int y){
		POINT coordnate = getTileCoordinate(x, y);
		void* ptr = nullptr;

		// 이부분 차후 어레이로 수정
		for (int i = 0; i < _vEnemy.size(); i++){
			if (_vEnemy[i]->getPos().x == coordnate.x &&
				_vEnemy[i]->getPos().y == coordnate.y){
				ptr = _vEnemy[i];
				delete[] ptr;
				_vEnemy.erase(_vEnemy.begin() + i);
				_vEnemy.shrink_to_fit();
				break;
			}
		}
		ptr = nullptr;
		//
	}

	void moveObject(int fx, int fy, int tx, int ty){
		POINT coordnate = getTileCoordinate(fx, fy);
		POINT tcoordnate = getTileCoordinate(tx, ty);

		// 이부분 차후 어레이로 수정

		if (_vEnemy.size() == 0){
			addObject(tx, ty); // 오브젝트 db에 아무것도 없을경우
		}
		else{
			if (inList(coordnate.x, coordnate.y)){
				LPCOBJECT a = findObject(fx, fy);
				a->setPos(tcoordnate);
			}
			else {
				addObject(tx, ty); // 출발 기록이 없을경우
			}
		}

		// 이부분 차후 어레이로 수정
	}

	POINT getTileCoordinate(int x, int y){
		POINT ret;
		ret = { (x - (_tileWidth / 2)) / _tileWidth,
			(y - (_tileHeight / 2)) / _tileHeight
		};
		return ret;
	}

	RECT getTileRect(int x, int y){
		RECT ret = makeTile(x, y);
		return ret;
	}

	RECT makeTile(int x, int y){
		RECT ret = { x*_tile.right+(_tile.right/2), 
			y*_tile.bottom + (_tile.bottom/2),
			(x*_tile.right) + _tile.right + (_tile.right / 2),
			(y*_tile.bottom) + _tile.bottom + (_tile.bottom / 2) };
		return ret;
	}

	BOOL isCurInside(int x, int y){
		POINT check = getTileCoordinate(x, y);
		return (check.x < _numColumn - 1 &&
			check.y < _numRow - 1 &&
			x >(_tileWidth / 2) &&
			y >(_tileHeight / 2));
	}

	LPCOBJECT findObject(int x, int y){
		POINT coordnate = getTileCoordinate(x, y);
		for (int i = 0; i < _vEnemy.size(); i++){
			if (_vEnemy[i]->getPos().x == coordnate.x &&
				_vEnemy[i]->getPos().y == coordnate.y){
				return _vEnemy[i];
			}
		}
		return nullptr;
	}

	BOOL inList(int x, int y){
		for (int i = 0; i < _vEnemy.size(); i++){
			if (_vEnemy[i]->getPos().x == x &&
				_vEnemy[i]->getPos().y == y) return true;
		}
		return false;
	}

	float _numRow = 0;
	float _numColumn = 0;
	float _tileWidth = 0;
	float _tileHeight = 0;
	BOOL move =false;

	RECT _tile;
	RECT _tileMap;

	Player* _player;

	vector<Enemy*> _vEnemy;
	queue<Enemy*> _qEnemy;
	vector<Bullet*> _vbullets;	
	queue<Bullet*> _qbullets;  // 큐이용한 재활용은 도전했다 실패
};

