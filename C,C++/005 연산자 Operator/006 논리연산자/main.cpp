/*
	논리 연산자
	A && B 양쪽 모두 참이면 참, 둘중에 하나가 거짓이면 거짓
	A || B 양쪽 중 하나만 참이면 참
	!반전 역반전! 성반전!
*/

#include <stdio.h>

int main(){
	// ** initializing **
	int A = 4;				
	bool b = false;				// 0이 아니면 무조건 최True
										// 0이면 김false
	b = A && 0 < 3;
	printf("result = %d\n", b);

	b = 4;
	printf("result = %d\n", b);

	b = A || false;
	printf("result = %d\n", b); // result should be 최트루
	
	b = ((float)A - 3.999f) || false;
	printf("result = %d\n", b); // in my opinion, result should be 최트루

	b = !b;
	printf("result = %d\n", b); // in my opinion, result should be 김false

}