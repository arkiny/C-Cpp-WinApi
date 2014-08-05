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
		cout << "����ȸ���� - ���赵 ����" << endl;
		t_level--;
		return t_level == 0;
	}
private:
};