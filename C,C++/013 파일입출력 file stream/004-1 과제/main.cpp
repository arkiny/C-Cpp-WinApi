/*
	@author		Heedong Arkiny Lee
	@date		07212014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	메모장으로 그린 맵 이미지 불러와서 화면 출력
	타일맵 불러오기 ( 크기는 고정 설정 )

	주의 ] 특수문자는 2 byte이고, 
		  각 열의 끝에는 null 문자가 있음을 고려

	응용 : 중간 과정 저장

	!! 난 타일맵 그리기를 그만두겠다 !!
	!! 타일맵 지겨움.... !!
	
	게임 프로그래머의 인생게임만들어 볼까
	세이브/로딩이 되는 알흠다운 인생 
	....

	1. Circular Array로 array 13개를 가지고 무한루핑돌게 만듬
		- 모든 프로세스를 저장할수는 없지만, 딱 필요한만큼의 렌더와 메모리 저장이 가능
		- 또한 무조건 바로 다음 상황이 랜덤으로 지정되지 않으므로, 세이브/로딩시의
		 상속성도 가질수 있다.
	2. 플레이어가 지나간 자리는 새로운 상황조성 업데이트
		- 13개짜리 배열을 선택한 이유는 주사위 두개는 12까지 나올수 있으므로, 
	      12가 나왔을시에 제자리로 돌아오므로 생기는 문제를 피하기 위함
	3. 바이너리 저장, 불러오기를 통해 세이브/로드가능...
	  - 랜덤 시드 역시 저장되므로, 세이브/로드 상속성을 가진다.
		근데 진짜 인생은 세이브/로드가 없다고 합니다....
*/

#include <stdio.h>		// FILE, fread, fwrite, printf
#include <stdlib.h>		// system(), rand(), srand(), _sleep()
#include <time.h>		// time()
#include <conio.h>		// _getch()

typedef struct game_info{
	int player_position;				// 현재 보드위의 플레이어 위치
	int current_money;					// 플레이어가 가진돈
	const int map_size = 13;			// 맵사이즈, 여기선 13으로 고정
	int current_map[13];				// 맵정보
	unsigned int rseed;					// 랜덤 시드 번호
}GAME_INFO;

void map_init(game_info *input);
int update(GAME_INFO *input);
void map_render(GAME_INFO *input);
void map_render_comp(GAME_INFO *input);
void icon_printer(int *input);
char keyinput();
void player_update(GAME_INFO *input, int status);
void print_signature();

void main(){	
	GAME_INFO play;
	char key = -1;
	int step; // 밟은 칸의 상황
	map_init(&play);
	FILE* pfile = nullptr;
	int save_flag = 0;
	
	while (key != 'q' || key != 'Q'){
		// 맵 렌더
		print_signature();
		map_render(&play);
		step = update(&play);
		printf("\n");
		map_render(&play);
		printf("\n");
		player_update(&play, step);
		// 게임 종료 상황
		if (play.current_money < 0){
			printf("당신은 거지가 되어 거리에 나앉게 되었습니다..\n");
			printf("이전 데이타를 로딩하시겠습니까? (y/n)\n");
			key = keyinput();
			// 주사위는 랜덤이라 바로 전상황과는 다른 상황이 나올수 있음
			if (key == 'y' || key == 'Y'){
				if (save_flag == 0){
					printf("세이브 파일이 없습니다. \n");
					printf("게임을 종료합니다. \n");
					system("pause");
					break;
				}
				else{
					pfile = fopen("udd.dat", "rb");	 // w: write, b : binary
					{
						fread(&play, sizeof(GAME_INFO), 1, pfile);
					}
					fclose(pfile);
					printf("로딩 완료\n");
					system("pause");
				}
			}
			else if (key == 'x' || 'X'){
				break;
			}
			else{
				printf("제대로 다시 입력해주세요.\n");
			}
		}
		// 해피엔딩...
		else if (play.current_money > 500000000){
			printf("5억을 번 당신은 치킨집을 차리고 즐거운 은퇴생활을 가지게 되었습니다.\n");
			break;
		}
		else{
			key = keyinput();
		}
		// 저장 불러오기
		switch (key)
		{
		case 's':
		case 'S':
			pfile = fopen("udd.dat", "wb");	 // w: write, b : binary
			{
				fwrite(&play, sizeof(GAME_INFO), 1, pfile);
			}
			fclose(pfile);
			save_flag = 1;
			printf("저장 완료\n");
			system("pause");
			break;
		case 'L':
		case 'l':
			if (save_flag == 1){
				pfile = fopen("udd.dat", "rb");	 // w: write, b : binary
				{
					fread(&play, sizeof(GAME_INFO), 1, pfile);
				}
				fclose(pfile);
				printf("로딩 완료\n");
				system("pause");
			}
			else {
				printf("세이브 파일이 없습니다. 게임을 그냥 진행합니다.\n");
				system("pause");
			}
			break;
		default:
			break;
		}
		system("cls");
	}
}

