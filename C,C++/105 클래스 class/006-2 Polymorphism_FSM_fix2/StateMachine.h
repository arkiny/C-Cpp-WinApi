#pragma once

#include "State.h"

/*
	StateMachine
	실질적으로 렌더와 State 행동을 컨트롤 한다.
	setState같은 경우 일단 callback용으로 사용한다.

	실질적으로 컨트롤에 필요한 데이타들을 저장한다.
	(위험도, 피로도) 
		-> 이러한 변수들을 원래 각 하위 클래스에서 관리해줘야 하는데...
		-> Idle에서 수평이동하여 RunAway나 Resting에서
		   변수를 어떻게 뽑을지 한참 해메다가 일단 포기
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

