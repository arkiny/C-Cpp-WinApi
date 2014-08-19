/*
@author		Heedong Arkiny Lee
@date		07142014
@git		https://github.com/arkiny/SGA-Learning-Heedong

// �������ĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤĤ�

������ ���.... ������ �� ����..

������ ���׸� �ٽ��ѹ� �����
char *pstr[4] = {};

�� 16��, ���� ����

1���� [] [] [] [] [] [] [] []			char* pQuarterFinal[8]
2����   []    []   []    []				char* SemiFinal[4]
3����       []       []					char* Final[2]
���              []						char* pWinner
*/

/*
Design
main(){
	main�� �ּ�ȭ
	���� ��°�
	����Ÿ �̵��� �ǽ�
	????���Ŀ� ����Ÿ �̵����� ���� �Լ��� �����Ҽ� ������????
}

Controller(){
	���� ���������� r�� ���ؼ� �ݺ��� ��� ���ο��� ���Ӻκ���
	���ͼ� ������ �ְ�����... ������ ���⼭ ����
}

Model(���ڿ�, ���ڿ�){
	���ڿ��� �޾Ƽ�, �ش� ���ڿ��� ������ ���ݸ�ŭ 
	�������� ��� �������� �̾� ������
}

view(���, ��°���){
	�������̽� ���
	�������̽��� ��İ� �� ������ �޾Ƽ� ������� ����Ѵ�
	???? ���������� \t ������ ó���Ҽ� ������ ????
	ex) 8������ \t 1��, 4������ \t 2��, ��¿��� \t 4��
		����ڴ�\t 8�� ó���ؾ��Ϸ���?
	(�ϴ� �ش�κ� ����)
}
*/


#include <stdio.h> // printf()
#include <stdlib.h> // srand(), rand(), system()
#include <time.h> // time()

// Prototype
// Engine
void quarterFinalGame(char** inputArray, char** outputArray);
void semifinalGame(char** inputArray, char** outputArray);
void finalGame(char** inputArray, char** outputString);
void randomize(char* input[], char* output[], int size);

// View
void toString(char** input, int size);
void print_signature();

// Main Function
void main(){
	// ���� �ʱ�ȭ
	// Initialize the Country names
	// Initial DataBase
	char* pQuarterFinal[8] = { "Brazil", "Germany", 
								"France", "Spain",
								"Korea", "U.S.A", 
								"Ghana", "Argentina" };
	char* pSemiFinal[4] = {};
	char* pFinal[2] = {};
	char* pWinner[1] = {};
	
	// ���� �õ� �ʱ�ȭ
	// Seeding the random function
	srand(time(NULL));

	// Interface Initialization
	print_signature();
	toString(pQuarterFinal, 8);

	// Game Engine :D
	// ���� ���� �κ��� �������� ��±��� ���
	quarterFinalGame(pQuarterFinal, pSemiFinal);
	semifinalGame(pSemiFinal, pFinal);
	finalGame(pFinal, pWinner);

	system("pause");
} // main()

// 8�� ��� �ǽ�
// ���� ���� ���� �Ѱ��ֱ� ���� output parameter���� ������ �־�� �Ѵ�.
// @param char** inputArray		�Է¹��� ���� ���ڿ�(8��)
// @param char** outputArray	������ ���� ���ڿ�(4��)
void quarterFinalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 4);	
	toString(outputArray, 4);
} // quarterFinalGame()

// �ذ�� ��� �ǽ�
// ���� ���� ���� �Ѱ��ֱ� ���� output parameter���� ������ �־�� �Ѵ�.
// @param char** inputArray		�Է¹��� ���� ���ڿ�(4��)
// @param char** outputArray	������ ���� ���ڿ�(2��)
void semifinalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 2);
	toString(outputArray, 2);
} // semifinalGame()

// ��� ��� �ǽ�
// ���� ���� ���� �Ѱ��ֱ� ���� output parameter���� ������ �־�� �Ѵ�.
// �Ϲ� ���ڿ��� output���� �������� ������, �Լ��� ���ϼ��� ���� �迭 ��������
// �����ֱ�� ����
// @param char** inputArray		�Է¹��� ���� ���ڿ�(2��)
// @param char** outputArray	������ ���� ���ڿ�(1��)
void finalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 1);
	toString(outputArray, 1);
} // finalGame()

// �� ������ �ٽɺκ�
// �迭�� ������ ����� �޾�, �ƿ�ǲ �迭�� ���߾� �����ش�.
// ������ ���� �տ��� ���� ������� 2���� �߶� �ǽ��ϸ�,
// ���� �츮�� ���� �� �ִ� �迭 �ּҰ���
// ������ ������� ������ �� �迭�� 1/2�̹Ƿ�,
// ������ % 2 + (2 * i)�� �ȴ�. (2���� ������ �ö󰡹Ƿ�)
// @param char* input[] ��⸦ �ǽ��� ���ڿ�
// @param char* output[] ��� ����� �Է��� ���ڿ�
// @param int size ��� ������� �Էµ� output�� ������
// @warning ouput.length()�� input.length()�� 1/2������� �Ѵ�.
void randomize(char* input[], char* output[], int size){
	int pick = 0;
	for (int i = 0; i < size; ++i){
		pick = rand() % 2 + (2 * i);
		output[i] = input[pick];
	}
}

// ��� ó���� �̰����� ��� ó���Ѵ�.
// @param char*input[] ����� ���ڿ�
// @param int size	����� ���ڿ��� ������
void toString(char* input[], int size){
	switch (size)
	{
	case 8:
		printf("== 8�� ��� == \n", size);
		break;
	case 4:
		printf("== �ذ�� ��� == \n", size);
		break;
	case 2:
		printf("== ��� ��� == \n", size);
		break;
	case 1:
		printf("== ��� ��� ��� == \n", size);
		break;
	default:
		break;
	} // end switch

	for (int i = 0; i < size; i++){
		// 2������ vs�� �ٿ��� �ϹǷ�, �ּҰ��� �������� 1�� �ɶ�, vs ���
		if (i % 2 == 1){ 
			printf(" vs ");
		}
		else{
			// �ƴҶ� �׳� ĭ ������� ��ȣ ���
			printf("��");
		}
		printf("%s", input[i]);
	} // end for

	printf("��\n\n");
}

// ���� ���
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07142014 ����\n");
	printf("============================================================\n");
	printf("2120�� �ѱ� ������ ��� - (�����Ҷ����� ����� �ٲ�ϴ�)\n\n");
}