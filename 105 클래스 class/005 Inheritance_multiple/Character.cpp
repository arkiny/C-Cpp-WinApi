
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
	cout << "내 이름은 " << name << endl;
	Arm::show();
	Leg::show();
}