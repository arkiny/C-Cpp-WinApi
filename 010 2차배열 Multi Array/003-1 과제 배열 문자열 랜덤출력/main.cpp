/*
	@author		Heedong Arkiny Lee
	@date		07102014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// prototype
void print_signature();
void ranSen(char pStr1[][12], char pStr2[][20], char pStr3[][6]);
// main function
void main(){
	
	// seeding
	srand(time(NULL));
	
	// variable initialization
	unsigned input_key = 0;
	char str1[][12] = { "고대에 ", "중세시대에 ", "삼국시대에 ", "고려시대에 " };
	char str2[][20] = { "게임을 잘하는 ", "염력을 쓰는 ", "총을 잘쏘는 ", "시간여행을 하는 " };
	char str3[][6] = { "왕", "상놈", "양반", "평민" };
	
	// Print out the function
	while (input_key != 'q'){
		print_signature();

		printf("\n\n당신의 전생은?\n");
		ranSen(str1, str2, str3);
		printf("\n\n 그만 하시려면 q를 눌러주세요.\n\n");
		input_key = _getch();		
		if (input_key == 0xE0 || input_key == 0) input_key = _getch();	// 주소값 check
		if (input_key == 'q'){
			break;
		}
		system("cls");
	}
}

// print out random Sentence
// @param ptr1[][12]
// @param ptr2[][17]
// @param ptr3[][5]
void ranSen(char pStr1[][12], char pStr2[][20], char pStr3[][6]){
	int randomNum = -1;

	printf("당신은 ");

	// 랜덤한 문자를 주소로 뽑아내어 출력한다.
	randomNum = rand() % 4;
	printf("%s", pStr1[randomNum]);

	randomNum = rand() % 4;
	printf("%s", pStr2[randomNum]);

	randomNum = rand() % 4;
	printf("%s", pStr3[randomNum]);
	printf("이었습니다\n");
}

// 서명 출력
void print_signature(){
	printf("이희동\n");
	printf("07102014 SGA51A 과제\n");
	printf("================================================\n");
}
