/*
	1�� �迭 ������
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
	int nums[5] = { 3, 5, 6, 7, 8 };
	
	// �迭�� ���� �ּ�
	int *pnums = nums; // 5��¥�������� ������ �迭�� �����ּҸ� �˼� �ִ�.
	
	for (int i = 0; i < 5; i++){
		printf("nums�� %d��°�� ��� : %d\n", i, *(pnums+i));
		printf("nums�� %d��°�� ��� : %d\n\n", i, pnums[i]);
	}	
}