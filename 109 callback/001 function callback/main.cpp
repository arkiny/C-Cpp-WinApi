/*
	function pointer
	- callback function
	- 함수 안에 함수를 넣어보기
*/
#include <iostream>

using std::cout;
using std::endl;

int show1(int);
int show2(int);
void callbacktest(int in, int*(*pfunc)(int));

void main(){
	// how we use pointer normally
	int* ptr = nullptr;

	// 함수형 포인터, function pointer
	int (*pfunc)(int);

	//show1(10);
	pfunc = show1;
	pfunc(10);
	
	//show2(20);
	pfunc = show2;
	pfunc(20);
}

int show1(int in){
	// function show 1 = a;
	cout << "function show1 = " << in << endl;
	return in;
}

int show2(int in){
	cout << "function show2 = " << in << endl;
	return in;
}
