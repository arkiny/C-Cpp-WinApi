/*
	�Լ� function
	- main �Լ��� ���ߵ� �ڵ带 �л�.
	- �Լ��� ���� �ڵ带 ����.

	y = f	( x )
	int main(void)

	1. �Լ��� �ʿ伺 �˾ƾ�...
	2. �Լ��� ����..
	3. �Լ��� ����..
*/

#include <stdio.h>
// 3. declare add function
int add(int a, int b); // addition
int sub(int a, int b); // subtraction
int mul(int a, int b); // mulitiplication
int div(int a, int b); // division float�� �ؾ��ϴµ� ������
void show(int input);// printout;

void main(){ // ��Ȯ�� �ҹ��� main �� �־�� ������ ������
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