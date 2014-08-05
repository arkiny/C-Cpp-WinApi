#include "State.h"

State::State()
{
	currentState = Idling;
}

State::~State()
{
}

int State::goNext(function<void(int)> callback, int &el, int &tl)
{
	switch (currentState)
	{
	case Idling:
		currentState = Idle::goNext(callback, el, tl);
		break;
	case Running:
		currentState = RunAway::goNext(callback, el, tl);
		break;
	case Sleeping:
		currentState = Resting::goNext(callback, el, tl);
		break;
	default:
		break;
	}
	return currentState;
}

void State::setState(int type){
	currentState = type;
}