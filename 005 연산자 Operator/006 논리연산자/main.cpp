/*
	�� ������
	A && B ���� ��� ���̸� ��, ���߿� �ϳ��� �����̸� ����
	A || B ���� �� �ϳ��� ���̸� ��
	!���� ������! ������!
*/

#include <stdio.h>

int main(){
	// ** initializing **
	int A = 4;				
	bool b = false;				// 0�� �ƴϸ� ������ ��True
										// 0�̸� ��false
	b = A && 0 < 3;
	printf("result = %d\n", b);

	b = 4;
	printf("result = %d\n", b);

	b = A || false;
	printf("result = %d\n", b); // result should be ��Ʈ��
	
	b = ((float)A - 3.999f) || false;
	printf("result = %d\n", b); // in my opinion, result should be ��Ʈ��

	b = !b;
	printf("result = %d\n", b); // in my opinion, result should be ��false

}