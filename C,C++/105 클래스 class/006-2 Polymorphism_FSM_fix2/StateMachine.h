#pragma once

#include "State.h"

/*
	StateMachine
	���������� ������ State �ൿ�� ��Ʈ�� �Ѵ�.
	setState���� ��� �ϴ� callback������ ����Ѵ�.

	���������� ��Ʈ�ѿ� �ʿ��� ����Ÿ���� �����Ѵ�.
	(���赵, �Ƿε�) 
		-> �̷��� �������� ���� �� ���� Ŭ�������� ��������� �ϴµ�...
		-> Idle���� �����̵��Ͽ� RunAway�� Resting����
		   ������ ��� ������ ���� �ظ޴ٰ� �ϴ� ����
*/
class StateMachine
{
public:
	StateMachine();
	StateMachine(State &in);
	~StateMachine();
	void step();
	void setState(int type);
	void incElevel(int in);
	void incTlevel(int in);

	void render();

private:
	void goNext(int &tl, int &el);
	State current;
	int elevel;
	int tlevel;
};

