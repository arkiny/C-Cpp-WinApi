/*
	printf
	- printout variables, and constant to console
	- ������ �����.. ȭ��� ���

	scanf
	- deliver value from keyboard to variables
	- Ű����� �Է� ���� ���� ������ ����
	- ���� : "%d "  " " ������ �ڴ� �ݵ�� �ٿ��� �̿�
	*/

#include <stdio.h>

int main(){
	// initialize nA
	int nA = 5;
	printf("nA = %d\n", nA);

	nA = 11; // nA's value changed as 11
	printf("nA = %d\n", nA);


	// 1. ���� nA�� �Է��� ���ڸ� ����
	// scanf("formant", address)
	// Don't forget the ampersand
	// Care about the format. (���� ����!)
	/*scanf("%d", &nA);
	printf("nA = %d\n", nA);
	*/

	// 2. �ѹ��� �ΰ��� ������ �Է�
	// put two input data at once
	//int nB = 0;
	//// �տ� �ٴ� �Ͱ� �߰��� �ٴ� ���� ���������, �������� �����̽��� �Ѱ��
	//// ���� �� �Է��� ��ٸ���.
	//scanf("%d %d", &nA, &nB);
	//printf("nA = %d, nb = %d\n", nA, nB);

	// 3. �Ǽ� �Է�
	/*float fC = 0.0f;
	printf("input float : \n", fC);
	scanf("%f", &fC);
	printf("fC = %.2f\n", fC);*/

	// 4. ���� �ϳ� �Է�
	char chD = 0;
	printf("input character : \n");
	scanf("%c", &chD);
	printf("�Է��� ���� = %c\n", chD);
	printf("Asciicode = %x\n", chD);
}
