/*
	@author		Heedong Arkiny Lee
	@date		07312014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Abstraction ( 추상화 )
	- Interface 클래스와 사용자간의 상호작용

	과제 ]] 파일 분리 후 함수 몇가지 만들기
	setPos( float x, float y ); // 절대값을 집어넣는 것
	MovePos( float x, float y); // 현재 위치로 받은 좌표 이동

	// 추가내용
	CalcDistance( POINT other ) // target까지와의 거리
	ShowDistance() // 멤버 변수가 하나 더 있어야 한다
	CalcAngle // 적과의 각도구하기
*/

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

typedef struct Point{
	// 아예 여기서 초기화해버리면 다시 만질 필요가 없어져서 편함
	float fx = 0.0f;
	float fy = 0.0f;
}POINT, *LPPOINT;

class Object
{
public:
	// constructor
	Object();
	Object(float, float);

	//destructor
	~Object();

	// print out position
	void show();		

	// set object's position
	// @param float x coordinate
	// @param float y coordinate
	void setPos(float, float); 
	// move object's position depends on its original position
	// @param float x vertical move
	// @param float y horizontal move
	void movePos(float, float);

	// Calculate distance to other point
	// @param POINT other point
	// @return float distance to the point
	float calcDistance(POINT);

	// Calculate and show distance between other point
	// @param POINT other point
	void showDistance(POINT);

	// Calculate Angle to other point
	// @param POINT other point
	// @return float Angle
	float calcAngle(POINT);

	// Calculate and show Angle to other point
	// @param POINT other point
	void showAngle(POINT);

	// return object's current position
	POINT getPos();

private:
	/*POINT pos = {};*/ //최근버전의 c++에서 이게 가능하게 바뀜
	POINT pos;
};

#endif