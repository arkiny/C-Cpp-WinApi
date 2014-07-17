/*
	@author		Heedong Arkiny Lee
	@date		07172014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	과제 ] 두점사이 거리구하기

	struct POINT { x, y }

	거리 = calcDistance (&p1, &p2);

	POINT tower
	POINT enemy
	BOOL = tower.isinRange(&enemy) ;
	-> true "발싸!"
	-> false "대기"


	[[ 두점사이 거리공식 활용 ]]

	#include <math.h>
	pow( ,n) -> n제곱승
	sqrt() -> 제곱근 (루트 연산)
*/


#include <stdio.h>	// printf()
#include <math.h>	// sqrt(), pow()
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()
#include <conio.h>	// _getch()

// Contant define
const int SIGHT_RANGE = 10;				//감시카메라 감시범위

// 좌표가 양수로만 이루어졌다고 가정할 때?
// 혹은 음수로 이루어진 좌표가 있다고 가정할때
// 음수는 없을수 없으므로 일단 음수가 있을때를 가정하면
// x1 = 1, x2 = 7
// x1 = -1, x2 = 7
// x1 = 1, x2 = -7
// x1 = -1, x2 = -7
// 이 모든 경우의 수를 비교하면
// 부호가 같을 경우는 두수를 뺀수,
// 부호가 다를 경우는 두수를 합친다.
// 무조건 작은수를 뒤로 보내서 빼면 될득
typedef struct POINT{
	float fX; // x축
	float fY; // y축

	// target과 자신과 거리를 구해서 target이 자신의 시야 안에 있는지
	// 확인 하는 함수
	// @param point *target 타겟이 될 point 점
	bool isinRange(POINT *target){
		// 두 점간의 거리가(피타고라스 정리 이용) 시야 거리보다 작은가? 작으면 true
		// 작지 않으면 false;
		return  this->distanceTo(target) <= SIGHT_RANGE; 
	}// is in Range

	// target과 자신과의 거리를 구해서 돌려주는 함수
	// @param point *target 거리측정을 할 target
	float distanceTo(POINT *target){
		float a, b;
		// x축 거리 계산
		if (fX == target->fX){		// 양쪽 숫자가 같을때 0
			a = 0;
		}
		else if (fX < target->fX){	// this.fX가 작을시에 타겟의 fX에서 this.fX를 뺌
			a = target->fX - fX;
		}
		else {						// 반대일 경우
			a = fX - target->fX;
		}// if()

		// y축 거리 계산
		if (fY == target->fY){		// 양쪽 숫자가 같을 때 0
			b = 0;
		}
		else if (fY < target->fY){	// this.fY가 작을시에 타겟의 fY에서 fY를 뺌
			b = target->fY - fY;
		}
		else {						// 반대의 경우
			b = fY - target->fY;
		} //if()

		// 두 점끼리의 거리를 피타고라스의 정리법칙을 이용하여 계산
		// sqrt(x축에서 두점사이의 거리^2 + y축에서의 두점 사이의 거리^2)
		return  sqrt(pow(a, 2) + pow(b, 2));
	}

	// 구조체가 가진 좌표를 인쇄하는 helper method
	void printout(){
		printf("(%.2f, %.2f)\n", fX, fY);
	}
}point;

// prototype
float calcDistance(point *p1, point *p2);
void watch_Vision();
char keyinput();

// main
void main(){
	// seeding
	srand(time(NULL));	
	// for exit flag
	char exit_flag = 0;
	
	while (exit_flag != 'x' && exit_flag != 'X'){ // x키를 누르면 모듈 종료
		watch_Vision();
		exit_flag = keyinput();
		system("cls");
	} // while
} // main

// Test를 위한 함수
// main 함수의 최소화를 위해 이곳에서 실행
void watch_Vision(){
	point watcher = { rand() % 20, rand() % 20 };	// 감시카메라 위치
	point thief = { rand() % 20, rand() % 20 };		// 도둑놈 위치
	float dist = calcDistance(&watcher, &thief);	// 둘간의 거리
	bool alert = watcher.isinRange(&thief);			// 감시카메라는 도둑을 발견했는가?
	
	printf("랜덤으로 두 점을 찍고 두 점사이의 거리를 확인하여,\n");
	printf("도둑이 감시카메라의 시야(거리 10m) 안에 있는지 확인하는 함수입니다.\n");
	printf("------------------------------------------------------------\n");
	printf("감시카메라 위치 : "); watcher.printout();
	printf("   도둑 위치    : "); thief.printout();	
	printf("  둘간의 거리   :     %.2fm\n", dist);
	printf("\n감시카메라가 발견하였습니까?\n");
	if (alert){
		printf("\a!!!!!!!!!!!!!!!!!!Enemy Insight!!!!!!!!!!!!!!!!!!\n\n");
	}
	else {
		printf("                     All clear!\n\n");
	} // if
	printf("종료하시려면 x를, 계속 테스트 하시려면 아무키나 눌러주세요.\n");
} // watch_Vision

// 이미 해당 struct 안에 helper method를 만들어 놨기에 한줄로 처리 가능
// 점 좌표 두개를 받아서 거리를 계산하여 float으로 리턴한다
// @param point *p1 비교할 좌표 1
// @param point *p2 비교할 좌표 2
// @return float 둘사이의 거리
float calcDistance(point *p1, point *p2){
	return p1->distanceTo(p2);
} // calcDistance

char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput