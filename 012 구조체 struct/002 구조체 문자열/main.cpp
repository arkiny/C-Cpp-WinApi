/*
	1. ����ü �ȿ� ���ڿ�
	2. ����ü �ȿ� �Լ��ֱ�
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
	// �̷��� ���� �ִٴ� ��ü�� �޸𸮰� ���ӵǾ��ٴ� ��
	PROFILE ronaldo = {28, "ronaldo", 96};  
	PROFILE messi = { 26, "messi", 98 };
	
	/*
	printf("%d\n", ronaldo.nAge);
	printf("%s\n", ronaldo.name);
	printf("%d\n", ronaldo.nOffense);*/

	ronaldo.show();
	messi.show();

	ronaldo.inputName(); // ��ü �߽�
	ronaldo.show();

	show(&messi); // �Լ� �߽�
}

void show(PROFILE *pf){
	//�ּ��ϰ�쿡�� -> �̿�
	printf("------ show profile -------\n");
	printf("%d\n", pf->nAge);
	printf("%s\n", pf->name);
	printf("%d\n", pf->nOffense);
}