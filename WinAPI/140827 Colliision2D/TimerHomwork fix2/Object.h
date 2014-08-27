/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once
#include <Windows.h>

enum MoveState { NOMOVE, LEFT, RIGHT, UP, DOWN };

struct KeyControl{
	BOOL left;
	BOOL right;
	BOOL up;
	BOOL down;
};

class Object {
public:
	virtual ~Object() {};
	virtual void update() = 0;
};

class Obstacle : public Object{
public:
	Obstacle(){};

	Obstacle(POINT pos, int size){
		_pos = pos;
		_size = size;
		_dir = LEFT;
	}

	int getSize(){	return _size;	}
	MoveState getDir(){ return _dir; }
	POINT getPos(){ return _pos; }
	BOOL checkBound(RECT &_map){
		BOOL ret = (_pos.x - _size <= _map.left ||
			_pos.x + _size >= _map.right ||
			_pos.y - _size <= _map.top ||
			_pos.y + _size >= _map.bottom);
		return ret;
	}

	void setDir(MoveState in) { _dir = in; }
	void setPos(int x, int y){
		_pos.x = x;
		_pos.y = y;
	}

	void update(){
		switch (_dir)
		{
		case LEFT:
			_pos.x -= 5;
			break;
		case RIGHT:
			_pos.x += 5;
			break;
		default:
			break;
		}
	}	

private:
	POINT _pos;
	int _size;
	MoveState _dir;	
};

class Player : public Object{
public:
	Player(){};

	Player(POINT pos, int size){
		_pos = pos;
		_size = size;
		_kc = { false, false, false, false };
	}

	int getSize(){ return _size; }
	KeyControl getKC(){ return _kc; }
	POINT getPos(){ return _pos; }

	BOOL checkBound(RECT &_map){
		BOOL ret = (_pos.x - _size <= _map.left ||
			_pos.x + _size >= _map.right ||
			_pos.y - _size <= _map.top ||
			_pos.y + _size >= _map.bottom);
		return ret;
	}

	void setDir(MoveState in) { 
		switch(in){
		case LEFT:
			_kc.left = true;
			break;
		case RIGHT:
			_kc.right = true; 
			break;
		case UP:
			_kc.up = true;
			break;
		case DOWN:
			_kc.down = true;
			break;		
		default:
			break;
		}
	}

	void unsetDir(MoveState in){
		switch (in){
		case LEFT:
			_kc.left = false;
			break;
		case RIGHT:
			_kc.right = false;
			break;
		case UP:
			_kc.up = false;
			break;
		case DOWN:
			_kc.down = false;
			break;
		default:
			break;
		}
	}

	void setPos(int x, int y){
		_pos.x = x;
		_pos.y = y;
	}

	void update(){		
		if (_kc.left){ _pos.x -= 10; }
		if (_kc.right){ _pos.x += 10; }
		if (_kc.up){ _pos.y -= 10; }
		if (_kc.down){ _pos.y += 10; }		
	}

private:
	POINT _pos;
	int _size;
	KeyControl _kc;
};