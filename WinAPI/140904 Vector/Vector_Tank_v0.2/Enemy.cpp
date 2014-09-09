#include "Object.h"

Enemy::Enemy(float x, float y, VECTOR2D& target){
	_pos = VECTOR2D(x, y);
	_from = _pos;
	_target = target;
	_size = 15;
}

void Enemy::update(float delta){
	VECTOR2D dir = _target - _from;
	dir.Normalize();
	VECTOR2D final = dir * (_speed*delta);
	_pos = _from + final;
}

void Enemy::render(HDC &hdc){
	::Rectangle(hdc,
		_pos.x - _size,
		_pos.y - _size,
		_pos.x + _size,
		_pos.y + _size);

	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

	::Rectangle(hdc, _pos.x - _size, _pos.y + 10, _pos.x + _size, _pos.y + _size);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	if (_hp >= 1){
		::Rectangle(hdc, _pos.x - _size, _pos.y+10,
			_pos.x - _size + (((_pos.x + _size) - (_pos.x - _size)) / 3)* _hp,
			_pos.y + _size);
	} 
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void Enemy::updateTarget(VECTOR2D& target){
	_from = _pos;
	_target = target;
}



BOOL Enemy::isHittedbyBullet(Bullet &bullet){
	int hcollidingRange = bullet.getSize() + _size;
	int vcollidingRange = bullet.getSize() + _size;
	int hRange = abs(_pos.x - bullet.getPos().x);
	int vRange = abs(_pos.y - bullet.getPos().y);
	return	(hRange <= hcollidingRange) && (vRange <= vcollidingRange);
}