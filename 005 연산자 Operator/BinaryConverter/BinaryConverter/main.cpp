/*
10���� -> printf ("%d");
8���� -> %o
16���� -> %x
2���� -> �츮�� ������ �����

2������ �Է� : __ __ __ __ 4bit
(*8 *4 *2 *1 sum = ?)
10������ ��ȯ�Ͽ� ��� = __

10������ �Է� : __ (15���� ����)
2������ ��ȯ = __
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
	printf("�ʿ��Ͻ� �۾��� �����ϼ���.\n");
	printf("1. 2������ 10������ ��ȯ \n");
	printf("2. 10�������� 2������ ��ȯ\n");
	printf("3. 2���� ����\n");
	printf("4. 2���� ����\n");
	printf("5. 2���� ����\n");
	printf("6. 2���� ������\n");
	printf("�Է� : ");
	scanf("%d", &nIndexChoice);
	printf("\n");

	// Now we got the choice for working.
	// If we can use condition statement, the process would be easy.
	// However, for education purpose, 
	// We will using ? operator which we learned from last lecture.

	nIndexChoice == 1 ? // if nIndexChoice is 1, we have to do converting binary to decimal
		printf("2���� ���ڸ��� �Է��ϼ���.") :
		nIndexChoice == 2 ?
		printf("10������ �Է��ϼ��� (0~15)") :
		nIndexChoice == 3 ?
		printf("_ _ _ _ + _ _ _ _ (2����)") :
		nIndexChoice == 4 ?
		printf("_ _ _ _ - _ _ _ _ (2����)") :
		nIndexChoice == 5 ?
		printf("_ _ _ _ * _ _ _ _ (2����)") :
		nIndexChoice == 6 ?
		printf("_ _ _ _ / _ _ _ _ (2����)") :
		printf("Error : �޴��� ���� ��ȣ�Դϴ�.");

	
	// scan binary number from input

	// change it to decimal number

	// print out result


}
