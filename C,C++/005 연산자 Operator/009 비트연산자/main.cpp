/*
	��Ʈ������
	& | >> <<

	- ��Ʈ ���� ������
	- 2���� (Binary) ������
	*/

#include <stdio.h>

void main(){
	int A = 1;									// 0001
	int B = 2;									// 0010

	int C = 0;									// 0000

	C = A & B;									// 0000 -> should be zero
	printf("c = %d\n", C);

	C = A | B;									// 0011 -> 3
	printf("c = %d\n", C);

	C = A << 2;								// shift operator : �ڸ����� �о� �ش� 0100
	C = A * 8;
	printf("c = %d\n", C);					// Var << (num of shift)

	C = C >> 2;								//  0001
	C = C / 2;
	printf("c = %d\n", C);
}


/*
 10���� -> printf ("%d");
 8���� -> %o
 16���� -> %x
 2���� -> �츮�� ������ �����

 2������ �Է� : __ __ __ __ 4bit
 (*8 *4 *2 *1 sum = ?)
 10������ ��ȯ�Ͽ� ��� = __

 10������ �Է� : __ (15���� ����)
 2������ ��ȯ = __
 */

