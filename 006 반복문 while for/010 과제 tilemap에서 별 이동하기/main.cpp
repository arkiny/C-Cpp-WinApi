/*
9 x 10 (nine by ten) 크의 타일 맵

★□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□
□□□□□□□□□□

★ 키보드 입력 이동 ]
상,하,좌,우 키 입력으로 이동하기

좌표 == (행, 열) (세로, 가로)

*/

#include<stdio.h>
int main(){
	// 세로 그리기
	for (int i = 0; i <= 8; i++){
		// 가로 그리기
		for (int j = 0; j <= 9; j++){
			printf(" (%d, %d) ", i, j); // 열
		}
		printf("\n"); // 개행
	}
}