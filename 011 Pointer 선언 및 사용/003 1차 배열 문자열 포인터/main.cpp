/*
	1차 배열 문자열 포인터
*/

#include <stdio.h>

void show(char* pstring, int index);
void show2(char pstring[], int index);

void main(){
	// variable initialization
	char str[] = "Worldcup Winner ?";
	int offset = 0;

	/*
		pstr에 str을 전달, pstr을 출력 
		printf(pstr )-> Winner ?
	*/
	char *pstr = str + 9;
	printf("%s\n", pstr);

	int i = 0;
	while (true){
		if (pstr[i]=='\0'){
			break;
		}
		printf("%c", pstr[i]);
		i++;
	}	
	printf("\n");
	
	
	// 함수화 하기
	show(pstr, offset);
	show2(pstr, offset);
}

void show(char* pstring, int index){
	printf("%s\n", pstring + index);
}

void show2(char pstring[], int index){
	// 값을 받아오는 것이므로 주소값을 받아야 하므로 Ampersand를 이용한다.
	printf("%s\n", &pstring[index]);
}