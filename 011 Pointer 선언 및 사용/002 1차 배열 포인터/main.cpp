/*
	1�� �迭 ������
*/

#include <stdio.h>
#include <stdlib.h>

// prototype
void show(int *pnums, int size);

void main(){
	int nums[5] = { 3, 5, 6, 7, 8 };
	
	// �迭�� ���� �ּ�
	int *pnums = nums; // 5��¥�������� ������ �迭�� �����ּҸ� �˼� �ִ�.
	
	// (nums + 0); // �ּ��� ���� �ּҸ� ����Ų��.

	// pnums�� Ȱ���ؼ� nums�� �ι�° �� ���
	for (int i = 0; i < 5; i++){
		// pointer�� ����
		printf("nums�� %d��°�� ��� : %d\n", i, *(pnums+i));
		// �迭�� ����
		printf("nums�� %d��°�� ��� : %d\n\n", i, pnums[i]);
	}	

	//
	int *pnums2 = (nums + 2);
	printf("pnums2 = %d\n", pnums2[0]);

	//int size = sizeof(pnums)/sizeof(int);
	int size = sizeof(nums)/sizeof(int);
	// function making
	show(pnums, size);
}

//void show(int pnums[], int size) ���� �Ȱ��� ����� �Լ�
void show(int *pnums, int size){
	for (int i = 0; i < size; i++){
		printf("�Լ��� �޾Ƽ� nums�� ��� = %d\n", *(pnums + i));
	}
	// range for�� ���� ��� ���� ����̱⶧���� �����͸� �̿��Ҽ� ����
	/*for (int x : pnums){
		
	}*/

}