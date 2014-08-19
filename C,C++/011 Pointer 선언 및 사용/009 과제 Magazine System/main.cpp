/*
	@author		Heedong Arkiny Lee
	@date		07152014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	과제 ]]
		탄창 시스템.. (Magazine System)
		1. rifle	30					pfunc = rifle
		2. pistol	7					pfunc = pistol
		3. knife	infinite			...
		4. grenade	2					...

		r. reload

		발사버튼.. Spacebar				pfunc = fire

		현재 선택한 무기의 총알이 소모

		함수 포인터 활용
		tip] 탄알은 static or 배열 활용

		---------------------------------------------

		Function Pointer 및 static 옵션, MVC 패턴에 대해서 고찰해봄...
		현재 이 프로그램에서는 static이 굳이 함수 안에 있을 필요가 없이
		공통 변수라고 생각되어 최상위 변수로 끌어냈고....

		물론 필요할수도 있겠지만...

		주석은 딱히 달껀덕지가 없고, 대부분 수업시간에 배운 것들이라 달지 않습니다.
		시간이 많이 걸린 이유는 MVC 패턴 따라서 Flowchart 그려보고

		그게 생각보다 너무 복잡해져서 간단하게 만드느라...
		Flow차트는 참조용으로 같이 올림...
*/

#include <stdio.h>	// printf()
#include <conio.h>	// _getch()

// dataset
// 고정 변수 수열을 이용해 데이타 저장
static int ammo_stat[] = { 30, 9, 99, 2 };	// rifle , pistol , knife , granade
static int magazine[] = { 3, 2 };			// rifle , pistol

// prototype

// Main module
// 구연하고자 하는 모듈중 최상위 함수
void system_window_module();
void print_signature();

// model
// 실질적으로 게임연산이 들어가는 함수들
void rifle();
void pistol();
void knife();
void grenade();
void reload(int current_weapon);

// control
// 유저의 키컨트롤을 담당하는 함수
char keyinput();

// view
// 화면 출력을 담당하는 함수들
void interfaceRender_upside();
void effect_swap(int weapon);
void effect_reload_no_mag();
void effect_can_not_reload();
void effect_reload_complete(int magazine, int ammo);
void effect_need_reload();
void effect_no_grenade();

// main
void main(){
	print_signature();
	system_window_module();
} // main()

// 시스템 윈도우 모듈
// 게임내에서 시스템 및 효과음 자막을 출력하는 창
// 각종 자막 이펙트를 매니징 하는 역할도 한다...
// 실은 MVC 패턴 디자인 공부하면서 하다가 망함..
void system_window_module(){
	// 창구현에 필요한 함수들 초기화
	char key = -1;
	// 기본 무기는 라이플
	// 원래는 게임 엔진 부분에서 따로 다뤄진걸 받아야 하지만
	// 여기선 function pointer 및 static 교육 목적이므로 그냥 씀
	// default weapon = rifle
	void(*p_func)() = rifle;	// 기본 함수는 rifle
	int current_weapon = 0;		// 현재 무기 식별자
	int flag = 0;				// 게임 종료를 위한 플래그 변수

	// 인터페이스 출력
	interfaceRender_upside();

	
	// 이부분은 컨트롤로 넣어야 할까?
	while (flag != 1){
		key = keyinput();
		switch (key)
		{
		case '1':
			p_func = rifle;				// 함수 포인터에 rifle 함수 장전!
			current_weapon = 0;			// 현재 무기 식별자 0
			effect_swap(0);				// 무기식별 변수를 이용해 변환 이펙트(이하 생략)
			break;
		case '2':
			p_func = pistol;			// 함수 포인터에 pistol 함수 장전!
			current_weapon = 1;			// 현재 무기 식별자 1(이하 생략)
			effect_swap(1);				
			break;
		case '3':
			p_func = knife;				// 함수 포인터 p_func에 knife 함수 장전!
			current_weapon = 2;
			effect_swap(2);
			break;
		case '4':
			p_func = grenade;			// 함수 포인터에 grenade 함수 장전!
			current_weapon = 3;
			effect_swap(3);
			break;
		case ' ':
			p_func();					// 장전된 함수 발싸! 
			break;
		case 'r':
			reload(current_weapon);		// 현재 무기식별 변수를 이용해 장전 실시
			break;
		case 'x':
			flag = 1;					// 게임 종료를 위한 케이스
			break;
		default:
			break;
		}// end switch()
	}// end while()
}// system_window_module()

// 서명 출력
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07152014 과제\n");
	printf("============================================================\n");
}

