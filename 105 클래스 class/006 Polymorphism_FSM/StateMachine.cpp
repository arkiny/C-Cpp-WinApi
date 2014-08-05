#include "StateMachine.h"

StateMachine::StateMachine(){
	current = new State;
	current = dynamic_cast<Idle*>(current);//일단 idle로 시작
}

StateMachine::~StateMachine(){
	delete current;
}

void StateMachine::goNext(){
	switch (currentType)
	{
	case Idling:
		current = dynamic_cast<IBattle*>(current);
		currentType = inBattle;
		break;
	case inBattle:
		current = dynamic_cast<Sleep*>(current);
		currentType = Sleeping;
		break;
	case Sleeping:
		current = dynamic_cast<Idle*>(current);
		currentType = Idling;
	default:
		break;
	}
}

void StateMachine::setState(statetype in){
	
}