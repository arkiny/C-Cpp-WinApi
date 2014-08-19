#pragma once

#include "IState.h"

/*
	Resting State
*/
class Resting : virtual public IState
{
public:
	Resting();
	virtual ~Resting();

public:
	virtual int goNext(function<void(int)> callback, int &el, int &tl);

private:
};

