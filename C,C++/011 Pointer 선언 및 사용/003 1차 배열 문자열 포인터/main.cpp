/*
	1�� �迭 ���ڿ� ������
*/

#include <stdio.h>

void show(char* pstring, int index);
void show2(char pstring[], int index);

void main(){
	// variable initialization
	char str[] = "Worldcup Winner ?";
	int offset = 0;

	/*
		pstr�� str�� ����, pstr�� ��� 
		printf(pstr )-> Winner ?
	*/
	char *pstr = str + 9;
	printf("%s\n", pstr);

	int i = 0;
	while (true){
		if (pstr[i]=='\0'){
			break;
		}
		printf("%c", pstr[i]);
		i++;
	}	
	printf("\n");
	
	
	// �Լ�ȭ �ϱ�
	show(pstr, offset);
	show2(pstr, offset);
}

void show(char* pstring, int index){
	printf("%s\n", pstring + index);
}

void show2(char pstring[], int index){
	// ���� �޾ƿ��� ���̹Ƿ� �ּҰ��� �޾ƾ� �ϹǷ� Ampersand�� �̿��Ѵ�.
	printf("%s\n", &pstring[index]);
}