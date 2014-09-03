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
#include <queue>
#include "Object.h"

using std::vector;
using std::queue;


class World{
public:
	World();

	World(int nRow, int nColumn);

	~World();

	void updateMap(RECT &clientRect);
	void update(float delta);
	void render(HDC hdc);
	void mbLbuttonDown(int x, int y);	
	void mbRbuttonDowns(int x, int y);
	void kbDown(WPARAM& wParam);
	void kbUp(WPARAM& wParam);

	// getter
	RECT getTile(){ return _tile; }
	int getNumRow(){ return _numRow; }
	int getNumColumn(){ return _numColumn; }
	vector<Enemy*> getObjects(){ return _vEnemy; }
	BOOL isMoving(){ return move; }

	//setter
	void setMoving(BOOL in){ in = move; }

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
	queue<Bullet*> _qbullets;  
};