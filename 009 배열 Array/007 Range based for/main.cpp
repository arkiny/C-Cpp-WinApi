/*
	[ c++0x -> c++ 11]

	ranged base for
	- �迭�� ���� �ݺ���

*/

#include <stdio.h>

void show(int* pnums);

void main(){
	int nums[] = { 7, -2, 5, 13, 27 };
	for (int x : nums)
	{
		printf("%d\n", x);
	}
	// range based for �� ����ϱ�
	show(nums);
}

void show(int* pnums){
	for (int x : input){// ���۰� ���� ���� ��쿡�� ����
		printf("%d\n, x");
	}
}