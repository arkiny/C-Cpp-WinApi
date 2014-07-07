/*
@author		Heedong Arkiny Lee
@date		07062014
@Git		https://github.com/arkiny/SGA-Learning-Heedong

과제 ]] 조작 주사위 만들기

0~99까지의 숫자를 랜덤으로 뽑아내어 그에 맞는 주사위로 치환하면
각자 확률에 맞는 보상을 뽑아낼수 있음
1	->	-100 c			60 %	- 0~59
2	->	300 c			32 %	- 60~91
3	->	-5000 c			4 %		- 92~95
4	->	20000 c			2 %		- 96~97
5	->	-1000000 c		1 %		- 98
6	->	100000000 c		1 %		- 99
*/

#include <stdio.h>		// printf()
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()
#include <process.h>	// _getpid()
#include <conio.h>		// _getch()

// Function Prototype
// 함수 선언 (메인함수 아래 붙어있는 순서대로)
void game_Interface(int total);
void print_reward();
char key_scan();
void seed_basedonTime();
void seed_basedonTimeandProcess();
unsigned long mix(unsigned long a, unsigned long b, unsigned long c);
void seed_usingmix();
int randomRange(int min, int max);
int diceCheck(int input_num);
int rewardCheck(int input_num);

// Main function
void main(){
	// 변수 선언
	// Variable initialization
	int user_total = 1000;
	int dice_num = -1;
	int reward = -1;
	bool end_trigger = true;
	
	// 랜덤함수를 위한 시딩
	// Seeding
	// seed_basedonTime;
	// seed_basedonTimeandProcess;
	seed_usingmix();

	while (end_trigger){
		// Printing main interface
		game_Interface(user_total); 

		//  Actual game engine
		switch (key_scan()){
		case '1' :
			// Print the reward interface on the console
			print_reward();
			break;
		case 'Q' :
		case 'q':
			// if end trigger fired, game end
			end_trigger = false;	
			break;
		default :
			printf("\n\n주사위를 던집니다. \n");
	
			// using dicecheck fucntion and randomRange function 
			dice_num = diceCheck(randomRange(0, 99));
			
			printf("나온 주사위 눈 : %d \n", dice_num);
			
			// using rewardcheck function
			reward = rewardCheck(dice_num);
			
			printf("당신이 가진 돈 %d에서 %d만큼 더해집니다. \n", user_total, reward);
			user_total += reward;

			// Game over triger
			if (user_total < 0){
				printf("당신은 파산하였습니다.\n\n\n\n");
				printf("GAME OVER.\n");

				end_trigger = false;
			}
			break;
		}

		system("pause");
		system("cls");
	}
}

// 주요 인터베이스 출력
// Printing main interface
void game_Interface(int total){
	printf("Heedong Lee's Simple Dice Game\n");
	printf("--------------------------------------\n");	 // printing upper CUI
	printf("당신이 가진 금액이 0이하가 되면 Game Over\n");
	printf("--------------------------------------\n");
	printf("현재 당신이 가진 금액 : %d\n\n", total);
	printf("명령어를 입력하세요 : \n");
	printf("[1] 주사위눈에 따른 보상 보기, [아무키] 게임진행하기, [q] 게임 종료 \n");
}

// 주사위 눈에 따른 보상 출력
// Print Reward
void print_reward(){
	printf("\n\n주사위 눈 :     보상\n");
	printf("    1    : -100 \n");
	printf("    2    : 300 \n");
	printf("    3    : -5000 \n");
	printf("    4    : 20000 \n");
	printf("    5    : -1000000 \n");
	printf("    6    : 100000000 \n");
	printf("\n");

}

// 키 스캔
// Scanning the key
char key_scan(){
	char input_key = _getch();
	if (input_key == 0xE0 || input_key == 0) input_key = _getch(); // address check
	return input_key;
}

// 현재 시간을 이용한 무작위 숫자 도출 (24일마다 같은 패턴이 있다고 함)
// Initialize random number generator using currunt time
void seed_basedonTime(){
	srand(time(NULL));
}

// 현재 시간 및 프로세스ID(현 프로그램가 가진 프로세스ID)를 이용한
// 무작위 숫자 도출
// Initialize random number generator using currunt time
// and current process ID (for more diversity)
void seed_basedonTimeandProcess(){
	srand((signed)time(NULL) * _getpid());
}

// 이하 링크에서 떠온 96비트 믹스 펑션...
// 분석 하려했는데 아직도 이해는 못하겠음...
// Robert Jenkins' 96 bit Mix Function
// Still cannot figure out how it works
// reference : http://burtleburtle.net/bob/hash/doobs.html
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
	a = a - b;  a = a - c;  a = a ^ (c >> 13);
	b = b - c;  b = b - a;  b = b ^ (a << 8);
	c = c - a;  c = c - b;  c = c ^ (b >> 13);
	a = a - b;  a = a - c;  a = a ^ (c >> 12);
	b = b - c;  b = b - a;  b = b ^ (a << 16);
	c = c - a;  c = c - b;  c = c ^ (b >> 5);
	a = a - b;  a = a - c;  a = a ^ (c >> 3);
	b = b - c;  b = b - a;  b = b ^ (a << 10);
	c = c - a;  c = c - b;  c = c ^ (b >> 15);
	return c;
}

// 클락(시피유가 가진 일종의 시간개념), 현재 시간, 그리고 프로세스아이디를 믹스하여
// 무작위 숫자를 도출
// using mixed clock, current time and process id number for seeding
// it give more diversity to seeding
void seed_usingmix(){
	unsigned long seed = mix(clock(), time(NULL), getpid());
	srand(seed);
}

// 수업시간에 한 랜덤 레인지 함수
// Return a random number between min and max
// @param int min 
// minimum number of the range
// @param int max 
// maximum number of the range
// @return int
// Random number between min and max
int randomRange(int min, int max){
	return rand() % ((max + 1) - min) + min;
}

// 랜덤함수에서 나온 숫자를 주사위 수로 변환
// return dice number of the input number
// @param int input_num
// Input number
// @return int
// Dice Number
int diceCheck(int input_num){
	if (input_num >= 0 && input_num <= 59){
		// you have got "1" 
		// 60 percents (0~59)
		return 1;
	}
	else if (input_num >= 60 && input_num <=91){
		// you got "2"
		// 32 percents (60~91)
		return 2;
	}
	else if (input_num >= 92 && input_num <= 95){
		// you got "3"
		// 4 percents (92~95)
		return 3;
	}
	else if (input_num >= 96 && input_num <= 97){
		// you got "4"
		// 2 percents (96~97)
		return 4;
	}
	else if (input_num == 98){
		// you got "5"
		// 2 percents (98)
		return 5;
	}
	else if (input_num == 99){
		// you got "6"
		// 2 percents (9)
		return 6;
	}
	else {
		printf("Error : Wroing number");
		return -1;
		// error
	}
}

// 주사위 숫자에서 보상으로 변환
// return reward amount of the input number
// @param int dice_num
// dice number
// @return int
// Reward Amount
int rewardCheck(int dice_num){
	switch (dice_num)
	{
	case 1 :
		return -100;
		break;
	case 2:
		return 300;
		break;
	case 3:
		return -5000;
		break;
	case 4:
		return 20000;
		break;
	case 5:
		return -1000000;
		break;
	case 6:
		return 100000000;
		break;
	default:
		// error handling
		printf("Error: Wrong dice number\n");
		break;
	}
}