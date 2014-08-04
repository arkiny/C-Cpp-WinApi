#include <iostream>
#include "Leadership.h"
using std::cout;
using std::endl;

Leadership::Leadership()
{
	nLeadership = 0;
}

Leadership::~Leadership()
{
}

void Leadership::setLeadership(int n_input){
	nLeadership = n_input;
}

int Leadership::getLeadership(){
	return nLeadership;
}

void Leadership::show(){
	cout << "Åë¼Ö·Â ] --- " << nLeadership << endl;
}