// map initialize
// 랜덤 시드도 따라 받는다
void map_init(game_info *input){		
	input->current_money = 350000;
	input->player_position = 0;
	input->current_map[0] = 8;
	for (int i = 1; i < input->map_size; i++){
		input->current_map[i] = rand() % 8;
	}
	input->rseed = time(NULL);
	srand(input->rseed);
}

// 플레이어 이동 및, 이동에 따른 맵업데이트
// 플레이어가 밟은 곳 상황 리턴
int update(GAME_INFO *input){
	int firstDice = rand() % 6 + 1;				// 첫번째 주사위
	int secondDice = rand() % 6 + 1;			// 두번째 주사위
	int sumDice = firstDice + secondDice;		// 두 주사위의 합
	int ret;
	
	// 간단한 연출
	printf("주사위를 굴립니다.");
	for (int i = 0; i < 3; i++){
		printf(".");
		_sleep(500);
	} 
	printf("\n");
	
	int i = 0;

	// 플레이어가 이동하면서 칸 업데이트
	while (i < sumDice){
		// 플레이어가 지나가는 곳은 상황바꿔주기 업데이트
		if (i + input->player_position < input->map_size){
			input->current_map[i + input->player_position] = rand() % 8;
		}
		// 현재위치와 다르게 만약 수열을 넘어가는 수가 나오면
		// 수열 처음부터 다시 기록할수 있도록
		else {
			input->current_map[i + input->player_position - input->map_size] 
				= rand() % 8;
		}
		i++;
	}	

	// 플레이어 포지션 확정
	if (i + input->player_position < input->map_size){
		// 확정전에 현재 스텝의 상황 리턴용 정수 변수에 저장
		ret = input->current_map[i + input->player_position]; 
		input->player_position = i + input->player_position;
	}
	else {
		ret = input->current_map[i + input->player_position - input->map_size];
		// 확정전에 현재 스텝의 상황 리턴용 정수 변수에 저장
		input->player_position = i + input->player_position - input->map_size;
	}

	// debug
	/*for (int i = 0; i < input->map_size; i++){
		printf(" %d ", input->current_map[i]);
	}*/
	printf("\n");
	printf("첫번째 주사위 값 : %d\n", firstDice);
	printf("두번째 주사위 값 : %d\t 주사위 합계 : %d\n", secondDice, sumDice);
	// debug

	return ret;
}

