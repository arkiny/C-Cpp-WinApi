#pragma once

#include "Idle.h"
#include "RunAway.h"
#include "Resting.h"

/*
	State Class
*/
class State : public Idle, public RunAway, public Resting
{
public:
	State();
	~State();

	void show();
	void setState(int type);
	int goNext(function<void(int)> callback, int &el, int &tl);

private:
	int currentState;
};
