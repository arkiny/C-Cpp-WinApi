// @author	: Heedong Arkiny Lee
// @date	: 07032014
// @Git		: https://github.com/arkiny/SGA-Learning-Heedong

/*
	과제 ]]

	#include <conio.h>
	kbhit() , getch()

	무한루프...
	{
	A, a 입력 -> "Attack~~~!"
	S, s 입력 -> "Stop~~~~!"

	Q, q 입력 -> ""
	1 입력


	x 키 입력 -> 프로그램 종료
	기타 입력 -> 잘못된 키 입력
	}
*/

// I will make a MUD game which was my first online in my memory
// This game is a just concept, therefore I will skip the networking part
// 어렸을 때 같이 MUD게임을 했던 친구를 만나고 돌아와서 새벽 감성 돋는 김에 후루룩 만듬
// 내 첫번째 온라인 게임이었던 삼국지전기와 퇴마록(MUD)를 추억하며....

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main(){
	// variable 초기화 // Actually data table
	unsigned char input_key = 0;			// 플레이어가 입력한 키 저장
	int teemo_health = 460;					// 티모의 최초 체력
	unsigned const int teemo_attack = 47;	// 티모의 공격력(상수)
	int player_health = 200;				// 플레이어 체력
	unsigned int player_mana = 50;			// 플레이어 마나
	unsigned const int a_skill = 100;		// 일반 공격 공격력(상수)
	unsigned const int q_skill = 150;		// q스킬 공격력 (상수)
	unsigned const int w_skill = 130;		// w스킬 공격력 (상수)
	unsigned const int e_skill = 120;		// e스킬 공격력 (상수)
	unsigned const int r_skill = 300;		// r스킬 공격력 (상수)
	unsigned const int one_item = 30;		// 1번 아이템 효능 (상수)
	unsigned int one_item_num = 3;			// 1번 아이템 개수
	unsigned const int two_item = 15;		// 2번 아이템 효능 (상수)
	unsigned int two_item_num = 1;			// 2번 아이템 개수


	// Give chance to skip intro
	printf("인트로 스킵은 지금 s키를 눌러주세요\n");
	input_key = _getch();
	if (input_key == 0xE0 || input_key == 0) input_key = _getch();	// 주소값 check
	switch (input_key) {
	case 's':
		//skip
		break;
	default:
		// Intro Part, give motivation to player
		// Step and clear effect using pause and cls
		printf("\n\n\n\n\n당신은 기억하십니까?\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n천리안, 하이텔, 나우누리 시절해 했던,\n");
		printf("MUD, multi user dugeon 게임들을요.,\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n수십만원 짜리 그래픽카드가 아니라,\n");
		printf("최고의 그래픽카드인 당신의 상상력을 이용했던 그 게임,\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n기억 못하시거나 모르셔도 됩니다.\n");
		printf("오늘 당신은 그 게임의 일부를 맛보시게 됩니다.\n\n\n\n\n");
		system("pause");
		system("cls");
		break;
	}
	



	while (input_key != 'x'){				// 플레이어가 입력한 키가 x일 경우 게임 종료
		///////////////////////////////////////////////////////////////// Plaza
		printf("\n\n                              [ 광 장 ]\n\n");
		printf("[ Player ] Lv 5, 견습전사\n\n");
		printf("수많은 사람들이 서로 잡담을 나누며 상품 거래를 하는 흔한 마을의 광장이다.\n\n");
		printf("동(오른쪽 방향키)쪽에는 동물들이 많이 살고 있을 듯한 숲이 보인다.\n");
		printf("서(왼쪽 방향키)쪽에는 상점가가 보인다. 장비를 사고 팔수 있어보인다.\n");
		printf("남(아래쪽 방향키)쪽에는 거대한 성이 보인다. 왕이 살고 있을거 같다.\n");
		printf("북(위쪽 방향키)쪽에는 높은 산이 보인다.\n");
		
		printf("\n 동[→] 서[←] 남[↓] 북[↑], 스킬 및 아이템 확인[i] 게임 종료[x]\n");
		// 플레이어 명령어 입력 
		input_key = _getch();
		if (input_key == 0xE0 || input_key == 0 ) input_key = _getch();	// 주소값 check
		switch (input_key)
		{
		case 77 ://///////////////////////////////////////////////////// eastern forest
			system("cls");
			printf("\n\n 동쪽으로 이동하였다. \n");
			printf("\n\n                          [ 소환사의 협곡 ]\n\n");
			printf("왠 다이아몬드처럼 생긴 건물들과 포탑들이 늘어서 있다.\n");
			printf("수많은 사람 비스므리한 것들이 줄을 지어 어딘가로 이동하고 있다.\n");
			printf("\n주변을 둘러보고 있는 데..\n\n 야생의 티모가 나타났다!\n\n");
			
			system("pause");
			// battle phase
			if (teemo_health > 0){ // 티모가 살아있을때 전투시작
				while (teemo_health > 0 && input_key!='x'){  
					// 티모 체력이 없거나, 종료조건 'x' 입력시 탈출	

					printf("\n티모(Lv 1) 현재 체력 : %d \n", teemo_health);
					printf("\n티모 : "" ^오^ 그건 좀 따가울거야. ^오^ ""\n");
					printf("\n티모가 맹독성침으로 공격해옵니다.\n");

					// 티모로부터의 공격, 플레이어 현재체력 - 티모 공격력
					player_health -= teemo_attack;
					if (player_health <= 0){ // 플레이어 체력이 다됬을시
						printf("당신은 체력이 다다하여 쓰러졌습니다.\n");
						input_key = 'x';
						break; // 반복문 탈출
					}
					else{// 플레이어 체력이 남아있을 시에 전투 페이즈 계속
						printf("당신의 체력이 %d 만큼 줄었습니다.\n", teemo_attack);
						printf("\n당신의 현재 체력 : %d ", player_health);
						printf("당신의 현재 마나 : %d \n", player_mana);
						printf("\n당신의 행동을 정하세요. 도망칠 길 따윈 없습니다.\n");
						printf("일반공격[a], 휴식[s], 배쉬[q], 피어스[w], 볼링배쉬[e], 파이널 스트라이크[r]\n");
						printf("체력포션사용[1], 마나포션사용[2] 게임 종료[x] \n");
						
						// 플레이어 명력 입력
						input_key = _getch();
						if (input_key == 0xE0 || input_key == 0) input_key = _getch();
						switch (input_key)
						{
						case 97: // a키
							printf("\n당신은 검을 휘둘러 %d의 데미지로 티모를 공격합니다.\n", a_skill);
							teemo_health -= a_skill;	// 공격력에 따른 티모 체력 감소
							break;
						case 115: // s키
							printf("\n당신은 멍때리며 소량의 체력(%d)을 회복합니다.\n", 10);
							player_health += 10;	// 플레이어 체력회복
							printf("당신의 현재 체력 : %d \n", player_health);
							break;
						case 113: // q키
							if (player_mana >= 20){	// 마나를 이용하는 스킬이므로 마나 체크
								printf("\n배쉬!!!.\n");
								printf("당신은 검을 힘차게 휘둘러 %d의 데미지로 티모를 공격합니다.\n", q_skill);
								printf("20의 마나가 소모되었습니다.\n");
								teemo_health -= q_skill;	// 공격력에 따른 티모 체력 감소
								player_mana -= 20;			// 마나 사용량에 따른 마나감소
							}
							else {	// 마나가 없을시 
								printf("\n마나가 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 119: // w키
							if (player_mana >= 15){ // 마나를 이용하는 스킬이므로 마나 체크
								printf("\n피어스!!!.\n");
								printf("당신은 검을 힘차게 찔러 %d의 데미지로 티모를 공격합니다.\n", w_skill);
								printf("15의 마나가 소모되었습니다.\n");
								teemo_health -= w_skill; // 공격력에 따른 티모 체력 감소
								player_mana -= 15;			// 마나 사용량에 따른 마나감소
							}
							else { // 마나 없을시
								printf("\n마나가 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 101: // e키
							if (player_mana >= 30){ // 마나를 이용하는 스킬이므로 마나 체크
								printf("\n볼링 배쉬!!!.\n");
								printf("당신은 검을 힘차게 휘둘러 주변의 사물을 이용해\n %d의 데미지로 티모를 공격합니다.\n", e_skill);
								printf("15의 마나가 소모되었습니다.\n");
								teemo_health -= e_skill; // 공격력에 따른 티모 체력 감소
								player_mana -= 30;			// 마나 사용량에 따른 마나감소
							}
							else {
								printf("\n마나가 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 114: // r키
							if (player_mana >= 50){ // 마나를 이용하는 스킬이므로 마나 체크
								printf("\n파이널 스트라이크!!!.\n");
								printf("당신은 온몸의 기를 검에 모아\n %d의 데미지로 티모를 공격합니다.\n", r_skill);
								printf("50의 마나가 소모되었습니다.\n");
								teemo_health -= r_skill; // 공격력에 따른 티모 체력 감소
								player_mana -= 50;			// 마나 사용량에 따른 마나감소
							}
							else { // 마나 없을시 
								printf("\n마나가 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 49: // 1키, 아이템 사용
							if (one_item_num >= 1){ // 아이템 개수 체크
								printf("\n꿀꺽꿀꺽, 당신은 체력포션을 마십니다.\n");
								printf("\n당신은 소량의 체력(%d)을 회복합니다.\n", one_item);
								printf("\n남은 체력포션 개수 : %d개\n", one_item_num);
								one_item_num--;			// 사용시 아이템 개수 감소
								player_health += one_item;	// 아이템 효능에 따른 체력회복
							}
							else{ // 해당 아이템 없을시
								printf("\n체력 포션이 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 50: // 2키
							if (two_item_num >= 1){ // 아이템 개수 체크
								printf("\n꿀꺽꿀꺽, 당신은 마나 포션을 마십니다.\n");
								printf("당신은 소량의 마나(%d)를 회복합니다.\n", two_item);
								printf("\n남은 마나포션 개수 : %d개\n", two_item_num);
								two_item_num--;				// 사용시 아이템 개수 감소
								player_mana += two_item;	// 아이템 효능에 따른 마나 회복
							}
							else{ // 해당 아이템 없을시
								printf("\n마나 포션이 모자랍니다. 당신은 그냥 멍때립니다.\n");
							}
							break;
						case 120: // 종료키가 트리거됬을시
							printf("\n종료 키를 누르셨습니다. 진짜로 종료하시겠습니까?\n");
							printf("(y/n) : ");
							scanf("%c", &input_key);

							if (input_key == 'y'){  // 재확인
								input_key = 'x';
							}
							else {					// 종료 확인이 안됬을 경우
								input_key = 0;
							}
							break;
						default:
							printf("\n잘못된 키를 입력하셨습니다.\n");
							break;
						} // end switch						
					}
				}
				// 승리나 사망시 처리
				if (teemo_health <= 0){
					printf("티모를 쓰려뜨렸지만, 이내 쓸모 없었다는걸 깨닫고 광장으로 돌아가기로 합니다.\n");
				}
				else if (player_health <= 0) { // Game over(player 사망시)
					printf("Game over\n");
				}
				else{
					printf("전투중에 종료하셨으므로, 페널티가 주어... 질리가 없습니다.\n");// do nothing
				}
				}
				else{
					// 이미 티모를 쓰러뜨렸을때 처리
					printf("티모가 쓰러져있습니다.\n 이내 할게 없다는걸 깨닫고 광장으로 돌아가기로 합니다.\n");
				}
				system("pause");			
			break;
		////////////////////////////////////////////////// 여기서부턴 미완성 부분 단순 인터페이스 처리
		case 75 : ////////////////////////////////////////////////////// western item mall(미완)
			system("cls");
			printf("\n\n 서쪽으로 이동하였다. \n");
			printf("\n\n                          [ 상점가 입구 ]\n\n");
			printf("걸스데이의 조현영을 닮은 예쁜 도우미가 간판을 들고 안내를 하고 있다.\n");
			printf("\n도우미 : 현재는 컨셉시연 중이라 이용이 불가능합니다. \n");

			printf("\n광장으로 돌아가기로 했다. \n\n");		
			system("pause");
			system("cls");
			break;
		case 80 : /////////////////////////////////////////////////////// southern castle(개그)
			system("cls");
			printf("\n\n 남쪽으로 이동하였다. \n");
			printf("\n\n                          [ 홍콩행 게이바 ]\n\n");
			printf("내 이름은 존슨. 어제 나의 성 정체성을 깨닫게 되었다\n");
			printf("그랬다 난 게이었던 것이다. 게이바나 가야징. \n\n");
			printf("그러나 게이바의 분위기는 상상 이상으로 하드코어 했다. \n");
			printf("어서 여기를 탈출해야 겠다. \n\n");
			printf("PINK 씨 :  ""들어올 땐 마음대로 들어왔겠지만 나갈 땐 안된단다."" \n\n");
			
			system("pause");
			system("cls");

			// silence
			// 정적 때리기
			printf("...\n");
			system("pause");
			system("cls");
			printf("본 장면은 인터넷 유행어의 패러디이며,\n");
			printf("성 소수자에 대한 차별, 나쁜 의미로 쓰인것이 아닙니다.\n");
			printf("본의 아니게 감정을 상하게 했다면 사과드립니다.\n");
			printf("\n\nGame Over\n");
			input_key = 'x';
			break;
		case 72 : /////////////////////////////////////////////////////// northern mountain(미완)
			printf("\n\n 북쪽으로 이동하였다. \n");
			printf("\n\n                          [ 북악산 입구 ]\n\n");
			printf("마을과 산사이에 넓고 깊은 계곡이 펼쳐져 있다.\n");
			printf("계곡을 건너는 다리는 끊어져 있고 그 앞에 안내문이 쓰여있다.\n");
			printf("\n간판 : 현재는 컨셉시연 중이라 이용이 불가능합니다. \n");

			printf("\n광장으로 돌아가기로 했다. \n\n");
			system("pause");
			system("cls");
			break;
		case 105 ://///////////////////////////////////////////////////// skill check(스킬 체크)
			printf("\n[ 스킬 확인 ]\n");
			printf("[q] - 배쉬 (dmg: 150 mp: 20) \n");
			printf("[w] - 피어스 (dmg: 130 mp: 15) \n");
			printf("[e] - 볼링배쉬(광역) (dmg: 120 mp: 30) \n");
			printf("[r] - 파이널 스트라이크 (dmg: 300 mp: 50) \n");
			printf("1번 아이템 - 체력포션 %d\n", one_item_num);
			printf("2번 아이템 - 마나포션 %d\n", two_item_num);
			system("pause");
			system("cls");
			break;
		///////////////////////////////////////////////////////////////// 종료 및 에러 핸들링
		case 120 ://///////////////////////////////////////////////////// end game(게임 종료 트리거)
			printf("\n종료 키를 누르셨습니다. 진짜로 종료하시겠습니까?\n");
			printf("(y/n) : ");
			scanf("%c", &input_key);

			if (input_key == 'y'){
				input_key = 'x';				
			}
			else {
				input_key = 0;
			}
			break;
		default://///////////////////////////////////////////////////// error handling(기타 키입력)
			system("cls");
			printf("키설정이 되지 않았습니다. 다시 입력해주세요.\n");
			printf("입력한 키 = %d\n", input_key);
			system("pause");
			break;
		}
		


	}
	printf("\n게임을 종료합니다.\n");
	system("pause");
}

// 새벽 감성 돋아서 하고 내일 수업시간때 또 내가 한 뻘짓 보며 후회할득...