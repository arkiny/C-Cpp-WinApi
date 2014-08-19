/*
	2차 배열 포인터
*/

#include <stdio.h>
// prototype
void show(int(*input2)[4], int x, int y);
void show2(int(*input)[4]);

// main
void main(){
	int table[3][4] = { 2, 4, 6, 8,
						1, 3, 5, 7,
						9, 7, 5, 3 };
	
	// 첫번째 행의 시작 주소
	int* pt = table[0]; // 1차 배열인지, 2차배열인지 컴퓨터는 몰랑 ㅋ
	printf("%d\n", *pt);
	// 첫행 두번째 열값 출력
	printf("%d\n", *(pt+(4*0)+1));
	printf("%d\n", pt[7]);


	// 2차배열 2차 포인터 형태로 받기
	table; // ((table+0)+0);
	int (*pt2)[4] = table; 
	// 2, 1의 좌표
	printf("%d, %d = %d\n", 2, 1, *(*(pt2 + 2) + 1));
	printf("%d, %d = %d\n", 2, 1, pt2[2][1]);

	// 함수로 만들기
	show(pt2, 2, 3);

	// for문 전체 출력
	show2(pt2);
} // main()

void show(int(*input)[4], int x, int y){
	printf("%d, %d = %d\n", x, y, input[x][y]);
} // show()

void show2(int(*input)[4]){
	// 나는 변태라서 변태 코드를 짠다.
	// I am shitty a nerd and geek.
	// therefore, I coded like hentai kkkkk
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			//show(input, i, j);
			printf("%3d", *(*(input + i) + j));
		} // end inner for
		printf("\n");
	} // end outer for
}// show()