/*
	typedef (typed define)
	- Re-define standard data type
	- 기존의 데이터형을 재정의 한다.
*/

#include <stdio.h> // printf()
// 1.
// unsinged int대신 UNIT를 쓸수가 있음
// 아무거나 쓸수 있는게 아니라 기존의 데이터만 재정의해줄수 있다.
typedef unsigned int UINT;

// 2.
// #define 은 데이터형이 아니라도 재정의할수 있다.
// kkkk 는 이제 unsigned int 인겁니다.
// 제 맘대로 할수 있는 겁니다.
#define kkkk unsigned int

// 3.
// #define으로 상수를 정의하려면, const 형 상수로 정의하는게 좋다.
#define PI 3.141592
const float fPI = 3.141592f;

// 이렇게 쓰면 point와 POINT 둘다 쓸수가 있게 되는겨...
// 이제야 알았네....
typedef struct point{

}POINT, pOiNT; // 복수로 정의도 가능

// 재정의 한것을 재정의 가능
typedef POINT pOINT;


int main(){
	// 같은 구조체일까 다른 구조체일까?
	// 같은 구조체..
	point p1;
	POINT p2;
	pOiNT p3;
	pOINT p4;

	kkkk n = 1000;
	float f = fPI;

	return 0;
}