#pragma once

#include "IState.h"

/*
Orc...?
*/
class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	// fucking... I wanted to use call back function but failed by circular link
	void goNext();


private:
	IState *current;	
};

