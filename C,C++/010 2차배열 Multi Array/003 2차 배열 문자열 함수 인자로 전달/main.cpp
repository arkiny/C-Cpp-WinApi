
#include <stdio.h>

void show1(char str[]);
void show2(char* str);
void show3(char str[][20]);

int main(){
	// 1차 배열 문자열
	char str1[] = "2014 Brazil Worldcup";

	show1(str1);
	show2(str1);
	return 0;
	
	// 2차 배열 문자열
	char str2[][20] = { "USA Washington DC",
					"CANADA Otawa",
					"AUSTRAILIA Canberra",
					"CHINA Beijing"};

	show3(str2);
}

void show1(char str[]){
	printf("%s", str);
	printf("\n");
}

void show2(char *str){
	int i = 0;
	while (true){
		if (str[i] == '\0'){
			break;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

// 과제
void show3(char str[][20]){
	printf("%s", str);
}

/*
	문자열 조합하기
	str1 누가 = "홍길동" "고길동" "어우동"
	str2 무엇을 해서 = " "
	str3 어떻게 됐다 = "잘 됐다" "부자가 됬다 등등"

	어디서 = 
	무엇을 =
	어떻게 =
	왜 =

	각 스트링 별로 랜덤하게 조합하기
*/