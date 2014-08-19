/*
	1. 구조체 안에 문자열
	2. 구조체 안에 함수넣기
*/

#include <stdio.h> 

struct PROFILE{
	int nAge;
	char name[20];
	int nOffense;

	void show(){
		printf("------ show profile -------\n");
		printf("%d\n", nAge);
		printf("%s\n", name);
		printf("%d\n", nOffense);
	}

	void inputName(){
		scanf("%s", name);
	}
};

void show(PROFILE *pf);

void main(){
	// 이렇게 쓸수 있다는 자체가 메모리가 연속되었다는 말
	PROFILE ronaldo = {28, "ronaldo", 96};  
	PROFILE messi = { 26, "messi", 98 };
	
	/*
	printf("%d\n", ronaldo.nAge);
	printf("%s\n", ronaldo.name);
	printf("%d\n", ronaldo.nOffense);*/

	ronaldo.show();
	messi.show();

	ronaldo.inputName(); // 객체 중심
	ronaldo.show();

	show(&messi); // 함수 중심
}

void show(PROFILE *pf){
	//주소일경우에는 -> 이용
	printf("------ show profile -------\n");
	printf("%d\n", pf->nAge);
	printf("%s\n", pf->name);
	printf("%d\n", pf->nOffense);
}