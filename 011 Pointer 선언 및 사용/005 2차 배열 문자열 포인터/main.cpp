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


// 과제에ㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔ
/*
	월드컵 우승.... 인정할 수 없다..

	본인의 리그를 다시한번 만들기
	char *pstr[4] = {};

	팀 16개, 랜덤 배정

	1라운드 [] [] [] [] [] [] [] []		char* pQuarterFinal[4]
	2라운드   []    []   []    []			char* SemiFinal[2]
	3라운드       []       []				char* Final[2]
	결승              []					char* pWinner
*/