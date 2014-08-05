#pragma once

#include <iostream>
#include "IState.h"

using std::cout;
using std::endl;

/*
*/
class Sleep : virtual public IState
{
public:
	Sleep();
	virtual ~Sleep();
	virtual bool doEvent(){
		cout << "수면중, 피로도 감소" << endl;
		e_level--;
		return e_level == 0;
	}

private:
};