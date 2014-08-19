#include <iostream>
#include "Physical.h"
using std::cout;
using std::endl;

Physical::Physical()
{
	nContPhysical = 0;	
}

Physical::Physical(int input){
	nContPhysical = input;
}

Physical::~Physical()
{	
}

void Physical::setPhysical(int n_input){ 
	nContPhysical = n_input; 
}

int Physical::getPhysical(){ 
	return nContPhysical; 
}

void Physical::show(){
	cout << "¹«·Â   ] --- " << nContPhysical  << endl;
}