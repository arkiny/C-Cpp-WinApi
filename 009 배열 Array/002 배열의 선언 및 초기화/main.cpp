/*
	�迭�� ����, �ʱ�ȭ
*/

#include <stdio.h>
int main(){
	// �ʱ�ȭ 3 - ������ ���ÿ� �ʱ�ȭ
	int nums[] = {0,1,2,3,4,8,9}; // �⺻������ 0
	// ���ȣ ���� �����ڿ� ���ؼ� �迭 �ּҰ� �ڵ� �Էµ�

	// �ʱ�ȭ ��� 1 - ���� ����
	/*nums[0] = 11;
	nums[1] = 22;
	nums[2] = 33;
	nums[3] = 44;
	nums[4] = 55;*/

	// �迭�� ũ��
	printf("�迭�� ũ�� = %d\n", sizeof(nums));

	// �迭�� ���� = ��ü ũ�� / ���� ũ��
	int nCount = sizeof(nums) / sizeof(int);
	printf("�迭�� ���� = %d\n", nCount);

	// �ʱ�ȭ 2 - 
	// �ݺ��� Ȱ���ؼ� �迭�� ���� ��� 1�� �ʱ�ȭ
	for (int i = 0; i < nCount; i++){
		//nums[i] = 1;
		printf("nums[%d] = %d\n", i, nums[i]);
	}

	return 0;
}