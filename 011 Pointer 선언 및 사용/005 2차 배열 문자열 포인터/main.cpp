/*
	2�� �迭 ���ڿ� ������
*/

#include <stdio.h> // printf()
int main()
{
	char *pstr[4] = {};
	
	char Brazil[] = "Brazil";
	char Holland[] = "Holland";
	char Germany[] = "Germany";
	char Argentina[] = "Argentina";

	pstr[0] = Brazil;
	pstr[1] = Holland;
	pstr[2] = Germany;
	pstr[3] = Argentina;

	printf("%s\n", pstr[1]);

	char USA[] = "USA";

	pstr[1] = USA;

	printf("%s\n", pstr[1]);

	return 0;
}


// �������ĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤ�
/*
	������ ���.... ������ �� ����..

	������ ���׸� �ٽ��ѹ� �����
	char *pstr[4] = {};

	�� 16��, ���� ����

	1���� [] [] [] [] [] [] [] []		char* pQuarterFinal[4]
	2����   []    []   []    []			char* SemiFinal[2]
	3����       []       []				char* Final[2]
	���              []					char* pWinner
*/