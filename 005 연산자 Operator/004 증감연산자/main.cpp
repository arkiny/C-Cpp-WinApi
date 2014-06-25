/*
	증감 연산자
	- 단항 연산자
	
	++ --
*/

#include <stdio.h>

void main(){

	int num1 = 0;

	// 1증가
	num1++;							// 후위연산자(낮은 우선순위)
	//num1 += 1;
	//num1 = num1 + 1;

	++num1;	// 전위연산자(높은 우선순위)
	// 서로 우선순위가 달라서 생기는 일

	// num1을 출력 이후에 연산, 후위연산자
	printf("num1 = %d\n", num1++); //2
	printf("num1 = %d\n", num1);		//3

	// num1을 출력 이전에 연산, 전위연산자
	printf("num1 = %d\n", ++num1); //4
	printf("num1 = %d\n", num1);		//4
	// 1감소
	num1--;

	//num1++++은 불가하지만
	// ----num1은 가능
	--num1;
	
}