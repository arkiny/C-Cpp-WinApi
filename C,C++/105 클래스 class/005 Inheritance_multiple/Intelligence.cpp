#include <iostream>
#include "Intelligence.h"
using std::cout;
using std::endl;

Intelligence::Intelligence(){
	nIQ = 0;
}
Intelligence::Intelligence(int n_input){
	nIQ = n_input;
}
Intelligence::~Intelligence(){	
}

void Intelligence::show(){
	cout << "ม๖ทย   ] --- " << nIQ << endl;
}
void Intelligence::setIQ(int n_input){
	nIQ = n_input;
}
int Intelligence::getIQ(){
	return nIQ;
}