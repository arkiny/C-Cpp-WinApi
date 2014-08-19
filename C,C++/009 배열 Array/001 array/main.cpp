/*
	배열 Array
	1. 같은 데이터 타입.
	2. 연속된 주소
*/

#include <stdio.h>

void main(){
	int a = 1, b = 2, c = 3;
	printf("a 주소 : %p\n", &a); // 주소를 볼때는 %p 
	printf("b 주소 : %p\n", &b);
	printf("c 주소 : %p\n", &c);

	printf("-------------------\n");

	// 배열 최초 선언 [ 배열의 개수 ]	
	int Arr[3];

	// 배열 사용 [ 시작 번호 ] 시작 <- 0 1 2
	printf("Arr[0] 주소 : %p\n", &Arr[0]);
	printf("Arr[1] 주소 : %p\n", &Arr[1]);
	printf("Arr[2] 주소 : %p\n", &Arr[2]);

}