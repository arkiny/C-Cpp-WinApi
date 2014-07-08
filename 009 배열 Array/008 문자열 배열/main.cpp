/*
	단일문자 'a' 'c' 'e'
	문자열	"worldcup" 문자끝 '\0' (null문자가 추가되어있음)
*/

#include <stdio.h>

void show(char* pStr, int nCount);

void main(){
	char a = 'a';
	char strA[] = "a"; // "a" -> a\0

	printf("size = %d, %d\n", sizeof(a), sizeof(strA));

	//
	char strB[] = "Brazil vs Germany";
	int nCount = sizeof(strB) / sizeof(char);
	show(strB, nCount);
	
}

void show(char* pStr, int nCount){
	int i = 0;
	// solution 1
	while (true){
		printf("%c", pStr[i]);
		i++;
		if (pStr[i] == '\0'){
			break;
		}
	}
	printf("\n");

	// solution 2
	for (int i = 0; i < nCount; i++){
		printf("%c", pStr[i]);		
	}
	printf("\n");
}


/*

한글자씩 타이핑해서 틀린부분의 개수 세기
예)
주어진 문장	] a rolling stone gathers no moss
타이핑		] a r_ll_ng s_one gathers no moss

기본 ] 몇 글자가 틀렸습니다. :: ___
확장 ] 타이핑 완료까지 걸린 시간 :: __

참고 >> 띄어쓰기 포함한 문자열 입력
scanf("%[^\n]", string);
*/