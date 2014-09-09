#include "Object.h"

Player::Player()
{
	//_kc = KEYCONTROL();
	_barreldir = VECTOR2D();
	_size = 15;
}

Player::Player(float x, float y){
	// 차후 동적할당
	_pos = VECTOR2D(x, y);
	_barreldir = vRight;
	_size = 15;
}

Player::Player(float x, float y, KeyContrl* kc){
	_pos = VECTOR2D(x, y);
	_barreldir = vRight;
	_kc = kc;  // 처리 편의성을 위해 일단 주소를 받아와서 컨트롤
	_size = 15;
}

void Player::update(float delta){
	Player::setDirection(_kc->mouseX, _kc->mouseY);
	Player::movePlayer(delta);
}

void Player::render(HDC& hdc){
	
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));;
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	::Rectangle(hdc, _pos.x - _size, _pos.y + _size, _pos.x + _size, _pos.y + _size + 10);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
	
	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	if (_hp >= 1){
		::Rectangle(hdc, _pos.x - _size, _pos.y+_size,
			_pos.x - _size + (((_pos.x + _size) - (_pos.x - _size)) / 3)* _hp,
			_pos.y + _size + 10);
	}
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	::Ellipse(hdc, _pos.x - _size, _pos.y - _size,
		_pos.x + _size, _pos.y + _size);

	_barreldir.Normalize();

	VECTOR2D muzzle = _pos + (_barreldir * _barrelLength);

	::MoveToEx(hdc, _pos.x, _pos.y, NULL);
	::LineTo(hdc, muzzle.x, muzzle.y);

}

// helper for update
void Player::setDirection(int x, int y){
	VECTOR2D mousePos(x, y);
	_barreldir = mousePos - _pos;
}

// 8방향 이동
void Player::movePlayer(float delta) {
	VECTOR2D vMover;
	VECTOR2D test;

	if (_kc->_right == true && _kc->_up == true){
		test = vRight + vUp;
		test.Normalize();
		vMover = test * (_moveSpeed * delta);
	}
	else if (_kc->_left == true && _kc->_up == true){
		test = vLeft + vUp;
		test.Normalize();
		vMover = test * (_moveSpeed * delta);
	}
	else if (_kc->_right == true && _kc->_down == true){
		test = vRight + vDown;
		test.Normalize();
		vMover = test * (_moveSpeed * delta);
	}
	else if (_kc->_left == true && _kc->_down == true){
		test = vLeft + vDown;
		test.Normalize();
		vMover = test * (_moveSpeed * delta);
	}
	else if (_kc->_right == true){
		vMover = vRight * (_moveSpeed * delta);
	}
	else if (_kc->_left == true){
		vMover = vLeft * (_moveSpeed * delta);
	}
	else if (_kc->_up == true){
		vMover = vUp * (_moveSpeed * delta);
	}
	else if (_kc->_down == true){
		vMover = vDown * (_moveSpeed * delta);
	}
	else {
		// 설마 일어나겠는가!
	}

	_pos = _pos + vMover;
}

BOOL Player::isHittedbyEnemy(Enemy &Enemy){
	// vector로 충돌 테스트 하는 방법 (Ellipse형 충돌)
	/*float minDist = _size + Enemy.getSize();
	VECTOR2D vDist = _pos - Enemy.getPos();
	float range = sqrtf(vDist.x * vDist.x + vDist.y * vDist.y);
	if (range <= minDist)	{ return true; }
	return false;*/	

	int hcollidingRange = Enemy.getSize() + _size;
	int vcollidingRange = Enemy.getSize() + _size;
	int hRange = abs(_pos.x - Enemy.getPos().x);
	int vRange = abs(_pos.y - Enemy.getPos().y);
	return	(hRange <= hcollidingRange) && (vRange <= vcollidingRange);
}