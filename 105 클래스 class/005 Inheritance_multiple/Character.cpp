
#include <iostream>
#include "Character.h"

using std::cout;
using std::endl;

character::character()
{
	cout << "character ] --- constructor ---" << endl;
}

character::~character()
{
	cout << "character ] --- destructor ---" << endl;
}

void character::show(){
	cout << "�� �̸��� " << name << endl;
	Arm::show();
	Leg::show();
}