/*
	1차 배열 포인터
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
	int nums[5] = { 3, 5, 6, 7, 8 };
	
	// 배열의 시작 주소
	int *pnums = nums; // 5개짜리인지는 모르지만 배열의 시작주소를 알수 있다.
	
	for (int i = 0; i < 5; i++){
		printf("nums의 %d번째값 출력 : %d\n", i, *(pnums+i));
		printf("nums의 %d번째값 출력 : %d\n\n", i, pnums[i]);
	}	
}