/*
	2차 ( 다차원 ) 배열 : Multi Array
	
	행 : 세로 쪽 좌표 : Row		: Vertical
	열 : 가로 쪽 좌표 : Column		: Horizontal

	int Array[행][열]

	- 1차 배열과 같이 연속된 주소형태
*/

#include <stdio.h>

void main(){
	// 요래 초기화 하는 습관을 들이도록 한다.
	int table[3][4] =   { { 0, 1, 2, 3 },
						  { 4, 5, 6, 7 },
						  { 8, 9, 10, 11 } };
	//// 2차 배열 -> 값 출력
	//printf("값 출력 ------------- \n");
	//for (int i = 0; i < 3; i++){
	//	for (int j = 0; j < 4; j++){
	//		printf("%3d ", table[i][j]);
	//	}
	//	printf("\n");
	//}

	//printf("\n주소 출력 ----------- \n");
	//// 2차 배열 -> 주소 출력
	//for (int i = 0; i < 3; i++){
	//	for (int j = 0; j < 4; j++){
	//		printf("%3p ", &table[i][j]);
	//	}
	//	printf("\n");
	//}

	// 1차, 2차 배열 모두 메모리가 순차적으로 증가

	//printf("%d\n", *(table + 0));


	int nCount = sizeof(table) / sizeof(int);
	for (int i = 0; i < nCount; i++){
		printf("%3p ", &table[i]);
	}

	// 2차 배열의 경우 table[0]부터 시작해줘야지 가능
	printf("\n");
	for (int i = 0; i < nCount; i++){
		printf("%3d ", *(table[0]+i));
	}

	printf("\n");
	for (int i = 0; i < nCount; i++){
		printf("%3d ", *(*(table + 0) + i));
	}

	printf("\n");
	// *(*(table + i) + j)
	// i = 행, j = 열 이동
	// 죤나 신박하다
	printf("%3d ", *(*(table + 1) + 0));
}