/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	WORLD 관리 클래스
	Object들을 관리하며, Renderer에 필요한 정보들을 불러준다.
*/

#pragma once

#include <Windows.h>
#include <vector>

using std::vector;

typedef struct CObject {
	POINT _pos;
} COBJECT, *LPCOBJECT;

class World{
public:
	World(){
		_cobjects.clear();
	}

	World(int nRow, int nColumn){
		_numRow = nRow + 1;
		_numColumn = nColumn +1 ;
	}

	~World(){
		while (!_cobjects.empty()){
			// redo memory control
			_cobjects.pop_back();
			_cobjects.shrink_to_fit();		
		}				
	}

	void updateMap(RECT &clientRect){
		_tile.left = clientRect.left;
		_tile.top = clientRect.top;
		_tile.right = clientRect.left + clientRect.right / _numColumn;
		_tile.bottom = clientRect.top + clientRect.bottom / _numRow;
		_tileWidth = _tile.right - _tile.left;
		_tileHeight = _tile.bottom - _tile.top;
	}

	void update(float delta){
		// todo
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

	void addObject(int x, int y){		
		if (isCurInside(x, y))
		{
			LPCOBJECT ptr = new COBJECT();
			ptr->_pos = getTileCoordinate(x, y);
			_cobjects.push_back(ptr);
			ptr = nullptr;
		}
	}

	void deleteObject(int x, int y){
		POINT coordnate = getTileCoordinate(x, y);
		void* ptr = nullptr;

		for (int i = 0; i < _cobjects.size(); i++){
			if (_cobjects[i]->_pos.x == coordnate.x &&
				_cobjects[i]->_pos.y == coordnate.y){
				ptr = _cobjects[i];
				delete[] ptr;
				_cobjects.erase(_cobjects.begin() + i);
				_cobjects.shrink_to_fit();
				break;
			}
		}
		ptr = nullptr;
	}

	void moveObject(int fx, int fy, int tx, int ty){
		POINT coordnate = getTileCoordinate(fx, fy);
		POINT tcoordnate = getTileCoordinate(tx, ty);
		if (_cobjects.size() == 0){
			addObject(tx, ty); // 오브젝트 db에 아무것도 없을경우
		}
		else{
			if (inList(coordnate.x, coordnate.y)){
				LPCOBJECT a = findObject(fx, fy);
				a->_pos.x = tcoordnate.x;
				a->_pos.y = tcoordnate.y;
			}
			else {
				addObject(tx, ty); // 출발 기록이 없을경우
			}
		}
	}

	LPCOBJECT findObject(int x, int y){
		POINT coordnate = getTileCoordinate(x, y);
		for (int i = 0; i < _cobjects.size(); i++){
			if (_cobjects[i]->_pos.x == coordnate.x &&
				_cobjects[i]->_pos.y == coordnate.y){
				return _cobjects[i];
			}
		}
		return nullptr;
	}

	BOOL inList(int x, int y){
		for (int i = 0; i < _cobjects.size(); i++){
			if (_cobjects[i]->_pos.x == x &&
				_cobjects[i]->_pos.y == y) return true;
		}
		return false;
	}

	RECT getTile(){
		return _tile;
	}

	int getNumRow(){
		return _numRow;
	}

	int getNumColumn(){
		return _numColumn;
	}

	vector<LPCOBJECT> getObjects(){
		return _cobjects;
	}

	void setMoving(BOOL in){
		in = move;
	}

	BOOL isMoving(){
		return move;
	}

private:	
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

	int _numRow = 0;
	int _numColumn = 0;
	float _tileWidth = 0;
	float _tileHeight = 0;
	BOOL move =false;
	RECT _tile;
	vector<LPCOBJECT> _cobjects;
};

