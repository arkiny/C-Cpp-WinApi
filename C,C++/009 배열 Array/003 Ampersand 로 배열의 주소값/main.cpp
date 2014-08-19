/*
	Ampersand ( & ) �����ڷ� �迭�� �ּ� Ȯ��
*/ 

#include <stdio.h>

void main()
{
	int arr[4] = {};
	arr[1] = 3;
	arr[3] = 5;

	// 1. Address check - &arr[0]
	//printf("arr[1]�� �ּ� = %p\n", &arr[1]);

	int nCount = sizeof(arr) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("&arr[%d]�� �ּ� = %p\n", i, &arr[i]);
	}

	printf("------------------------------------\n");
	// 2. Alternative Address check (arr+0) (arr+1)[���� �ּ��� �����ּ�]
	for (int i = 0; i < nCount; i++){
		printf("arr + %d�� �ּҴ� = %p\n", i, arr + i);
	}
}