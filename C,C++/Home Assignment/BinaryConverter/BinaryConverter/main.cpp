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

#include <stdio.h>

int main(){
	
	// check what kind of calculation
	// 1. Binary to Decimal
	// 2. Decimal To Binary
	// 3. Binary Calculations (Add, Sub, Multi, Div) 
	//		- I will use binary masking if I can use

	// is logical operator ? support lambda function?

	// variable initialization part
	int nIndexChoice = -1; 
	

	// First, Program index
	printf("필요하신 작업을 선택하세요.\n");
	printf("1. 2진수에 10진수로 변환 \n");
	printf("2. 10진수에서 2진수로 변환\n");
	printf("3. 2진수 덧셈\n");
	printf("4. 2진수 뺄셈\n");
	printf("5. 2진수 곱셈\n");
	printf("6. 2진수 나눗셈\n");
	printf("입력 : ");
	scanf("%d", &nIndexChoice);
	printf("\n");

	// Now we got the choice for working.
	// If we can use condition statement, the process would be easy.
	// However, for education purpose, 
	// We will using ? operator which we learned from last lecture.

	nIndexChoice == 1 ? // if nIndexChoice is 1, we have to do converting binary to decimal
		printf("2진수 네자리를 입력하세요.") :
		nIndexChoice == 2 ?
		printf("10진수를 입력하세요 (0~15)") :
		nIndexChoice == 3 ?
		printf("_ _ _ _ + _ _ _ _ (2진수)") :
		nIndexChoice == 4 ?
		printf("_ _ _ _ - _ _ _ _ (2진수)") :
		nIndexChoice == 5 ?
		printf("_ _ _ _ * _ _ _ _ (2진수)") :
		nIndexChoice == 6 ?
		printf("_ _ _ _ / _ _ _ _ (2진수)") :
		printf("Error : 메뉴에 없는 번호입니다.");

	
	// scan binary number from input

	// change it to decimal number

	// print out result


}
