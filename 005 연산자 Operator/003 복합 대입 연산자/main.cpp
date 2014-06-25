/*
	복합 대입 연산자
	+= -= *= /= %=
*/

#include <stdio.h>

void main(){
	int num1 = 3;
	num1 += 2;					 // num1 = num1 + 2;
	printf("num1 = %d\n", num1);

	num1 -= -1 + num1;	// 우선순위 : (num1 - (-1 + num1))
										// 오른쪽 우선
	printf("num1 = %d\n", num1);

	num1 *= 3 * (num1 + 2);
	// ((1 + 2)*3)*1 = 9
	printf("num1 = %d\n", num1);

	num1 %= 13 - num1;
	// (13 - 9) % 9 = 1??? 복습요망
	printf("num1 = %d\n", num1);
}