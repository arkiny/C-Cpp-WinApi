#pragma once

#include "Idle.h"
#include "IBattle.h"
#include "Sleep.h"


enum statetype { Idling, inBattle, Sleeping, stateMAX };
/*
	이거 어디다가 쓰지....
*/
class State : public Idle, public IBattle, public Sleep
{
public:
	State();
	~State();

	bool doEvent(){	
		return true;
	}

	IState* goNext(IState* in){
		switch (currentType)
		{
		case Idling:
			in = dynamic_cast<Idle*>(in);
			currentType = Idling;
			break;
		case inBattle:
			in = dynamic_cast<IBattle*>(in);
			currentType = inBattle;
			break;
		case Sleeping:
			in = dynamic_cast<Sleep*>(in);
			currentType = Sleeping;
			break;
		default:
			break;
		}
	}

	void setTLevel(int in);
	void setELevel(int in);

private:
	statetype currentType;
};

