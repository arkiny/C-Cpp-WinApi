/*
	Object, Player, Enemy 관리 클래스
*/

#pragma once
#include <Windows.h>

class Object{
public:
	virtual ~Object() {};
	virtual void update(float delta) = 0;
	POINT getPos() { return _pos; }
protected:
	POINT _pos;
};

class Enemy : public Object{
public:
	Enemy(){};
	// 화면내에서의 x, y좌표를 설정해주는것
	// 타일의 x, y좌표가 아니다
	Enemy(POINT pos){
		_pos = pos;
	}

private:
};

class Player : public Object{
public:
	Player(){};
	// player는 타일에 구애받지 않으므로 그냥 일반 타일
	Player(POINT pos){
		_pos = pos;
	}
	
private:
};