/*
	반복문 - while

	3가지 요소 : 시작값, 종료조건, 증감값

	1. 시작값
	while( 2. 종료 ){
	내용..

	3. 증감값
	}
	*/

#include <stdio.h>

void main(){
	// 1 부터 5까지 순차적으로 증가하는 값을 출력

	// 1. 시작값
	// index initialization
	int i = 0;

	// 2. 종료조건
	// looping and printing
	while (i < 6){	// while의 조건문 안이 true일시 무한 반복, false면 탈출
		printf("%d\n", i);
		// index increment
		// 3. 증가값 (1씩 증가)
		i++;
	}

	// 3부터 16까지 출력 ( +2 씩 증가 )
	// Re-initialize the index
	i = 3;
	printf("\n\n3부터 16까지 출력 ( +2 씩 증가 )\n");
	while (i <= 16){				// while i is less or equal to 16
		printf("%d\n", i);			// print index
		i += 2;						// index = index + 2
	}

	// 20 부터 1까지 출력 ( -3씩 감소 )
	i = 20; // re-initialize the index
	printf("\n\n2부터 1까지 출력 (-3씩 감소)\n");
	while (i >= 1){					// while i is larger or equal to 1
		printf("%d\n", i);			// print index
		i -= 3;						// index = index - 3
	}

	// 1부터 10까지 더한 값? ( 누적된 값 )
	int j = 1;						// index
	int sum = 0;					// for summary
	printf("\n\n1부터 10까지 더한 값 (누적된 값)\n");
	while (j <= 10){
		sum = sum + j;				
		printf("sum + %d = %d\n", j ,sum);
		j++;
	}
}