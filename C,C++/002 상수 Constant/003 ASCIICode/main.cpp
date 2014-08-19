/*
	Ascii Code
	-Ű������� ǥ���Ǵ� ��� ���ڵ��� ����ǥ
	(Number Table of all characters in keyboard)
	-16���� ǥ�� : 0x??
	Ascii �ڵ� ���� 
	http://www.cisco.com/c/en/us/td/docs/ios/12_2/configfun/command/reference/ffun_r/frf019.pdf
*/

#include <stdio.h>
int main()
{
	printf("%c�� AsciiCode = %x\n", 'a', 'a');
	printf("%c�� AsciiCode = %x\n", 'A', 'A');
	printf("%c�� AsciiCode = %x\n", '1', '1');
	printf("%c�� AsciiCode = %x\n", 'b', 'b');
	printf("%x = %c\n", 0x63, 0x63);

	//'S' 'G' 'A' 'P' -> �ƽ�Ű�ڵ�
	printf("%c %c %c %c \n", 'S', 'G', 'A', 'P');
	printf("%x %x %x %x \n", 'S', 'G', 'A', 'P');
	
	// esc, enter, spacebar
	printf("%s %s %s\n", "esc", "enter", "space");
	printf("%c %c %c\n", 0x1B, 0x0A, 0x20);

	return 0;
}
