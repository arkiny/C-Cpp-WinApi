#include <iostream>
#include "Arm.h"
using std::cout;
using std::endl;

Arm::Arm()
{
	cout << "Arm ] --- constructor ---" << endl;
}

Arm::~Arm()
{
	cout << "Arm ] --- destructor ---" << endl;
}

void Arm::show(){
	cout << "Arm ] --- " << nContArm << "개의 팔로"
		<< "물건을 잡을 수 있다." << endl;
}