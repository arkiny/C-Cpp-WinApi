/*
	배열의 선언, 초기화
*/

#include <stdio.h>
int main(){
	// 초기화 3 - 생성과 동시에 초기화
	int nums[] = {0,1,2,3,4,8,9}; // 기본세팅은 0
	// 대괄호 안은 생성자에 의해서 배열 주소값 자동 입력됨

	// 초기화 방법 1 - 직접 대입
	/*nums[0] = 11;
	nums[1] = 22;
	nums[2] = 33;
	nums[3] = 44;
	nums[4] = 55;*/

	// 배열의 크기
	printf("배열의 크기 = %d\n", sizeof(nums));

	// 배열의 개수 = 전체 크기 / 단위 크기
	int nCount = sizeof(nums) / sizeof(int);
	printf("배열의 개수 = %d\n", nCount);

	// 초기화 2 - 
	// 반복문 활용해서 배열의 값을 모두 1로 초기화
	for (int i = 0; i < nCount; i++){
		//nums[i] = 1;
		printf("nums[%d] = %d\n", i, nums[i]);
	}

	return 0;
}