/*
	2차 배열 문자열 포인터
*/

#include <stdio.h> // printf()
int main()
{
	char *pstr[4] = {};
	
	char Brazil[] = "Brazil";
	char Holland[] = "Holland";
	char Germany[] = "Germany";
	char Argentina[] = "Argentina";

	pstr[0] = Brazil;
	pstr[1] = Holland;
	pstr[2] = Germany;
	pstr[3] = Argentina;

	printf("%s\n", pstr[1]);

	char USA[] = "USA";

	pstr[1] = USA;

	printf("%s\n", pstr[1]);

	return 0;
}


