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
		cout << "������, �Ƿε� ����" << endl;
		e_level--;
		return e_level == 0;
	}

private:
};