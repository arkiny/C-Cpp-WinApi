/*
	관계 연산자
	> < >= <=
	A == B 양쪽 값이 같으면 참, 아니면 거짓 (equal, true, else false_
	A != B 양쪽 값이 다르면 참, 다르면 거짓 (difference)
*/

#include <stdio.h>

int main()
{
	int A = 0;

	//  datatype bool, 1byte
	// true	= 1;
	// false	= 0;
	bool b = false;															// true(1) or false(0);
	b = A < 3;
	printf("result = %d\n", b);

	// 관계 연산자가 후위 연산자보다 우선순의를 가지므로 false
	b = 0 > A--;	
	printf("result = %d\n", b);

	// 계산 후에 비교하므로 false
	b = (3 == A + 3);
	printf("result = %d\n", b);
}