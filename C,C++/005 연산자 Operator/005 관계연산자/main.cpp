/*
	���� ������
	> < >= <=
	A == B ���� ���� ������ ��, �ƴϸ� ���� (equal, true, else false_
	A != B ���� ���� �ٸ��� ��, �ٸ��� ���� (difference)
*/

#include <stdio.h>

int main()
{
	int A = 0;

	//  datatype bool, 1byte
	// true	= 1;
	// false	= 0;
	bool b = false;															// true(1) or false(0);
	b = A < 3;
	printf("result = %d\n", b);

	// ���� �����ڰ� ���� �����ں��� �켱���Ǹ� �����Ƿ� false
	b = 0 > A--;	
	printf("result = %d\n", b);

	// ��� �Ŀ� ���ϹǷ� false
	b = (3 == A + 3);
	printf("result = %d\n", b);
}