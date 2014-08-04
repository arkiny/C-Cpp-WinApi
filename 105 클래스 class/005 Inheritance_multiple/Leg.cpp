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
	cout << "Leg ] --- " << nCntLeg << "개의 속도로"
		<< "달릴수 있다." << endl;
}