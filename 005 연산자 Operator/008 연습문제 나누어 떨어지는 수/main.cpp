/*
	���ڸ� �Է� : ____

	7�� ������...

	������ ��������					= ��
	������ �������� ������		= ������
	*/

#include <stdio.h>
int main(){
	//init
	int nInput = -1;		// Input variable
	int nMod = -1;			// for modular value
	int nDiv = -1;			// for Division value
	int outResult = -1;	// our Return value

	//scaning part
	printf("���ڸ� �Է����ּ��� : \n");
	scanf("%d", &nInput);

	if (nInput <= 0){
		printf("0�̳� ������ ������� �ʽ��ϴ�. \n");
		return -1;
	}

	//compute and printing part
	nMod = nInput % 7;
	nDiv = nInput / 7;
	nMod != 0 ? outResult = nMod : outResult = nInput / 7;
	nMod != 0 ? printf("�������� �����ϴ� : %d\n", nMod) : printf("������ �������ϴ� - �� : %d\n", nDiv);

	return 0;
}