/*
	constant, literal (constant character)
		- cannot be changed

	constant number			integer					1, -2, 0
							real number				3.14, 9.8
	constant character		a character				'a', 'b'
							String					"Worldcup"
*/

#include <stdio.h>

void main(){
	// print 9 + 14 = ? using printf function
	/*int a = 9;
	int b = 14;
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c);*/

	// 1. ������ ��� (integer constant) (%d) 4 byte
	printf("%d + %d = %d\n", 9, 14, 9+14);

	// 2. �Ǽ��� ��� (real number constant) (%f) float = 4 byte, double = 8byte
	// %f�� ����ϸ� �Ǽ��� ǥ���� ����. %.2f �� ��� �Ҽ��� ��°�ڸ�����
	// �Ҽ��� ���� ���ڸ� �̿��Ҷ��� �ڿ� f�� �ٿ��ֵ��� �Ѵ�.
	printf("%.2f + %.2f = %.2f\n", 6.23f, 7.21f, 6.23f - 7.21f);

	// 3. ���� ������ ��� (A character constant) (%c) 1 byte
	// 'a' 'l' 'g' 'e' 'r' 'i' 'a'
	printf("%c%c%c%c%c%c%c %d : %d\n", 'A', 'l', 'g', 'e', 'r', 'i', 'a', 4, 2);

	// 4. ���ڿ� (String) (%s) n+1 byte
	// "Belgium" 
	printf("%s %d %s %d %s \n", "Belgium", 4, "vs", 1, "Korea");
}