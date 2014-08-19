/*
	����� ������ ũ�� (size of constant)
	- sizeof : �������� ũ�⸦ byte�� ��ȯ (return the size of data as byte)
	- 1byte = 8bit
*/

#include <stdio.h> // it is a library!!

int main(){
	//1. ������ ũ�� �˾ƺ���
	printf("���� %d�� ũ�� = %d\n",51, sizeof(51));

	//2. �Ǽ��� ũ�� �˾ƺ��� (3.14)
	printf("�Ǽ� %f�� ũ�� = %d\n", 3.14, sizeof(3.14));  // double
	printf("�Ǽ� %f�� ũ�� = %d\n", 3.14f, sizeof(3.14f)); // float

	//3. ���� ������ ũ�� ('i')
	printf("���Ϲ��� %c�� ũ�� = %d\n", 'i', sizeof('i'));

	//4. ���ڿ��� ũ�� ("ai")
	//���ڿ��� ������ '\0'�� ����ְ� �̰��� Null���ڸ� ����
	//����ִ� ���ڷ� ���ڿ��� ���̶�� �� ǥ���Ѵ�ĭ��.
	printf("���ڿ� %s�� ũ�� = %d\n", "ai", sizeof("ai")); 

	return 0;
}