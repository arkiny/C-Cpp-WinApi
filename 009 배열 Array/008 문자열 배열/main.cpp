/*
	���Ϲ��� 'a' 'c' 'e'
	���ڿ�	"worldcup" ���ڳ� '\0' (null���ڰ� �߰��Ǿ�����)
*/

#include <stdio.h>

void show(char* pStr, int nCount);

void main(){
	char a = 'a';
	char strA[] = "a"; // "a" -> a\0

	printf("size = %d, %d\n", sizeof(a), sizeof(strA));

	//
	char strB[] = "Brazil vs Germany";
	int nCount = sizeof(strB) / sizeof(char);
	show(strB, nCount);
	
}

void show(char* pStr, int nCount){
	int i = 0;
	// solution 1
	while (true){
		printf("%c", pStr[i]);
		i++;
		if (pStr[i] == '\0'){
			break;
		}
	}
	printf("\n");

	// solution 2
	for (int i = 0; i < nCount; i++){
		printf("%c", pStr[i]);		
	}
	printf("\n");
}


/*

�ѱ��ھ� Ÿ�����ؼ� Ʋ���κ��� ���� ����
��)
�־��� ����	] a rolling stone gathers no moss
Ÿ����		] a r_ll_ng s_one gathers no moss

�⺻ ] �� ���ڰ� Ʋ�Ƚ��ϴ�. :: ___
Ȯ�� ] Ÿ���� �Ϸ���� �ɸ� �ð� :: __

���� >> ���� ������ ���ڿ� �Է�
scanf("%[^\n]", string);
*/