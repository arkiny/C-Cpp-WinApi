/*
	Struct
		- �迭�� ������
			�迭: ���� ������ Ÿ���� ���
			����ü : �ٸ� ������ Ÿ�Ե� ��� ����.	
*/

#include <stdio.h>

// ����ü �̸�
struct profile{
	// ����鼭 �ʱ�ȭ 
	unsigned int nAge = 0;
	unsigned int nPhone = 0;
	float fWeight = 0.0f;
	// ...
};

void main(){
	// 1. ����ü ����� ���
	profile ljc;
	ljc.nAge = 23;
	ljc.nPhone = 557774740;
	ljc.fWeight = 68.5;

	//ljc�� ���� �����͸� ����ϱ�
	printf("���� : %d\n", ljc.nAge);
	printf("��ȭ��ȣ : %10d\n", ljc.nPhone);
	printf("������ : %.2f\n", ljc.fWeight);

	//2. ljc ����ü ũ��
	printf("ũ�� = %d\n", sizeof(ljc));

	//3. ����ü ���� �������� �ּҴ� �������ΰ�?
	printf("nAge �ּ� = %p\n", &ljc.nAge);
	printf("nPhone �ּ� = %p\n", &ljc.nPhone);
	printf("fWeight �ּ� = %p\n", &ljc.fWeight);
	// �׷��� �������̴�.

	//4. ����ü ������ ���� �ּҸ� �����Ϳ� ����

	unsigned int* pf = &ljc.nAge;
	
	printf("%d\n", pf[0]);
	printf("%d\n", pf[1]);
	printf("%f\n", *(float*)(pf+2));	
}