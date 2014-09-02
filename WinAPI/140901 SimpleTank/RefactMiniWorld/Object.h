
#pragma once

#include <Windows.h>

enum MoveState { NOMOVE, LEFT, RIGHT, UP, DOWN, SPACE };

struct KeyControl{
	BOOL left;
	BOOL right;
	BOOL up;
	BOOL down;
};

typedef class CObject {
public:
	virtual ~CObject() {};
	virtual void update(float delta) = 0;
	virtual void render(HDC &hdc) = 0;
	POINT getPos() { return _pos; }
	void setPos(POINT& in){
		_pos = in;
	}
protected:
	POINT _pos;
} COBJECT, *LPCOBJECT;


class Player : public COBJECT{
public:
	Player(){
		_pos = { 100, 100 };
		_size = 15;
		_kc = { false, false, false, false };
		_lastdr = RIGHT;
	};

	Player(POINT pos, int size){
		_pos = pos;
		_size = size;
		_kc = { false, false, false, false };
		_lastdr = RIGHT;
	}

	int getSize(){ return _size; }
	KeyControl getKC(){ return _kc; }

	BOOL checkBound(RECT &_map){
		BOOL ret = (_pos.x - _size <= _map.left ||
			_pos.x + _size >= _map.right ||
			_pos.y - _size <= _map.top ||
			_pos.y + _size >= _map.bottom);
		return ret;
	}

	void setDir(MoveState in) {
		switch (in){
		case LEFT:
			if (_kc.right = true){
				_kc.right = false;
			}
			_lastdr = LEFT;
			_kc.left = true;
			break;
		case RIGHT:
			if (_kc.left = true){
				_kc.left = false;
			}
			_lastdr = RIGHT;
			_kc.right = true;
			break;
		case UP:
			if (_kc.down = true){
				_kc.down = false;
			}
			_lastdr = UP;
			_kc.up = true;
			break;
		case DOWN:
			if (_kc.up = true){
				_kc.up = false;
			}
			_lastdr = DOWN;
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

	void update(float delta){
		if (_kc.left){ _pos.x -= 10; }
		if (_kc.right){ _pos.x += 10; }
		if (_kc.up){ _pos.y -= 10; }
		if (_kc.down){ _pos.y += 10; }
	}

	void render(HDC &hdc){
		::Rectangle(hdc,
			_pos.x - _size-2,
			_pos.y - _size-2,
			_pos.x + _size+2,
			_pos.y + _size+2);

		::Ellipse(hdc,
			_pos.x - _size,
			_pos.y - _size,
			_pos.x + _size,
			_pos.y + _size);


		HPEN myPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, myPen);
		switch (_lastdr)
		{
		case NOMOVE:
			break;
		case LEFT:
			::MoveToEx(hdc, _pos.x, _pos.y, NULL);
			::LineTo(hdc, _pos.x - 30, _pos.y);
			break;
		case RIGHT:
			::MoveToEx(hdc, _pos.x, _pos.y, NULL);
			::LineTo(hdc, _pos.x + 30, _pos.y);
			break;
		case UP:
			::MoveToEx(hdc, _pos.x, _pos.y, NULL);
			::LineTo(hdc, _pos.x, _pos.y-30);
			break;
		case DOWN:
			::MoveToEx(hdc, _pos.x, _pos.y, NULL);
			::LineTo(hdc, _pos.x, _pos.y + 30);
			break;
		case SPACE:
			break;
		default:
			break;
		}
		SelectObject(hdc, oldPen);
		DeleteObject(myPen);
	}

	MoveState getLastdir(){ return _lastdr; }

private:
	//POINT _pos;
	int _size;
	KeyControl _kc;
	MoveState _lastdr;
};

class Bullet : public CObject{
public:
	Bullet(){}
	Bullet(int x, int y, MoveState direction){
		_pos = { x, y };
		_direction = direction;
	}
	~Bullet(){}

	void update(float delta){
		//_pos.y -= _bulletSpeed * delta;
		switch (_direction)
		{
		case LEFT:
			_pos.x -= _bulletSpeed;
			break;
		case RIGHT:
			_pos.x += _bulletSpeed;
			break;
		case UP:
			_pos.y -= _bulletSpeed;
			break;
		case DOWN:
			_pos.y += _bulletSpeed;
			break;
		default:
			break;
		}
		
	}

	void render(HDC &hdc){
		HBRUSH myBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		::Ellipse(hdc,
			_pos.x - _size,
			_pos.y - _size,
			_pos.x + _size,
			_pos.y + _size);
		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}

	BOOL checkBound(RECT &_map){
		BOOL ret = (_pos.x - _size <= _map.left ||
			_pos.x + _size >= _map.right ||
			_pos.y - _size <= _map.top ||
			_pos.y + _size >= _map.bottom);
		return ret;
	}

	int getSize() { return _size; }

private:
	//POINT _pos;
	const int _size = 3;
	const int _bulletSpeed = 15;
	MoveState _direction;
};

class Enemy : public CObject{
public:
	Enemy(){
		_hp = 1;
	}

	Enemy(RECT& in){
		_reg = in;
	}

	void update(float delta){};
	void render(HDC &hdc){}

	BOOL isHittedbyBullet(Bullet &bullet){
		int hcollidingRange = bullet.getSize() + (_reg.right - _reg.left)/2;
		int vcollidingRange = bullet.getSize() + (_reg.bottom - _reg.top)/2;
		int hRange = abs(bullet.getPos().x - (_reg.left + (_reg.right - _reg.left) / 2));
		int vRange = abs(bullet.getPos().y - (_reg.top + (_reg.bottom - _reg.top) / 2));
		return	(hRange <= hcollidingRange) && (vRange <= vcollidingRange);
	}

	void getHitted(){
		_hp--;
	}

	BOOL isDead(){
		return _hp <= 0;
	}

private:
	int _hp;
	RECT _reg;
};