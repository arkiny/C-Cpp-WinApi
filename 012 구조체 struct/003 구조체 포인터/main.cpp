/*
	구조체 포인터
*/

#include <stdio.h> // printf()

struct POINT{
	float fX;
	float fY;

	void show(){
		printf("--- show point ---\n");
		printf("X = %.2f ,  Y = %.2f\n", fX, fY);
	}

	POINT plus(POINT input){
		POINT ret = { fX + input.fX, fY + input.fY };
		return ret;
	}
};

POINT PlusPoint(POINT p1, POINT p2);

void main(){
	POINT p1 = { 1.0f, 2.0f };
	POINT p2 = { 5.0f, 6.0f };
	POINT p3 = {};

	// p3 = p1 + p2 로 해주고 싶다.
	p3 = { (p1.fX + p2.fX), (p1.fY + p2.fY) };
	p3.show();

	p3 = PlusPoint(p1, p2);
	p3 = p1.plus(p2);
}

POINT PlusPoint(POINT p1, POINT p2){
	POINT ret = { p1.fX + p2.fX, p1.fY + p2.fY };
	return ret;
}