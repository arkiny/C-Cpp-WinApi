/*
	do while ]
	AsciiCode 출력기

	'!' 문자 나오면 종료

	입력 : 문자
	출력 : 해당 Ascii Code 출력
*/
#include <stdio.h>
void main(){
	char in_char = 0;
	do{
		printf("입력 : ");
		fflush(stdin);
		scanf("%c", &in_char);
		printf("출력 : %x \n", in_char);
	} while (in_char != '!');
}