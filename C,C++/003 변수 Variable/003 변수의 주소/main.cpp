/*
	변수의 주소
	- int 4 bytes	-> 메모리상의 4 bytes 를 해당 변수에 할당
	- 주소연산자	-> & Ampersand
*/


#include <stdio.h>
void main(){
	// When variable declared, it should be initialized
	// 초기화를 해주는 습관을 가지도록 하자
	char cA = 0;
	
	cA = 16;

	printf("cA = %d\n", cA);

	// 현재 컴퓨터의 주소방식은 아직은 32bit을 이용하고 있다.
	// Hexa Decimal을 이용하므로 %x를 이용한다. 
	//그러나 정확하게 나오지 않으므로 %p를 이용하도록 한다.
	printf("cA's memory address = %p \n", &cA);
}