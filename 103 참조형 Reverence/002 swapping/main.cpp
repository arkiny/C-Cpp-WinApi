/*
	swaps
	값에 대한 교환시도
	A <-> 서로 교환
*/
#include <iostream>

using std::cout;
using std::endl;

void swapV(int A, int B);
void swapP(int *A, int *B);
void swapR(int &A, int &B);

void main()
{
	int A = 100;
	int B = 33;

	// A <-> B 교환
	int temp = A;
	A = B;
	B = temp;

	cout << A << " " << B << endl;

	swapV(A, B);
	cout << "swapV = " << A << " " << B << endl;

	swapP(&A, &B);
	cout << "swapP = " << A << " " << B << endl;

	swapR(A, B);
	cout << "swapR = " << A << " " << B << endl;
}


void swapV(int A, int B){
	// 메모리 직접 간섭이 아무래도 불가능하다...
}

void swapP(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

void swapR(int &A, int &B){
	A = A + B;
	B = A - B;
	A = A - B;	
}