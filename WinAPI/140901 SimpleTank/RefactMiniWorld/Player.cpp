#include "Object.h"

Player::Player(){
	_pos = { 100, 100 };
	_size = 15;
	_kc = { false, false, false, false, false };
	_degree = 30;
};

Player::Player(POINT pos, int size){
	_pos = pos;
	_size = size;
	_kc = { false, false, false, false, false };
	_degree = 30;
}


void Player::setDegree(int inputDegree) { _degree = inputDegree; }

BOOL Player::checkBound(RECT &_map){
	BOOL ret = (_pos.x - _size <= _map.left ||
		_pos.x + _size >= _map.right ||
		_pos.y - _size <= _map.top ||
		_pos.y + _size >= _map.bottom);
	return ret;
}

void Player::setPos(int x, int y){
	_pos.x = x;
	_pos.y = y;
}

void Player::update(float delta){
	// key에 따라 각도 조절
	if (_kc.left){ _degree -= 10; }
	if (_kc.right){ _degree += 10; }

	if (_kc.up){
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
	}

}

void Player::render(HDC &hdc){
	::Rectangle(hdc,
		_pos.x - _size - 2,
		_pos.y - _size - 2,
		_pos.x + _size + 2,
		_pos.y + _size + 2);

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

	::LineTo(hdc, x, y);

	SelectObject(hdc, oldPen);
	DeleteObject(myPen);
}

void Player::setDir(MoveState in) {
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

void Player::unsetDir(MoveState in){
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