/*
	do while ]
	AsciiCode ��±�

	'!' ���� ������ ����

	�Է� : ����
	��� : �ش� Ascii Code ���
*/
#include <stdio.h>
void main(){
	char in_char = 0;
	do{
		printf("�Է� : ");
		fflush(stdin);
		scanf("%c", &in_char);
		printf("��� : %x \n", in_char);
	} while (in_char != '!');
}