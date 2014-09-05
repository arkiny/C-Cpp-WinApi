#pragma once

#include <Windows.h>
#include <cmath>
#define PI 3.14159265359

enum MoveState { NOMOVE, LEFT, RIGHT, UP, DOWN, SPACE };

struct KeyControl{
	BOOL left;
	BOOL right;
	BOOL up;
	BOOL down;
	BOOL space;
};

// 직선의 방정식으로 그린 터렛
class Turret{
public:
	Turret();
	Turret(POINT pos, int size);

	void update(float delta);
	void render(HDC& hdc);

	int getSize(){ return _size; }
	KeyControl getKC(){ return _kc; }
	int getDegree() { return _degree; }

	void setDegree(int inputDegree);
	void setPos(int x, int y);
	void setDir(MoveState in);
	void unsetDir(MoveState in);

	POINT getPos() { return _pos; }
	void setPos(POINT& in){
		_pos = in;
	}

private:
	float _x;
	float _y;

	float degreeToRadian(){
		return _degree * (float)(PI / 180);
	}
	//POINT _pos;
	const float _barrelSize = 50.0f;
	const float _speed = 10.0f;
	int _size;
	int _degree = 30;
	KeyControl _kc;
	POINT _pos;
};

// 벡터로 이동하는 플레이어
class Vector2D{
public:
	Vector2D(){
		_x = 0;
		_y = 0;
	}

	Vector2D(float x, float y){
		_x = x;
		_y = y;	
	}

	void Normalize(){
		float vLen = sqrtf(_x*_x + _y*_y);
		_x = _x / vLen;
		_y = _y / vLen;
	}

	Vector2D operator+(const Vector2D& vec) const{
		return Vector2D(_x + vec.getX(), _y + vec.getY());
	}
	Vector2D operator-(const Vector2D& vec) const{
		return Vector2D(_x - vec.getX(), _y - vec.getY());
	}
	Vector2D operator*(float val) const{
		return Vector2D(_x *val, _y*val);
	}

	bool operator==(const Vector2D& vec) const{
		return _x == vec.getX() && _y == vec.getY();
	}

	// getter
	float getX() const { return _x; }
	float getY() const { return _y; }

	// setter
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

private:	
	float _x;
	float _y;
};

