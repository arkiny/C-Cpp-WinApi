
#include <stdio.h>

void show1(char str[]);
void show2(char* str);
void show3(char str[][20]);

int main(){
	// 1�� �迭 ���ڿ�
	char str1[] = "2014 Brazil Worldcup";

	show1(str1);
	show2(str1);
	return 0;
	
	// 2�� �迭 ���ڿ�
	char str2[][20] = { "USA Washington DC",
					"CANADA Otawa",
					"AUSTRAILIA Canberra",
					"CHINA Beijing"};

	show3(str2);
}

void show1(char str[]){
	printf("%s", str);
	printf("\n");
}

void show2(char *str){
	int i = 0;
	while (true){
		if (str[i] == '\0'){
			break;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

// ����
void show3(char str[][20]){
	printf("%s", str);
}

/*
	���ڿ� �����ϱ�
	str1 ���� = "ȫ�浿" "��浿" "��쵿"
	str2 ������ �ؼ� = " "
	str3 ��� �ƴ� = "�� �ƴ�" "���ڰ� ��� ���"

	��� = 
	������ =
	��� =
	�� =

	�� ��Ʈ�� ���� �����ϰ� �����ϱ�
*/