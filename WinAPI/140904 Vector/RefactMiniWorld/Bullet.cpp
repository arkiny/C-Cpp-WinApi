#include "Object.h"

Bullet::Bullet(){}
Bullet::Bullet(int x, int y, int degree){
	_degree = degree;
	float fx = cosf(degreeToRadian())*25.0f + x;
	float fy = sinf(degreeToRadian())*25.0f + y;
	_pos = { fx, fy };
}
Bullet::~Bullet(){}

void Bullet::update(float delta){
	float rad = degreeToRadian();


	_pos = {
		cosf(rad) * _bulletSpeed + _pos.x,
		sinf(rad) * _bulletSpeed + _pos.y
	};
}

void Bullet::render(HDC &hdc){
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

BOOL Bullet::checkBound(RECT &_map){
	BOOL ret = (_pos.x - _size <= _map.left ||
		_pos.x + _size >= _map.right ||
		_pos.y - _size <= _map.top ||
		_pos.y + _size >= _map.bottom);
	return ret;
}

int Bullet::getSize() { return _size; }