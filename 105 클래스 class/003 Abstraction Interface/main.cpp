#include "object.h"

/*
	Main
*/

void main(){
	Object enemy = Object();
	enemy.show();
}

/*
	과제 ]] 파일 분리 후 함수 몇가지 만들기
	setPos( float x, float y ); // 절대값을 집어넣는 것
	MovePos( float x, float y); // 현재 위치로 받은 좌표 이동
	
	// 추가내용
	CalcDistance( POINT other ) // target까지와의 거리
	ShowDistance() // 멤버 변수가 하나 더 있어야 한다
	CalcAngle // 적과의 각도구하기
*/