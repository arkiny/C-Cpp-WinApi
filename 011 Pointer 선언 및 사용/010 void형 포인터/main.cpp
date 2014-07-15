/*
	void형 포인터
*/

#include <stdio.h>

void main(){
	char a = 3;
	int b = 7;
	float c = 7.89f;
	double d = -14.3;

	void* pa = &a;
	void* pb = &b;
	void* pd = &d;

	// 최근에 추가된 변수
	// 압뒤 전후 사항 추론해서 원하는 형으로 잡아주게 됨
	// 맹신해서 쓰기도 그런 것 (추상화)
	// 우리가 할때는 후반부 정도에나 쓰고 원래대로 쓰도록 함
	auto aa = &a;
	auto ab = &b;
	auto ac = &c;
	auto ad = &d;

	printf("%d\n", sizeof(pa)); // 사이즈가 4가 나옴
	printf("%d\n", sizeof(pd)); // 역시 사이즈가 4가 나옴

	printf("pa값 : %d\n", *((char*)pa)); // 3이 나옴
	printf("pd값 : %f\n", *((double*)pd)); // -14.3이 나옴

	
	printf("pd값 : %d\n", *aa); //3이 나옴
	printf("pd값 : %d\n", *ab); //ab이 나옴

}