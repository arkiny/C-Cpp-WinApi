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
	cout << "Arm ] --- " << nContArm << "���� �ȷ�"
		<< "������ ���� �� �ִ�." << endl;
}