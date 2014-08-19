/*
	파일 불러오기
*/

#include <stdio.h>

// int 리턴하는 경우와 void 리턴하는 경우는 일단 다르긴 다름
int main(){
	FILE* pfile = nullptr;

	pfile = fopen("data.txt", "r");
	{
		//
		int buff = 0;
		while (true){
			// 문자를 한글자씩 읽어온다.
			if (buff == EOF) break;
			buff = fgetc(pfile);
			printf("%c", buff);	
					
		}
	}
	fclose(pfile);


	return 0;
}

/*
과제 ]]

리스트에 데이타를 저장하고 불러오기
*/