/*
	Ascii Code
	-키보드상의 표현되는 모든 문자들의 숫자표
	(Number Table of all characters in keyboard)
	-16진수 표현 : 0x??
	Ascii 코드 참조 
	http://www.cisco.com/c/en/us/td/docs/ios/12_2/configfun/command/reference/ffun_r/frf019.pdf
*/

#include <stdio.h>
int main()
{
	printf("%c의 AsciiCode = %x\n", 'a', 'a');
	printf("%c의 AsciiCode = %x\n", 'A', 'A');
	printf("%c의 AsciiCode = %x\n", '1', '1');
	printf("%c의 AsciiCode = %x\n", 'b', 'b');
	printf("%x = %c\n", 0x63, 0x63);

	//'S' 'G' 'A' 'P' -> 아스키코드
	printf("%c %c %c %c \n", 'S', 'G', 'A', 'P');
	printf("%x %x %x %x \n", 'S', 'G', 'A', 'P');
	
	// esc, enter, spacebar
	printf("%s %s %s\n", "esc", "enter", "space");
	printf("%c %c %c\n", 0x1B, 0x0A, 0x20);

	return 0;
}
