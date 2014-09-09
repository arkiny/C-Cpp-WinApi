#pragma once

#include "Vector2D.h"

enum KeyInput{NOINPUT, UP, DOWN, LEFT, RIGHT, SPACE, LBUTTON};

// 차후 cMain (혹은 World)가 KeyControl 권한을 가지게 한다.
typedef struct KeyContrl{
	BOOL _up = false;
	BOOL _down = false;
	BOOL _left = false;
	BOOL _right = false;
	BOOL _space = false;
	BOOL _lbutton = false;
	int mouseX = 0;
	int mouseY = 0;
}KEYCONTROL, *LPKEYCONTROL;

struct KeyContrl;

const VECTOR2D vRight(1, 0);
const VECTOR2D vLeft(-1, 0);
const VECTOR2D vUp(0, -1);
const VECTOR2D vDown(0, 1);

typedef class Object
{
public:
	Object(){ _pos = VECTOR2D(); }
	virtual ~Object(){}

	VECTOR2D getPos(){
		return _pos;
	}

	void setVector(float x, float y){
		_pos.x = x;
		_pos.y = y;
	}

	virtual void render(HDC& hdc) = 0;
	virtual void update(float delta) = 0;

	int getSize(){ return _size; }
	void setSize(int x) { _size = x; }
protected:
	VECTOR2D _pos;
	int _size;
}OBJECT, *LPOBJECT;



class Bullet : public Object
{
public:
	Bullet(){}
	Bullet(VECTOR2D from, VECTOR2D direction);
	~Bullet(){}
	void render(HDC& hdc);
	void update(float delta);
private:
	VECTOR2D _from;
	VECTOR2D _barreldir;
	const int _bulletSpeed = 250;
};

// 좀비처럼 서서 플레이어에게 다가가면서
// 일정 거리내가 되면 침을 뱉는다?
class Enemy : public Object
{
public:
	Enemy(){}
	Enemy(float x, float y, VECTOR2D& target);
	void update(float delta);
	void render(HDC &hdc);

	void updateTarget(VECTOR2D& target);
	BOOL isHittedbyBullet(Bullet &bullet);
	void getHitted(){
		_hp--;
	}

	int getHP(){
		return _hp;
	}

private:
	int _hp = 3;
	VECTOR2D _from;
	VECTOR2D _target;
	const float _speed = 100;
};

// Ebase에서 적이 꾸준히 튀어나오고 Ebase를 다 부수고
// 좀비를 다 죽여야 게임 클리어는 차후 추가
class EBase : public Object
{
public:
	EBase(){}
	EBase(float x, float y){
		_pos.x = x;
		_pos.y = y;
		_size = 40;
	}

	void update(float delta){
		// 생각좀
	}

	void render(HDC &hdc){
		::Rectangle(hdc,
			_pos.x - _size,
			_pos.y - _size,
			_pos.x + _size,
			_pos.y + _size);
	}

private:
	int hp = 100;
};

typedef class Player : public Object
{
public:
	Player();
	Player(float x, float y);
	Player(float x, float y, KeyContrl *kc);
	~Player(){}
	void render(HDC& hdc);
	void update(float delta);

	VECTOR2D getDir(){ return _barreldir; }
	BOOL isHittedbyEnemy(Enemy &Enemy);

	void getHitted(){
		_hp--;
	}

	int getHP(){
		return _hp;
	}

	void setHP(int in){
		_hp = in;
	}

private:
	int _hp = 3;
	KeyContrl* _kc;
	void setDirection(int x, int y);
	void movePlayer(float delta);
	VECTOR2D _barreldir;
	const int _barrelLength = 30;
	const int _moveSpeed = 200;
}PLAYER, *LPPLAYER;