/*
	1차 배열 포인터
*/

#include <stdio.h>
#include <stdlib.h>

// prototype
void show(int *pnums, int size);

void main(){
	int nums[5] = { 3, 5, 6, 7, 8 };
	
	// 배열의 시작 주소
	int *pnums = nums; // 5개짜리인지는 모르지만 배열의 시작주소를 알수 있다.
	
	// (nums + 0); // 주소의 다음 주소를 가리킨다.

	// pnums를 활용해서 nums의 두번째 값 출력
	for (int i = 0; i < 5; i++){
		// pointer의 형태
		printf("nums의 %d번째값 출력 : %d\n", i, *(pnums+i));
		// 배열의 형태
		printf("nums의 %d번째값 출력 : %d\n\n", i, pnums[i]);
	}	

	//
	int *pnums2 = (nums + 2);
	printf("pnums2 = %d\n", pnums2[0]);

	//int size = sizeof(pnums)/sizeof(int);
	int size = sizeof(nums)/sizeof(int);
	// function making
	show(pnums, size);
}

//void show(int pnums[], int size) 서로 똑같은 방법의 함수
void show(int *pnums, int size){
	for (int i = 0; i < size; i++){
		printf("함수로 받아서 nums를 출력 = %d\n", *(pnums + i));
	}
	// range for문 같은 경우 범위 기반이기때문에 포인터를 이용할수 없음
	/*for (int x : pnums){
		
	}*/

}