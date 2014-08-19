#pragma once

#include "IState.h"

/*
	RunAway State
*/
class RunAway : virtual public IState
{
public:
	RunAway();
	virtual ~RunAway();

public:
	virtual int goNext(function<void(int)> callback, int &el, int &tl);

private:
};

