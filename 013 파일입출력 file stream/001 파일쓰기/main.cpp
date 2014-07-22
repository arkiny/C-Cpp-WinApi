/*
	파일 저장하기
	fopen()
	fclose()
*/

#include <stdio.h>		// fopen(), fclose(), printf(), scanf()

int main(){
	FILE* pfile = nullptr;

	//1. 파일을 연다.
	//data.txt에 저장 ( "w" ) mode write
	pfile = fopen("data.txt", "w");
	{
		//3. 한글자씩 저장
		fputc('M', pfile);
		// My name
		fputc('y', pfile);
		fputc(' ', pfile);
		fputc('n', pfile);
		fputc('a', pfile);
		fputc('m', pfile);
		fputc('e', pfile);

		// 개행도 잘댐
		fputs("July\n 22\n", pfile);
		
		//My Age : xx , weight : XX, %d
		fprintf(pfile, "My Age : %d, weight : %d\nz", 28, 54);
	}

	//2. 파일을 닫는다.
	fclose(pfile);

	return 0;
}
