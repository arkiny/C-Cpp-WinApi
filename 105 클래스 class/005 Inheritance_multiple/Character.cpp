#include <iostream>
#include "State.h"

using std::cout;
using std::endl;

State::State()
{	
	name = "";
}

State::~State()
{	
}

void State::setName(string input_str){
	name = input_str; 
}

string State::getName()	{
	return name; 
}

int State::getPowerLevel(){
	return this->getPhysical() + this->getLeadership() + this->getIQ();
}

void State::show(){
	cout << "---------------------------------" << endl;
	cout << "��� �̸�: " << name << endl;
	Physical::show();
	Leadership::show();
	Intelligence::show();
	cout << "�ɷ�ġ ����: " << this->getPowerLevel() << endl;
}