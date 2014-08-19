/*
	배열 버퍼 읽고 쓰기
*/


#include <stdio.h>
int main(){
	FILE* pfile = nullptr;
	char buffer[100] = {};

	////1. 키보드 버퍼의 데이터를 buffer에 저장
	//fgets(buffer, 100, stdin);

	////2. buffer -> file 로 저장
	//pfile = fopen("dataBuff.txt", "w");
	//{
	//	fputs(buffer, pfile);
	//}
	//fclose(pfile);

	//2. 파일의 내요을 버퍼에 저장
	pfile = fopen("dataBuff.txt", "r"); {
		fgets(buffer, 100, pfile);
		printf("%s\n", buffer);
	}
	fclose(pfile);
}