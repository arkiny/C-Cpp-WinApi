/*
	������ �ּ�
	- int 4 bytes	-> �޸𸮻��� 4 bytes �� �ش� ������ �Ҵ�
	- �ּҿ�����	-> & Ampersand
*/


#include <stdio.h>
void main(){
	// When variable declared, it should be initialized
	// �ʱ�ȭ�� ���ִ� ������ �������� ����
	char cA = 0;
	
	cA = 16;

	printf("cA = %d\n", cA);

	// ���� ��ǻ���� �ּҹ���� ������ 32bit�� �̿��ϰ� �ִ�.
	// Hexa Decimal�� �̿��ϹǷ� %x�� �̿��Ѵ�. 
	//�׷��� ��Ȯ�ϰ� ������ �����Ƿ� %p�� �̿��ϵ��� �Ѵ�.
	printf("cA's memory address = %p \n", &cA);
}