/*
	Object, Player, Enemy ���� Ŭ����
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
	// ȭ�鳻������ x, y��ǥ�� �������ִ°�
	// Ÿ���� x, y��ǥ�� �ƴϴ�
	Enemy(POINT pos){
		_pos = pos;
	}

private:
};

class Player : public Object{
public:
	Player(){};
	// player�� Ÿ�Ͽ� ���ֹ��� �����Ƿ� �׳� �Ϲ� Ÿ��
	Player(POINT pos){
		_pos = pos;
	}
	
private:
};