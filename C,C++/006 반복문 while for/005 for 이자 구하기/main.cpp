/*
	for Ȱ�� ]

	���� ( ��ġ�� : �ѹ��� �� �ñ� )

	�� ���� 3.1%

	�� ������ ? __
	��Ⱓ �ñ��� ? __

	1��° : ���� __, �ѱݾ� __
	2��° ..
	n��° : ���� __, �ʱݾ�__

	���� ]
	���� = ���� * 0.031;
	�ѱݾ� = ���� + ���� �ѱݾ�;
*/

#include<stdio.h>
int main(){
	// Variable Initialization
	// ���� �ʱ�ȭ
	// �������, ������, ���� ��¿� ����
	int deposit = -1, years = -1, benefit = -1;
	
	// Scanning
	// �Է´ܰ�
	printf("�󸶳� �����ðڽ��ϱ�?\n");
	scanf("%d", &deposit);
	printf("��� �����ðڽ��ϱ�?\n");
	scanf("%d", &years);
	benefit = deposit * 0.031f;

	// Loop, calculation and printing
	// �ݺ�, ���, ��´ܰ�
	for (int i = 1; i <= years; i++){
		deposit = deposit + benefit;			// �ѱݾ� = ���� + ���� �ѱݾ�
		printf("%d��° : ���� %d, �ѱݾ� %d\n", i, benefit, deposit);
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	printf(" ���� ���� �Ѥ�\n");
	// Variable Initialization
	// ���� �ʱ�ȭ
	// �������, ������, ���� ��¿� ����
	//int deposit = -1, years = -1, benefit = -1;

	// Scanning
	// �Է´ܰ�
	printf("�󸶳� �����ðڽ��ϱ�?\n");
	scanf("%d", &deposit);
	printf("��� �����ðڽ��ϱ�?\n");
	scanf("%d", &years);

	// Loop, calculation and printing
	// �ݺ�, ���, ��´ܰ�
	for (int i = 1; i <= years; i++){
		benefit = deposit * 0.031;				// ���� = ���� * 0.031
		deposit = deposit + benefit;			// �ѱݾ� = ���� + ���� �ѱݾ�
		printf("%d��° : ���� %d, �ѱݾ� %d\n", i, benefit, deposit);
	}


	/////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	
	////////////////// ������ ���
	int nMoney = 0;	// �ñ� �ݾ�
	int nYear = 0;	// �ñ� �Ⱓ
	const float fInterestRate = 0.031f;	// ������ (���)
	int nInterest = 0; // ����

	printf("�ݾ��� : ");
	scanf("%d", &nMoney);
	printf("�� �Ⱓ: ");
	scanf("%d", &nYear);

	for (int i = 0; i <= nYear; i++){
		nInterest = nMoney * fInterestRate;
		nMoney = nMoney + nInterest;
		printf("%d �� : ���� = %d, �ѱݾ� = %d\n", i, nInterest, nMoney);
	}
}