// 밟은 곳 상황에 맞는 업데이트
void player_update(GAME_INFO *input, int status){
	switch (status)
	{
	case 0:
		printf("\n회사에서 봉급을 받았습니다..... \n 카드회사들이 좋아합니다....\n");
		printf("200만원이 통장에 입금됩니다.\n");
		input->current_money = input->current_money + 2000000;
		break;
	case 1:
		printf("\n당신이 개발에 참여한 게임이 대박이 났습니다.\n");
		printf("당신에게도 코딱지만한 인센티브가 들어왔습니다.\n");
		printf("50만원이 통장에 입금됩니다.\n");
		input->current_money = input->current_money + 500000;
		break;
	case 2:
		printf("\n개발중...식대를 안대주는 회사라서, 식대가 나갑니다....\n");
		printf("최근 입출력 기기가 망가져서 새로삽니다...\n");
		printf("기타등등 돈나갈데는 많습니다...\n");
		printf("150만원이 통장에서 나갑니다.\n");
		input->current_money = input->current_money - 1500000;
		break;
	case 3:
		printf("\n집 대출 및 학자금 이자를 갚아야 됩니다.\n");
		printf("50만원이 통장에서 나갑니다.\n");
		input->current_money = input->current_money - 500000;
		break;
	case 4:
		printf("\n회사의 횡포를 견디다 못해 이직을 결정합니다.\n");
		printf("아껴쓴다고 아껴썼지만 돈은 나갑니다...\n");
		printf("50만원이 통장에서 나갑니다.\n");
		input->current_money = input->current_money - 500000;
		break;
	case 5:
		printf("\n헛된 희망을 가지고 로또를 사봅니다.\n");
		printf("당첨되었습니다!...... 5등\n");
		printf("5천원이 통장에 입금됩니다.\n");
		input->current_money = input->current_money + 5000;
		break;
	case 6:
		printf("\n....보증을 서줬던 친구가 도망갔습니다. \n");
		printf("당신의 모든 재산은 압류되었습니다.\n");
		input->current_money = 0;
		break;
	case 7:
		printf("\n신나는 생일! \n");
		printf("하지만 최근 생일대세는 생일자가 사는겁니다.\n");
		printf("10만원이 통장에서 나갑니다.\n");
		input->current_money = input->current_money + 100000;
		break;
	default:
		break;
	}

	printf("당신의 통장 : %d 원\n", input->current_money);
}

// 이동상황을 비교할수 있게
void map_render_comp(GAME_INFO *input){
	for (int i = 0; i < input->map_size; i++){
		printf("%d ", input->current_map[i]);
	}
	printf("\n");
}

// 계속 플레이어가 처음에 보이도록 조정해서 출력하는 함수
// 13개의 수열은 화면을 넘어가게 되므로 일단 9개만 출력한다.
// 언제나 플레이어가 수열의 첫번째에 있게 착각하게 만들어준다.
void map_render(GAME_INFO *input){
	printf("현재 통장 금액 : %d\n", input->current_money);
	for (int i = 0; i < 9; i++){
		if (i + input->player_position < input->map_size){
			icon_printer(&(input->current_map[input->player_position + i]));
		}
		else {
			icon_printer(&(input->current_map
				[i + input->player_position - input->map_size]));
		}
	}
	printf("\n");
	printf("   ↑");
}

// 그냥 맵 타일 인쇄하는 함수
// @param int *input 받은 정수에따라 다른 걸 그린다.
void icon_printer(int *input){
	switch (*input)
	{
	case 0:
		printf("| 봉급 |");
		break;
	case 1:
		printf("| 대박 |");
		break;
	case 2:
		printf("| 개발중 |");
		break;
	case 3:
		printf("| 대출 |");
		break;
	case 4:
		printf("| 이직 |");
		break;
	case 5:
		printf("| 로또 |");
		break;
	case 6:
		printf("| 파산 |");
		break;
	case 7:
		printf("| 생일 |");
		break;
	case 8:
		printf("| 출발 |");
		break;
	default:
		break;
	}
}

// 유저로부터 키를 받아와서 출력하는 메뉴
char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput

// 서명
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07232014 과제\n");
	printf("-------------------------------------------------------------\n");
	printf("  세이브/로딩이 되는 행복한 게임 프로그래머 인생 게임  \n");
	printf("| 진행 : 아무키 | 저장 : s, S  | 불러오기 : l, L | 종료 : q, Q |\n");
	printf("-------------------------------------------------------------\n");
}
