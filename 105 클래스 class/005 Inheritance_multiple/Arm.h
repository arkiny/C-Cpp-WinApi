#pragma once
#include "IGameObj.h"
/*
���� ����
- ������ ���ų�, ���� �� �ִ� ���� �ο�
- ???
*/

class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	void show();
	void setArm(int n_input) { nContArm = n_input; }
	int getArm(){ return nContArm; }

private:
	int nContArm;			// number of the Arms
};

