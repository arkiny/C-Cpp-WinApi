/*
	�迭 Array
	1. ���� ������ Ÿ��.
	2. ���ӵ� �ּ�
*/

#include <stdio.h>

void main(){
	int a = 1, b = 2, c = 3;
	printf("a �ּ� : %p\n", &a); // �ּҸ� ������ %p 
	printf("b �ּ� : %p\n", &b);
	printf("c �ּ� : %p\n", &c);

	printf("-------------------\n");

	// �迭 ���� ���� [ �迭�� ���� ]	
	int Arr[3];

	// �迭 ��� [ ���� ��ȣ ] ���� <- 0 1 2
	printf("Arr[0] �ּ� : %p\n", &Arr[0]);
	printf("Arr[1] �ּ� : %p\n", &Arr[1]);
	printf("Arr[2] �ּ� : %p\n", &Arr[2]);

}