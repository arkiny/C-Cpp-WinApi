#pragma once
#include "IGameObj.h"
/*
팔의 역할
- 물건을 집거나, 잡을 수 있는 역할 부여
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

