/*
	Pointer : �ּҸ� ����Ų��

	�ּ� ũ��� 32bit == 4byte

	pointer�� ũ��� ? 4byte
*/

#include <stdio.h>
#include <stdlib.h>

void sefFloat(float *pfnum, float input_f);

void main(){
	char ch = 's';
	char *pch = &ch;

	printf("ch�� �� = %c, �ּ� = %p\n", ch, &ch);
	printf("pch�� �� = %p\n", pch);
	printf("pch�� �ּ� = %p\n", &pch);

	printf("pch�� ���� ch�� �� = %c\n", *pch);
	
	*pch = 't';
	printf("ch�� �� = %c\n", ch);
	printf("pch�� ���� ch�� �� = %c\n", *pch);

	printf("ch�� ũ�� = %d\n", sizeof(ch));
	// �ּҰ��� ����Ǿ� �����Ƿ� 4����Ʈ�� ����
	printf("pch�� ũ�� = %d\n", sizeof(pch));  

	//
	float fnum = 3.14f;
	float *pfnum = &fnum;

	// pfnum�� 5.12f
	// fnum Ȯ��
	// �Լ��� �����

	*pfnum = 5.12f;
	printf("fnum�� �� : %f\n", fnum);

	sefFloat(pfnum, 9.18f);
	printf("fnum�� �� : %f\n", fnum);
	
}

void sefFloat(float *pfnum, float input_f){
	*pfnum = input_f;	
}