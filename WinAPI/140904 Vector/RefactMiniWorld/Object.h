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
	Player();

	Player(POINT pos, int size);

	void update(float delta);
	void render(HDC &hdc);

	BOOL checkBound(RECT &_map);
	
	// setter
	void setDegree(int inputDegree);
	void setPos(int x, int y);
	void setDir(MoveState in);
	void unsetDir(MoveState in);

	//MoveState getLastdir(){ return _lastdr; }
	int getSize(){ return _size; }
	KeyControl getKC(){ return _kc; }
	int getDegree() { return _degree; }

private:
	float degreeToRadian(){
		return _degree * (PI / 180);
	}
	//POINT _pos;
	const float _barrelSize = 25.0f;
	const float _speed = 10.0f;
	int _size;
	int _degree = 30;
	KeyControl _kc;
	//MoveState _lastdr;
};

class Bullet : public CObject{
public:
	Bullet();
	Bullet(int x, int y, int degree);
	~Bullet();

	void update(float delta);
	void render(HDC &hdc);
	BOOL checkBound(RECT &_map);
	int getSize();

private:
	//POINT _pos;
	float degreeToRadian(){
		return _degree * (PI / 180);
	}
	const int _size = 3;
	const int _bulletSpeed = 15;
	int _degree;
};

class Enemy : public CObject{
public:
	Enemy();
	Enemy(RECT& in);
	void update(float delta);
	void render(HDC &hdc);
	BOOL isHittedbyBullet(Bullet &bullet);
	void getHitted();
	BOOL isDead();

private:
	int _hp;
	RECT _reg;
};