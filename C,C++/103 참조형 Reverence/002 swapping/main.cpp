/*
	swaps
	���� ���� ��ȯ�õ�
	A <-> ���� ��ȯ
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

	// A <-> B ��ȯ
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
	// �޸� ���� ������ �ƹ����� �Ұ����ϴ�...
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