#include "object.h"

void Object::show(){
	cout << ">>> Object Class <<<" << endl;
	cout << "posX = " << pos.fx << ", posY = " << pos.fy << endl;
}

Object::Object(){
	cout << ">>> Object Constructed <<<" << endl;
	// �ʱ�ȭ ����� ���������� ������...
	/*pos.fx = 0.0f;
	pos.fy = 0.0f;*/
	//Ȥ��
	//pos = POINT(); // ����ü�� ������ class�̹Ƿ� ������ ������, �Ҹ��ڰ� �ִ�.
}

Object::Object(float x, float y){
	pos.fx = x;
	pos.fy = y;
}

Object::~Object(){
	cout << ">>> Object Destructed <<<" << endl;
}

void Object::setPos(float inputX, float inputY){
	pos.fx = inputX;
	pos.fy = inputY;
}

void Object::movePos(float moveX, float moveY){
	pos.fx += moveX;
	pos.fy += moveY;
}

float Object::calcDistance(POINT &target){
	// sqrt((���� �Ÿ�)^2 + (���ΰŸ�)^2)
	return sqrt(pow((target.fx - pos.fx), 2) + pow((target.fy - pos.fy), 2));
}

void Object::showDistance(POINT &target){
	cout << "Distance to Target= " << this->calcDistance(target) << endl;
}

float Object::calcAngle(POINT &target){
	// tan^-1 (x/y) * (180 / PI)
	return atan2((target.fy - pos.fy), (target.fx - pos.fx)) * (180 / 3.141592);
}

void Object::showAngle(POINT &target){
	cout << "Angle to Target= " << this->calcAngle(target) << " degree"<< endl;
}

POINT Object::getPos(){
	return pos;
}