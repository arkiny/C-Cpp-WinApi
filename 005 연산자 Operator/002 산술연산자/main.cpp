/*
	��� ������
	+ plus, addition
	- minus, subtraction
	* multiply
	/ division
	% modular
*/

#include <stdio.h>

void main()
{
	int k1 = 15;
	int k2 = 7;
	// +
	printf("+ = %d\n", k1 + k2);
	// -
	printf("- = %d\n", k1 - k2);
	// *
	printf("* = %d\n", k1 * k2);
	// /
	printf("/ = %d\n", k1 / k2);
	// %
	printf("%% = %d\n", k1 % k2);

	// what can we do using modular operator?
	// ��ⷯ ������ ���� ������ �Ҽ� ������?
	printf("\n ��ⷯ ������ ���� ������ �Ҽ� ������? \n");
	printf(" 3 %% 1 = %d\n", 3 % 1);
	printf(" 3 %% 2 = %d\n", 3 % 2);
	printf(" 3 %% 3 = %d\n", 3 % 3);
	printf(" 3 %% 4 = %d\n", 3 % 4);

	printf(" 10 %% 6 = %d\n", 10 % 6);
	printf(" 11 %% 6 = %d\n", 11 % 6);
	printf(" 12 %% 6 = %d\n", 12 % 6);
	printf(" 13 %% 6 = %d\n", 13 % 6);
	
	// ���� ǥ����, ����ó��(ex �ֻ���), 
	// �Ŀ� �̰����� �ֻ��� ȿ���� ���� ���� (Ȯ��, ����Ȯ��)
	printf(" 10 %% 12 = %d\n", 10 % 12);
	printf(" 11 %% 12 = %d\n", 11 % 12);
	printf(" 12 %% 12 = %d\n", 12 % 12);
	printf(" 13 %% 12 = %d\n", 13 % 12);
}
