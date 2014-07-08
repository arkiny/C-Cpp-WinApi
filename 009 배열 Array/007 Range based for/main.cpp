/*
	[ c++0x -> c++ 11]

	ranged base for
	- 배열을 위한 반복문

*/

#include <stdio.h>

void show(int* pnums);

void main(){
	int nums[] = { 7, -2, 5, 13, 27 };
	for (int x : nums)
	{
		printf("%d\n", x);
	}
	// range based for 로 출력하기
	show(nums);
}

void show(int* pnums){
	for (int x : input){// 시작과 끝이 있을 경우에만 가능
		printf("%d\n, x");
	}
}