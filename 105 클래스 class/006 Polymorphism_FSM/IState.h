#pragma once

/*
Interface of the State
*/
class IState{

public:
	IState();
	virtual ~IState();

	virtual bool doEvent(); 
	virtual void goNext();
	
protected:
	int t_level; // threaten level;
	int e_level; // exhaust level;
};