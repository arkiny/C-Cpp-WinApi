/*
@author : Heedong Lee (arkinylee@gmail.com)
@date : 06292014

	while 문 활용
	* 8개 그리기
	*
	 *
	  *
       *
        *
	     *
	      *
	       *
가로 : H
세로 : V
이중 while 문 활용.
*/

#include <stdio.h>
int main(){

	printf("SGA 51 - 이희동\n");
	printf("while문을 이용하여 대각선 그리기\n");
	printf("연산 속도 차이에 따른 두가지 방법\n");
	printf("차이점은 코드에 달려있는 주석을 참조해주시길 바랍니다.\n");


	// 1. 시작값
	// 1. variable initialization
	// 순서는 1이 아닌 0부터 시작합니다. (이 부분은 취향이므로 1에서 시작하셔도 무방합니다.)
	// zero based index

	int i = 0;
	int j = 0;
	printf("\nUsing Solution 1 : Absolute O(n^2)\n");
	printf("1번 답안 : 무조건 n^2번의 처리를 하는 코드\n");

	// O(n^2)
	// 이하 코드는 조건 연산을 이용한 코드로, 위의 코드보다는 약간 더 프로세스타임을 잡아먹는 방법입니다.
	// 주로 처음하시는 분들이 조건문과 반복문을 배웠을 경우, 아래와 같은 코드를 이용합니다.
	while (i < 8){								// 외곽반복 시작(행)		Begin Outer loop (Row)

		j = 0;									// 매 행반복문마다 열 인덱스 초기화
		// Re-initialization column index J for Every outer Loop

		while (j < 8){							// 내각 반복 시작(열)	Begin Inner loop (Column)
			// 위의 코드와 다른점은 무조건 8번째 열까지 반복문이 진행된다는
			// 점입니다.
			i == j ? printf("*") : printf(" "); // 만약 행순과 열순이 같을 경우 *을 출력, 다른 경우 빈칸 출력
			j++;								// 3. 열 증가			Column increment
		} // End inner while 

		printf("\n");							// 별표 출력 및 개행		Print Asterisk and move to newline
		i++;									// 3. 행 증가			Row increment
	} // End outer while

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	// 1. 시작값
	// 1. variable initialization
	// 이미 위에서 쓰인 변수들이므로, 다시 초기화하여 사용합니다.
	i = 0;
	j = 0;

	// 2. 종료조건 (i가 8과 같거나 커지면 반복 종료)
	// 2. Looping and Printing
	// I think this will take O(nlogn) (... maybe)
	// If we learned array, I think we can decrease process time shorter, in my opinion.
	// However, in this time, we have not yet learned array and data structure, I just using two loops.
	// 만약 우리가 수열(Array)을 배웠다면,  프로세스 타임을 좀 더 줄이는 방법(O(n))이 있을거라고 생각합니다.
	// 하지만 이번엔 아직 우리가 수열과, 데이타 구조를 배우지 않았으므로, 2개의 반복문을 이용한 방법으로
	// 프로그램을 짰습니다.
	printf("Using Solution 2 : Faster than Previous Solution\n");
	printf("2번 답안 : 위 답보단 빠른 처리속도의 코드\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// 위 코드와 다른점은 이 내각 순환문에서의 차이에서 이루어지며,											//
	// 위 코드는 공백을 포함 8개의 문자를 처리하여 출력하지만 ( 8*8 = 총64개)								//
	// 이 코드는 1+2+3+4+5+6+7+8 = 36 개의 문자만을 처리하여												//
	// 출력합니다. 코드상의 차이점은 내각 코드의 조건을 참조하시길 바랍니다.									//
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	while (i < 8){								// 외곽반복 시작(행)		Begin Outer loop (Row)
											
		j = 0;									// 매 행반복문마다 열 인덱스 초기화
												// Re-initialization column index J for Every outer Loop

		while (j < i){							// 내각 반복 시작(열)	Begin Inner loop (Column)
			printf(" ");						// 뛰어쓰기 추가			Space added
			j++;								// 3. 열 증가			Column increment
		} // End inner while 

		printf("*\n");							// 별표 출력 및 개행		Print Asterisk and move to newline
		i++;									// 3. 행 증가			Row increment
	} // End outer while

		
	getchar();
	return 0;
}
