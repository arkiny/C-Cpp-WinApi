/*
	�Լ� ( ���� - Parameter )

	- ������ ����
	- �ּҷ� ����
*/

#include <stdio.h>

void show(int nums[]);

void main(){
	int nums[] = {7,5,8,4,6};
	//1 �Լ��� �ʿ伺
	show(nums);
}

// 2�Լ� ������ (����)
void show(int nums[]){ // nums�� �ּ��� ���·� �Է�
	int nCount = sizeof(*nums) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("nums = %d\n", nums[i]);
	}
}

// 1. ���� - nCount�� �̿��� �Լ��� �κ�
// 2. AddArray(�迭, 3) �迭�� ��ü���� 3�� ���ϴ� ��(�Լ���)