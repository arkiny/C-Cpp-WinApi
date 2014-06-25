/*
	산술 연산자
	+ plus, addition
	- minus, subtraction
	* multiply
	/ division
	% modular
*/

#include <stdio.h>

void main()
{
	int k1 = 15;
	int k2 = 7;
	// +
	printf("+ = %d\n", k1 + k2);
	// -
	printf("- = %d\n", k1 - k2);
	// *
	printf("* = %d\n", k1 * k2);
	// /
	printf("/ = %d\n", k1 / k2);
	// %
	printf("%% = %d\n", k1 % k2);

	// what can we do using modular operator?
	// 모듈러 연산을 통해 무엇을 할수 있을까?
	printf("\n 모듈러 연산을 통해 무엇을 할수 있을까? \n");
	printf(" 3 %% 1 = %d\n", 3 % 1);
	printf(" 3 %% 2 = %d\n", 3 % 2);
	printf(" 3 %% 3 = %d\n", 3 % 3);
	printf(" 3 %% 4 = %d\n", 3 % 4);

	printf(" 10 %% 6 = %d\n", 10 % 6);
	printf(" 11 %% 6 = %d\n", 11 % 6);
	printf(" 12 %% 6 = %d\n", 12 % 6);
	printf(" 13 %% 6 = %d\n", 13 % 6);
	
	// 진법 표현시, 난수처리(ex 주사위), 
	// 후에 이것으로 주사위 효과를 만들 예정 (확률, 조작확률)
	printf(" 10 %% 12 = %d\n", 10 % 12);
	printf(" 11 %% 12 = %d\n", 11 % 12);
	printf(" 12 %% 12 = %d\n", 12 % 12);
	printf(" 13 %% 12 = %d\n", 13 % 12);
}
