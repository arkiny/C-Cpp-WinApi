/*
	�迭 ���� �а� ����
*/


#include <stdio.h>
int main(){
	FILE* pfile = nullptr;
	char buffer[100] = {};

	////1. Ű���� ������ �����͸� buffer�� ����
	//fgets(buffer, 100, stdin);

	////2. buffer -> file �� ����
	//pfile = fopen("dataBuff.txt", "w");
	//{
	//	fputs(buffer, pfile);
	//}
	//fclose(pfile);

	//2. ������ ������ ���ۿ� ����
	pfile = fopen("dataBuff.txt", "r"); {
		fgets(buffer, 100, pfile);
		printf("%s\n", buffer);
	}
	fclose(pfile);
}