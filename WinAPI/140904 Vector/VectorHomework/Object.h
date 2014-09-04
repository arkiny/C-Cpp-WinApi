#pragma once

#include <math.h>

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