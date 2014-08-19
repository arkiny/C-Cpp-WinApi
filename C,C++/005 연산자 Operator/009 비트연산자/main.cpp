/*
	비트연산자
	& | >> <<

	- 비트 단위 연산자
	- 2진수 (Binary) 연산자
	*/

#include <stdio.h>

void main(){
	int A = 1;									// 0001
	int B = 2;									// 0010

	int C = 0;									// 0000

	C = A & B;									// 0000 -> should be zero
	printf("c = %d\n", C);

	C = A | B;									// 0011 -> 3
	printf("c = %d\n", C);

	C = A << 2;								// shift operator : 자리수를 밀어 준다 0100
	C = A * 8;
	printf("c = %d\n", C);					// Var << (num of shift)

	C = C >> 2;								//  0001
	C = C / 2;
	printf("c = %d\n", C);
}


/*
 10진수 -> printf ("%d");
 8진수 -> %o
 16진수 -> %x
 2진수 -> 우리가 과제로 만들기

 2진수를 입력 : __ __ __ __ 4bit
 (*8 *4 *2 *1 sum = ?)
 10진수로 변환하여 출력 = __

 10진수를 입력 : __ (15까지 가능)
 2진수로 변환 = __
 */

