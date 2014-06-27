/*
	�ݺ��� - while

	3���� ��� : ���۰�, ��������, ������

	1. ���۰�
	while( 2. ���� ){
	����..

	3. ������
	}
	*/

#include <stdio.h>

void main(){
	// 1 ���� 5���� ���������� �����ϴ� ���� ���

	// 1. ���۰�
	// index initialization
	int i = 0;

	// 2. ��������
	// looping and printing
	while (i < 6){	// while�� ���ǹ� ���� true�Ͻ� ���� �ݺ�, false�� Ż��
		printf("%d\n", i);
		// index increment
		// 3. ������ (1�� ����)
		i++;
	}

	// 3���� 16���� ��� ( +2 �� ���� )
	// Re-initialize the index
	i = 3;
	printf("\n\n3���� 16���� ��� ( +2 �� ���� )\n");
	while (i <= 16){				// while i is less or equal to 16
		printf("%d\n", i);			// print index
		i += 2;						// index = index + 2
	}

	// 20 ���� 1���� ��� ( -3�� ���� )
	i = 20; // re-initialize the index
	printf("\n\n2���� 1���� ��� (-3�� ����)\n");
	while (i >= 1){					// while i is larger or equal to 1
		printf("%d\n", i);			// print index
		i -= 3;						// index = index - 3
	}

	// 1���� 10���� ���� ��? ( ������ �� )
	int j = 1;						// index
	int sum = 0;					// for summary
	printf("\n\n1���� 10���� ���� �� (������ ��)\n");
	while (j <= 10){
		sum = sum + j;				
		printf("sum + %d = %d\n", j ,sum);
		j++;
	}
}