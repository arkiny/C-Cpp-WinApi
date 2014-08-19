/*
	Pointer : 주소를 가리킨다

	주소 크기는 32bit == 4byte

	pointer의 크기는 ? 4byte
*/

#include <stdio.h>
#include <stdlib.h>

void sefFloat(float *pfnum, float input_f);

void main(){
	char ch = 's';
	char *pch = &ch;

	printf("ch의 값 = %c, 주소 = %p\n", ch, &ch);
	printf("pch의 값 = %p\n", pch);
	printf("pch의 주소 = %p\n", &pch);

	printf("pch를 통한 ch의 값 = %c\n", *pch);
	
	*pch = 't';
	printf("ch의 값 = %c\n", ch);
	printf("pch를 통한 ch의 값 = %c\n", *pch);

	printf("ch의 크기 = %d\n", sizeof(ch));
	// 주소값이 저장되어 있으므로 4바이트가 저장
	printf("pch의 크기 = %d\n", sizeof(pch));  

	//
	float fnum = 3.14f;
	float *pfnum = &fnum;

	// pfnum에 5.12f
	// fnum 확인
	// 함수로 만들것

	*pfnum = 5.12f;
	printf("fnum의 값 : %f\n", fnum);

	sefFloat(pfnum, 9.18f);
	printf("fnum의 값 : %f\n", fnum);
	
}

void sefFloat(float *pfnum, float input_f){
	*pfnum = input_f;	
}