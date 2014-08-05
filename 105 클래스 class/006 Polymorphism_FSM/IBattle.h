#pragma once

#include <iostream>
#include "IState.h"

using std::cout;
using std::endl;

/*
*/
class IBattle : virtual public IState
{
public:
	IBattle();
	virtual ~IBattle();
	virtual bool doEvent(){
		cout << "전투회피중 - 위험도 감소" << endl;
		t_level--;
		return t_level == 0;
	}
private:
};