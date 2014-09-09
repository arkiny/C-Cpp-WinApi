#include "Object.h"

Bullet::Bullet(VECTOR2D from, VECTOR2D direction){
	_size = 3;
	_barreldir = direction;
	_barreldir.Normalize();
	_pos = from + (_barreldir * 20);
}

void Bullet::update(float delta){
	VECTOR2D vMover;
	_barreldir.Normalize();
	vMover = _barreldir * (_bulletSpeed * delta);
	_pos = _pos + (vMover);
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