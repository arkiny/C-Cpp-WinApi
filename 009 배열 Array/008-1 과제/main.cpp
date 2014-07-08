/*
	@author		Heedong Arkiny Lee
	@date		07092014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	한글자씩 타이핑해서 틀린부분의 개수 세기
	예)
	주어진 문장	] a rolling stone gathers no moss
	타이핑		] a r_ll_ng s_one gathers no moss

	기본 ] 몇 글자가 틀렸습니다. :: ___
	확장 ] 타이핑 완료까지 걸린 시간 :: __

	참고 >> 띄어쓰기 포함한 문자열 입력
	scanf("%[^\n]", string);

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXLEN 65535 // 임시로 정한 char array의 Max Length

// Prototype
void print_signature();;
void printchara(char* input);
double diffclock(clock_t input1, clock_t input2);
void compare_char(char* origin, char* input);

// main method
void main(){
	// variable initialization
	// 포인터를 이용시에는 좀더 동적으로 활용할수 있겠으나
	// 현재 포인터 이용이 불가하므로 강제로 수열의 크기를 정해줘야함 (특히 scanf로 받을경우)
	char ex_string[MAXLEN] = "a rolling stone gathers no moss";
	char input_string[MAXLEN] = "";
	
	// time_t의 경우 초단위까지 계산은 가능하나 더 낮은 시간 계산은 불가능 하므로
	// clock_t(클럭)을 받아서 계산
	clock_t start_time, end_time;

	// 시간 차이는 양수이므로 float 보단 double을 받아서 시간을 계산
	double seconds = 0.0f;

	// 서명 출력
	print_signature();

	// 원본 글자열 출력
	// 원본 글자열도 입력 받을수 있으나, 일단은 패스
	printchara(ex_string);

	// 입력 받음	
	start_time = clock();
	scanf("%[^\n]", input_string);
	end_time = clock();

	// 원본과 비교후 다른 글자수와 위치 출력
	compare_char(ex_string, input_string);

	// clock을 받아서 계산하므로 따로 함수를 만들어서 계산
	seconds = diffclock(end_time, start_time);
	printf("타이핑 완료까지 걸린 시간 : %.2f second \n", seconds);	
	system("pause");
}

// 서명 출력
void print_signature(){
	printf("이희동\n");
	printf("07082014 SGA51A 우선과제\n");
	printf("================================================\n");
}

// 문자열끼리 비교후, 잘못된 문자위치 출력
// @param char* origin	원본 문자열
// @param char* input	비교할 문자열
void compare_char(char* origin, char* input){
	char* wronglocate = (char*)malloc(sizeof(origin)*sizeof(char));
	int i = 0;
	int wrongcount = 0;
	while (true){
		if (origin[i] == '\0'){
			break;
		}
		else if (origin[i] != input[i]){
			wronglocate[i] = '^';
			wrongcount++;			
		}
		else{
			wronglocate[i] = ' ';
		} //if()
		i++;
	} // while()
	printchara(wronglocate);
	printf("%d 글자가 틀렸습니다.\n", wrongcount);	
}

// 수업시간에 배운 print char array
// 문자열을 받아서 화면에 출력
// @param char* input 문자열(character array)
void printchara(char* input){
	int i = 0;
	while (true){
		printf("%c", input[i]);
		i++;
		if (input[i] == '\0'){
			break;
		}
	}//while()
	printf("\n");
}

// 클럭간의 시간 차이를 계산하여 초단위로 리턴
// @param clock_t input1 프로세스가 끝난 시간
// @param clock_t input2 프로세스가 시작된 시간
// @return duration time in second
double diffclock(clock_t input1, clock_t input2){
	double diffticks = input1 - input2;
	// 클럭틱은 보통 1ms마다 1번이므로 
	// 이미 지정되있는 CLOCK_PER_SEC(c에서는 1000)  이용
	// 하여 나누어 초단위로 재계산
	double diffms = diffticks / (CLOCKS_PER_SEC);
	return diffms;
}
