/*
	@author		Heedong Arkiny Lee
	@date		07102014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// prototype
void print_signature();
void ranSen(char pStr1[][12], char pStr2[][20], char pStr3[][6]);
// main function
void main(){
	
	// seeding
	srand(time(NULL));
	
	// variable initialization
	unsigned input_key = 0;
	char str1[][12] = { "��뿡 ", "�߼��ô뿡 ", "�ﱹ�ô뿡 ", "����ô뿡 " };
	char str2[][20] = { "������ ���ϴ� ", "������ ���� ", "���� �߽�� ", "�ð������� �ϴ� " };
	char str3[][6] = { "��", "���", "���", "���" };
	
	// Print out the function
	while (input_key != 'q'){
		print_signature();

		printf("\n\n����� ������?\n");
		ranSen(str1, str2, str3);
		printf("\n\n �׸� �Ͻ÷��� q�� �����ּ���.\n\n");
		input_key = _getch();		
		if (input_key == 0xE0 || input_key == 0) input_key = _getch();	// �ּҰ� check
		if (input_key == 'q'){
			break;
		}
		system("cls");
	}
}

// print out random Sentence
// @param ptr1[][12]
// @param ptr2[][17]
// @param ptr3[][5]
void ranSen(char pStr1[][12], char pStr2[][20], char pStr3[][6]){
	int randomNum = -1;

	printf("����� ");

	// ������ ���ڸ� �ּҷ� �̾Ƴ��� ����Ѵ�.
	randomNum = rand() % 4;
	printf("%s", pStr1[randomNum]);

	randomNum = rand() % 4;
	printf("%s", pStr2[randomNum]);

	randomNum = rand() % 4;
	printf("%s", pStr3[randomNum]);
	printf("�̾����ϴ�\n");
}

// ���� ���
void print_signature(){
	printf("����\n");
	printf("07102014 SGA51A ����\n");
	printf("================================================\n");
}
