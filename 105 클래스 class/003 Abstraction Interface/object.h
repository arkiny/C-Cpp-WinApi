/*
	@author		Heedong Arkiny Lee
	@date		07312014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Abstraction ( �߻�ȭ )
	- Interface Ŭ������ ����ڰ��� ��ȣ�ۿ�

	���� ]] ���� �и� �� �Լ� ��� �����
	setPos( float x, float y ); // ���밪�� ����ִ� ��
	MovePos( float x, float y); // ���� ��ġ�� ���� ��ǥ �̵�

	// �߰�����
	CalcDistance( POINT other ) // target�������� �Ÿ�
	ShowDistance() // ��� ������ �ϳ� �� �־�� �Ѵ�
	CalcAngle // ������ �������ϱ�
*/

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

typedef struct Point{
	// �ƿ� ���⼭ �ʱ�ȭ�ع����� �ٽ� ���� �ʿ䰡 �������� ����
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
	/*POINT pos = {};*/ //�ֱٹ����� c++���� �̰� �����ϰ� �ٲ�
	POINT pos;
};

#endif