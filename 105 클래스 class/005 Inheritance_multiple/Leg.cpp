#include <iostream>
#include "Leg.h"
using std::cout;
using std::endl;

Leg::Leg()
{
	cout << "Leg ] --- constructor ---" << endl;
}

Leg::~Leg()
{
	cout << "Leg ] --- destructor ---" << endl;
}
void Leg::show(){
	cout << "Leg ] --- " << nCntLeg << "���� �ӵ���"
		<< "�޸��� �ִ�." << endl;
}