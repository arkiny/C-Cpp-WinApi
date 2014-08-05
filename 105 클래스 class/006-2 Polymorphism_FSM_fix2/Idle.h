#pragma once

#include "IState.h"

/*
	Idle State
*/
class Idle : virtual public IState
{
public:
	Idle();
	virtual ~Idle();

public:
	virtual int goNext(function<void(int)> callback, int &el, int &tl);

private:
};