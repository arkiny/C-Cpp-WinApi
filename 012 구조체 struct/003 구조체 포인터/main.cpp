/*
@author		Heedong Arkiny Lee
@date		07162014
@git		https://github.com/arkiny/SGA-Learning-Heedong

구조체 포인터
*/

#include <stdio.h> // printf()

struct POINT{
	float fX; // x축
	float fY; // y축

	void show(){
		printf("--- show point ---\n");
		printf("X = %.2f ,  Y = %.2f\n", fX, fY); // 두자리수까지 출력
	}

	// plus method
	// @param POINT input 계산할 다른 함수
	// @return POINT this.x, this.y와 입력받은 struct의 x축과 y축이 더해진 값
	POINT plus(POINT input){
		POINT ret = { fX + input.fX, fY + input.fY };
		return ret;
	}
};

// prototype
POINT PlusPoint(POINT p1, POINT p2);
POINT Al_PlusPoint(POINT p1, POINT p2);
void print_signature();

// main
void main(){
	// Variable Init
	POINT p1 = { 1.0f, 2.0f };
	POINT p2 = { 5.0f, 6.0f };
	POINT p5 = {};
	POINT p6 = {};
	POINT p7 = {};
	// p3 = p1 + p2 로 해주고 싶다.
	/*p3 = { (p1.fX + p2.fX), (p1.fY + p2.fY) };
	p3.show();*/


	print_signature();
	// 과제 ]]

	/*
	1. p3 = PlusPoint(p1, p2);
	2. p3 = p1.plus(p2);*/
	// 수업시간에 한거라 과제인지 모르고 있다가 지금냄;
	// 원래 값 출력후에, 계산된 값 출력, 원본, 결과 비교
	// 자세한건 각 함수 주석 참조
	printf("\noriginal p5-\n");
	p5.show();
	printf("changed p5-\n");
	p5 = PlusPoint(p1, p2);
	p5.show();

	printf("\noriginal p7-\n");
	p7.show();
	printf("changed p7-\n");
	p7 = Al_PlusPoint(p1, p2);
	p7.show();

	printf("\noriginal p6-\n");
	p6.show();
	printf("changed p6-\n");
	p6 = p1.plus(p2);
	p6.show();
	/////////////////////////////////////////////////
} // main()


// PlusPoint
// @Param POINT p1, 입력받을 첫번째 객체, x축과 y축데이타를 가지고 있다.
// @Param POINT p2, 입력받을 두번째 객체
// @return POINT p1의 x, y 와 p2의 x,y가 각각 더해진 x,y를 가진 POINT를 리턴
POINT PlusPoint(POINT p1, POINT p2){
	POINT ret = { p1.fX + p2.fX, p1.fY + p2.fY }; // 각 POINT의 변수를 가져와서 직접 계산
	return ret;
} // PlusPoint();

// Alternative PlustPoint
// 객체 지향을 이용하여 만드는 방법
// 이미 우리는 Struct안에 비슷한 함수를 가지고 있다?!
POINT Al_PlusPoint(POINT p1, POINT p2){
	return p1.plus(p2); // Struct안의 함수를 그대로 이용해서 리턴
} // PlusPoint();


// 서명 출력
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07162014 과제\n");
	printf("============================================================\n");
}