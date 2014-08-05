#pragma once

#include <iostream>
#include "IState.h"

using std::cout;
using std::endl;
/*
*/
class Idle : virtual public IState
{
public:
	Idle();
	virtual ~Idle();

	virtual bool doEvent(){
		cout << "´ë±âÁß" << endl;
		return e_level + t_level > 0;
	}

private:
};
