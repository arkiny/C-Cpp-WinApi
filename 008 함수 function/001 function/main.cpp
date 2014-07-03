/*
	함수 function
	- main 함수에 집중된 코드를 분산.
	- 함수로 만든 코드를 재사용.

	y = f	( x )
	int main(void)

	1. 함수의 필요성 알아야...
	2. 함수를 정의..
	3. 함수를 선언..
*/

#include <stdio.h>
// 3. declare add function
int add(int a, int b); // addition
int sub(int a, int b); // subtraction
int mul(int a, int b); // mulitiplication
int div(int a, int b); // division float질 해야하는데 귀찮다
void show(int input);// printout;

void main(){ // 정확히 소문자 main 이 있어야 실행이 가능함
	int nA = 3, nB = 7;
	int nC = nA + nB;
	
	// 1. the function needs
	nC = add(nA, nB);
	//printf("nC = %d\n", nC);
	show(nC);
	nC = sub(nA, nB);
	show(nC);
	nC = mul(nA, nB);
	show(nC);
	nC = div(nA, nB);
	show(nC);
}


// 2.define add function 
int add(int a, int b){
	int c = a + b;
	return c;
	//return a + b;
	//cannot code anymore after the return
}

int sub(int a, int b){
	return a - b;
}

int mul(int a, int b){
	return a* b;
}

int div(int a, int b){
	return a / b;
}

void show(int input){
	printf("Result = %d\n", input);
}