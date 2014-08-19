/*
	���� Variable
	- ���� �� �ִ� ��
	- ���, ������ ������ �ִ� ���� (��...?!)
	- �������� �ٸ� ũ�⸦ ���´�. 

					C++ Data Types Ranges

					�뵵									Typical Bit width		Typical Range
	int				����									4 bytes					-2147483648 to 2147483647
	char			����									1 byte					-128 to 127 or 0 to 255(whine compiled by using /j)
	float			�Ǽ�									4 bytes					+/- 3.4e +/- 38 (~7 digits)
	double		�Ǽ�(�� ū ����)					8 bytes					+/- 1.7e +/- 308 (~15 digits)

	ppt Ȥ�� �̹��� ��ũ�� �� �ؼ� ���� ����
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
	// ������ ����� �����Ͽ����� �ȳ���, �̻��� ������ ���� �ִ�.
	// ���� ����Ÿ ������ �뵵�� �°� �̿��ؾ� �Ѵ�.

	//unsigned
	unsigned char unum = 130;
	printf("unum = %d\n", unum);

	// You can use unsigned because it is int type
	unsigned short ushort = 114000;
	
	// unsigned�� ǥ���ϱ� ���� %u�� �̿��ؾ� �Ѵ�.
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