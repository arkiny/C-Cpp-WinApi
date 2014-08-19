/*
	Ampersand ( & ) 연산자로 배열의 주소 확인
*/ 

#include <stdio.h>

void main()
{
	int arr[4] = {};
	arr[1] = 3;
	arr[3] = 5;

	// 1. Address check - &arr[0]
	//printf("arr[1]의 주소 = %p\n", &arr[1]);

	int nCount = sizeof(arr) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("&arr[%d]의 주소 = %p\n", i, &arr[i]);
	}

	printf("------------------------------------\n");
	// 2. Alternative Address check (arr+0) (arr+1)[시작 주소의 다음주소]
	for (int i = 0; i < nCount; i++){
		printf("arr + %d의 주소는 = %p\n", i, arr + i);
	}
}