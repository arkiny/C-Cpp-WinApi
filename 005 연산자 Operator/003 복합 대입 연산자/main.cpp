/*
	���� ���� ������
	+= -= *= /= %=
*/

#include <stdio.h>

void main(){
	int num1 = 3;
	num1 += 2;					 // num1 = num1 + 2;
	printf("num1 = %d\n", num1);

	num1 -= -1 + num1;	// �켱���� : (num1 - (-1 + num1))
										// ������ �켱
	printf("num1 = %d\n", num1);

	num1 *= 3 * (num1 + 2);
	// ((1 + 2)*3)*1 = 9
	printf("num1 = %d\n", num1);

	num1 %= 13 - num1;
	// (13 - 9) % 9 = 1??? �������
	printf("num1 = %d\n", num1);
}