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