////////////////////////////////////////////////////////////////////// Model
// 재장전시 프로세스를 포함하는 펑션
// 장전 및 장전시 출력되는 효과를 담당한다
// @param int current_weapon 현재 무기 식별용 변수
void reload(int current_weapon){
	if (current_weapon == 0){	// 현재 무기가 0(라이플) 일때
		if (magazine[0] > 0){	// 현재 총알 수 확인
			ammo_stat[0] = 30;	// 재장전
			magazine[0] -= 1;	// 탄창숫자 줄임
			effect_reload_complete(magazine[0], ammo_stat[0]);	// 재장전시 이펙트 출력
		}
		else {
			effect_reload_no_mag();	// 탄창이 없을시의 이펙트 출력
		} // end inner if
	}
	else if (current_weapon == 1){	// 현재 무기가 1(권총)일때
		if (magazine[1] > 0){		// 현재 총알 수 확인
			ammo_stat[1] = 9;		// 재장전
			magazine[1] -= 1;		// 탄창숫자 감소
			effect_reload_complete(ammo_stat[1], magazine[1]);	// 재장전 이펙트 출력
		}
		else {
			effect_reload_no_mag();	// 탄창 없을시 이펙트 출력
		} // end inner if
	}
	else {
		effect_can_not_reload();	// 재장전이 불가능한 무기를 재장전 할시의 이펙트 출력
	}// end outer iff
} // reload()

// M4A1 공격시 효과와 이펙트 담당
// 잔탄 숫자 감소
// 관련 효과 출력
void rifle(){
	if (ammo_stat[0] > 0){ // 잔탄이 0보다 많을때
		ammo_stat[0]--;	// 잔탄 숫자감소
		printf("효과음 : (라이플 쏘는 소리) 발싸 퓽퓽\n"); // 효과 출력
		printf("System : 라이플 잔탄 - %d\n", ammo_stat[0]);	// 잔탄 감소 출력
	}
	else{
		effect_need_reload();	// 재장전 필요시 출력
	} // end if
} // rifle()

// Pistol 공격시 효과와 이펙트 담당
// 잔탄 숫자 감소
// 관련 효과 출력
void pistol(){
	if (ammo_stat[1] > 0){ // 잔탄이 0보다 많을때
		ammo_stat[1]--; // 잔탄 숫자 감소
		printf("효과음 : (권총 쏘는 소리) 발싸 빵야빵야\n"); // 효과 출력
		printf("System : 권총 잔탄 - %d\n", ammo_stat[1]);  // 잔탄 감소 출력
	}
	else {
		effect_need_reload(); // 재장전 필요시 출력
	} // end if
}  // pistol()

// 대검은 무제한 탄창이므로 간단하게 출력만 한다.
void knife(){	
	printf("효과음 : (휘두르는 소리) 쉭쉭\n");	
}

// 수류탄 함수가 콜됬을시 효과와 이펙트 담당
void grenade(){
	if (ammo_stat[3] > 0){
		ammo_stat[3]--;	// 수류탄 잔탄 숫자 감소
		printf("Player : 전방 수류탄!\n");		// 효과 출력
		printf("System : 수류탄 잔탄 - %d\n", ammo_stat[3]); // 잔탄 감소 출력
	}
	else {
		effect_no_grenade();  // 수류탄이 없을때 출력
	} // end if()
}  // grenade()


////////////////////////////////////////////////////////////////////// View
// 수류탄이 없을때 출력
// 수류탄은 기본적으로 재장전이 없다
void effect_no_grenade(){
	printf("효과음 : (헛손질 하는 소리)");
	printf("Player : 수류탄이 부족하다.");
}

// 재장전을 실시할때 출력할
void effect_need_reload(){
	printf("효과음 : (방아쇠가 가볍게 당겨지는 소리) 틱틱\n");
	printf("System : 재장전이 필요합니다.\n");
} // effect_need_reload()

// 화면 인터페이스 제일 윗면을 출력하기 위한 부분
void interfaceRender_upside(){
	printf("1. M4A1 | 2. Desert Eagle | 3. Knife | 4. Grenade\n");
	printf("r. reload | x. module stop\n\n");
	printf("System Msg ↓\n");
	printf("────────────────────────────┐\n");
} //interfaceRender_upside()

// 각 무기를 꺼낼때 이펙트를 표현
// @param int weapon 현재 무기 식별용 변수
void effect_swap(int weapon){
	switch (weapon)
	{
	case 0:
		printf("\nM4A1을 꺼내들었습니다\n");
		break;
	case 1:
		printf("\nDersert Eagle을 꺼내들었습니다\n");
		break;
	case 2:
		printf("\nM50 대검을 꺼내들었습니다\n");
		break;
	case 3:
		printf("\n수류탄을 꺼내들었습니다.\n");
		break;
	default:
		break;
	} // end switch
} // effect_swap()

// 탄창이 부족할때 이펙트를 표현
void effect_reload_no_mag(){
	printf("Player : 탄창이 부족해..\n");
} // effect_reload_no_mag()

// 재장전시 표현
void effect_reload_complete(int magazine, int ammo){
	printf("효과음 : (탄창을 갈아 끼우는 소리) 철컥\n");
	printf("System : 재장전 완료, 남은 탄창 : %d, 잔탄 : %d\n", magazine, ammo);
} // effect_reload_complete()

// 수류탄 같이 재장전이 불가능할때의 표현
void effect_can_not_reload(){
	printf("System : 이 장비는 재장전이 불가능합니다.\n");
} // effect_can_not_reload()


////////////////////////////////////////////////////////////////////// Control
// 유저가 키를 입력했을때 키를 분석하고 char로 리턴
// @return char input 플레이어가 입력한 캐릭터
char keyinput(){
	char input = _getch();
	if (input == 0) {
		input = _getch();
	}
	return input;
} // input;