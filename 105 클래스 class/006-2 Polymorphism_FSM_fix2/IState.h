#pragma once

#include <functional>
using std::function;

enum stateType{ Idling, Running, Sleeping, State_MAX };

/*
	
*/
class IState{
public:
	IState() {};
	virtual ~IState(){};
	virtual int goNext(function<void(int)> callback, int &el, int &tl) = 0;
};