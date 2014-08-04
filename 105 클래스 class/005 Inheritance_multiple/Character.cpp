#include <iostream>
#include "Character.h"

using std::cout;
using std::endl;

character::character()
{	
	name = "";
}

character::~character()
{	
}

void character::setName(string input_str){
	name = input_str; 
}

string character::getName()	{
	return name; 
}

int character::getPowerLevel(){
	return this->getPhysical() + this->getLeadership() + this->getIQ();
}

void character::show(){
	cout << "---------------------------------" << endl;
	cout << "장수 이름: " << name << endl;
	Physical::show();
	Leadership::show();
	Intelligence::show();
	cout << "능력치 총합: " << this->getPowerLevel() << endl;
}