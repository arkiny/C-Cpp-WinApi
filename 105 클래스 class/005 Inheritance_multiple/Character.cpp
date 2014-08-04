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
	cout << "��� �̸�: " << name << endl;
	Physical::show();
	Leadership::show();
	Intelligence::show();
	cout << "�ɷ�ġ ����: " << this->getPowerLevel() << endl;
}