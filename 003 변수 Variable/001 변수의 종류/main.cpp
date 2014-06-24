/*
	변수 Variable
	- 변할 수 있는 수
	- 상수, 변수를 담을수 있는 공간 (방...?!)
	- 변수마다 다른 크기를 갖는다. 

					C++ Data Types Ranges

					용도									Typical Bit width		Typical Range
	int				정수									4 bytes					-2147483648 to 2147483647
	char			문자									1 byte					-128 to 127 or 0 to 255(whine compiled by using /j)
	float			실수									4 bytes					+/- 3.4e +/- 38 (~7 digits)
	double		실수(더 큰 범위)					8 bytes					+/- 1.7e +/- 308 (~15 digits)

	ppt 혹은 이미지 스크린 샷 해서 과제 폴더
*/

#include <stdio.h>
int main(){
	// char -128 ~ 127
	// unsigned char : 0~255
	// Variable type		Name			Value
	char						num				= 127;
	printf("num = %d\n", num);
	
	// int : -2147483648 to 2147483647
	// unsigned int : 4294967295...?
	int							num2			= -2200000000;		// this will print out weird number 
																				// because input number is out of range for the datatype
	printf("num2 = %d\n", num2);
	// 범위를 벗어나도 컴파일에러가 안나고, 이상한 오류를 낼수 있다.
	// 따라서 데이타 범위를 용도에 맞게 이용해야 한다.

	//unsigned
	unsigned char unum = 130;
	printf("unum = %d\n", unum);

	// You can use unsigned because it is int type
	unsigned short ushort = 114000;
	
	// unsigned를 표현하기 위해 %u를 이용해야 한다.
	unsigned int unum2 = 4100000000;
	printf("unum2 = %u\n", unum2);

	// unsigned type DOES NOT support float or double.
	// it DOES support int and char.

	// float does not support unsigned type
	// unsigned float ufloat = 2100000;
	// double does not support unsigned type either
	//	unsigned double udouble = 210000;

	return 0;
}