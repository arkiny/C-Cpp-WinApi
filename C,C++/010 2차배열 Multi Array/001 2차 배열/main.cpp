/*
	2�� ( ������ ) �迭 : Multi Array
	
	�� : ���� �� ��ǥ : Row		: Vertical
	�� : ���� �� ��ǥ : Column		: Horizontal

	int Array[��][��]

	- 1�� �迭�� ���� ���ӵ� �ּ�����
*/

#include <stdio.h>

void main(){
	// �䷡ �ʱ�ȭ �ϴ� ������ ���̵��� �Ѵ�.
	int table[3][4] =   { { 0, 1, 2, 3 },
						  { 4, 5, 6, 7 },
						  { 8, 9, 10, 11 } };
	//// 2�� �迭 -> �� ���
	//printf("�� ��� ------------- \n");
	//for (int i = 0; i < 3; i++){
	//	for (int j = 0; j < 4; j++){
	//		printf("%3d ", table[i][j]);
	//	}
	//	printf("\n");
	//}

	//printf("\n�ּ� ��� ----------- \n");
	//// 2�� �迭 -> �ּ� ���
	//for (int i = 0; i < 3; i++){
	//	for (int j = 0; j < 4; j++){
	//		printf("%3p ", &table[i][j]);
	//	}
	//	printf("\n");
	//}

	// 1��, 2�� �迭 ��� �޸𸮰� ���������� ����

	//printf("%d\n", *(table + 0));


	int nCount = sizeof(table) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("%3p ", &table[i]);
	}

	// 2�� �迭�� ��� table[0]���� ����������� ����
	printf("\n");
	for (int i = 0; i < nCount; i++){
		printf("%3d ", *(table[0]+i));
	}

	printf("\n");
	for (int i = 0; i < nCount; i++){
		printf("%3d ", *(*(table + 0) + i));
	}

	printf("\n");
	// *(*(table + i) + j)
	// i = ��, j = �� �̵�
	// �Գ� �Ź��ϴ�
	printf("%3d ", *(*(table + 1) + 0));
}