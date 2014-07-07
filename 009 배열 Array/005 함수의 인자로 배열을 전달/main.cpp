/*
	함수 ( 인자 - Parameter )

	- 값으로 전달
	- 주소로 전달
*/

#include <stdio.h>

void show(int nums[]);

void main(){
	int nums[] = {7,5,8,4,6};
	//1 함수의 필요성
	show(nums);
}

// 2함수 디자인 (정의)
void show(int nums[]){ // nums는 주소의 형태로 입력
	int nCount = sizeof(*nums) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("nums = %d\n", nums[i]);
	}
}

// 1. 과제 - nCount를 이용한 함수의 부분
// 2. AddArray(배열, 3) 배열의 전체값에 3씩 더하는 것(함수로)