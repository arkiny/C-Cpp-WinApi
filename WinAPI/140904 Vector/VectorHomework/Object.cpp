#include "Object.h"

Turret::Turret(){
	_pos = { 100, 100 };
	_size = 15;
	_kc = { false, false, false, false, false };
	_degree = 30;
};

Turret::Turret(POINT pos, int size){
	_pos = pos;
	_size = size;
	_kc = { false, false, false, false, false };
	_degree = 30;
}

void Turret::setDegree(int inputDegree) { _degree = inputDegree; }

void Turret::setPos(int x, int y){
	_pos.x = x;
	_pos.y = y;
}

void Turret::update(float delta){
	// key에 따라 각도 조절
	if (_kc.left){ _degree -= 10; }
	if (_kc.right){ _degree += 10; }

	/*if (_kc.up){
		float rad = degreeToRadian();
		_pos = {
			_pos.x + cosf(rad) * _speed,
			_pos.y + sinf(rad) * _speed
		};
	}

	if (_kc.down){
		float rad = degreeToRadian();
		_pos = {
			_pos.x - cosf(rad) * _speed,
			_pos.y - sinf(rad) * _speed
		};
	}*/

}

void Turret::render(HDC &hdc){
	::Ellipse(hdc,
		_pos.x - _size,
		_pos.y - _size,
		_pos.x + _size,
		_pos.y + _size);


	HPEN myPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, myPen);

	::MoveToEx(hdc, _pos.x, _pos.y, NULL);

	float x = cosf(degreeToRadian())*_barrelSize + _pos.x;
	float y = sinf(degreeToRadian())*_barrelSize + _pos.y;

	::LineTo(hdc, (int)x, (int)y);

	SelectObject(hdc, oldPen);
	DeleteObject(myPen);
}

void Turret::setDir(MoveState in) {
	switch (in){
	case LEFT:
		if (_kc.right = true){
			_kc.right = false;
		}
		_kc.left = true;
		break;
	case RIGHT:
		if (_kc.left = true){
			_kc.left = false;
		}
		_kc.right = true;
		break;
	case UP:
		if (_kc.down = true){
			_kc.down = false;
		}
		_kc.up = true;
		break;
	case DOWN:
		if (_kc.up = true){
			_kc.up = false;
		}
		_kc.down = true;
		break;
	case SPACE:
		_kc.space = true;
		break;
	default:
		break;
	}
}

void Turret::unsetDir(MoveState in){
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
	case SPACE:
		_kc.space = false;
		break;
	default:
		break;
	}
}