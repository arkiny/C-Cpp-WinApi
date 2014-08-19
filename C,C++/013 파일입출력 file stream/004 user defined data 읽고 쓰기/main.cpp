/*
	User Defined Data 읽고 쓰기
	(사용자 정의 데이터)
	(구조체 형 데이터)
*/

#include <stdio.h>

typedef struct data{
	int index;			// 데이터 순번
	char name[20];		// 네이밍
	int level;			// 캐릭터 레벨
	char job[20];		// 캐릭터 직업
}DATA;

void main(){
	DATA dat1 = { 1, "Elsa", 95, "Mage Queen" };

	FILE* pfile = nullptr;

	//1. 구조체 데이터 저장					 //			t : text ( ascii type )
	//pfile = fopen("udd.dat", "wb");	 // w: write, b : binary
	//{
	//	fwrite(&dat1, sizeof(DATA), 1, pfile);
	//}
	//fclose(pfile);

	DATA dat2 = {};
	pfile = fopen("udd.dat", "rb"); {
		fread(&dat2, sizeof(DATA), 1, pfile);
		printf("read : 순번 %d, 이름 %s, 레벨 %d, 직업 %s\n",
					dat2.index, dat2.job, dat2.level, dat2.name);
	}
	fclose(pfile);
}