/*
	Struct
		- 배열과 차이점
			배열: 같은 데이터 타입을 사용
			구조체 : 다른 데이터 타입도 사용 가능.	
*/

#include <stdio.h>

// 구조체 이름
struct profile{
	// 만들면서 초기화 
	unsigned int nAge = 0;
	unsigned int nPhone = 0;
	float fWeight = 0.0f;
	// ...
};

void main(){
	// 1. 구조체 선언과 사용
	profile ljc;
	ljc.nAge = 23;
	ljc.nPhone = 557774740;
	ljc.fWeight = 68.5;

	//ljc의 내부 데이터를 출력하기
	printf("나이 : %d\n", ljc.nAge);
	printf("전화번호 : %10d\n", ljc.nPhone);
	printf("몸무게 : %.2f\n", ljc.fWeight);

	//2. ljc 구조체 크기
	printf("크기 = %d\n", sizeof(ljc));

	//3. 구조체 내부 변수들의 주소는 연속적인가?
	printf("nAge 주소 = %p\n", &ljc.nAge);
	printf("nPhone 주소 = %p\n", &ljc.nPhone);
	printf("fWeight 주소 = %p\n", &ljc.fWeight);
	// 그렇다 연속적이다.

	//4. 구조체 변수중 시작 주소를 포인터에 전달

	unsigned int* pf = &ljc.nAge;
	
	printf("%d\n", pf[0]);
	printf("%d\n", pf[1]);
	printf("%f\n", *(float*)(pf+2));	
}