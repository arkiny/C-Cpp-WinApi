/*
	printf
	- printout variables, and constant to console
	- 변수나 상수등.. 화면상에 출력

	scanf
	- deliver value from keyboard to variables
	- 키보드로 입력 받은 값을 변수에 전달
	- 주의 : "%d "  " " 포멧의 뒤는 반드시 붙여서 이용
	*/

#include <stdio.h>

int main(){
	// initialize nA
	int nA = 5;
	printf("nA = %d\n", nA);

	nA = 11; // nA's value changed as 11
	printf("nA = %d\n", nA);


	// 1. 변수 nA에 입력한 숫자를 대입
	// scanf("formant", address)
	// Don't forget the ampersand
	// Care about the format. (형식 주의!)
	/*scanf("%d", &nA);
	printf("nA = %d\n", nA);
	*/

	// 2. 한번에 두개의 데이터 입력
	// put two input data at once
	//int nB = 0;
	//// 앞에 뛰는 것과 중간에 뛰는 것은 상관없지만, 마지막에 스페이스를 둘경우
	//// 다음 값 입력을 기다린다.
	//scanf("%d %d", &nA, &nB);
	//printf("nA = %d, nb = %d\n", nA, nB);

	// 3. 실수 입력
	/*float fC = 0.0f;
	printf("input float : \n", fC);
	scanf("%f", &fC);
	printf("fC = %.2f\n", fC);*/

	// 4. 문자 하나 입력
	char chD = 0;
	printf("input character : \n");
	scanf("%c", &chD);
	printf("입력한 문자 = %c\n", chD);
	printf("Asciicode = %x\n", chD);
}
