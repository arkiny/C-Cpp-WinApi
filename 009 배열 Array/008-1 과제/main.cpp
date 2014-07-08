/*
	@author		Heedong Arkiny Lee
	@date		07092014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	�ѱ��ھ� Ÿ�����ؼ� Ʋ���κ��� ���� ����
	��)
	�־��� ����	] a rolling stone gathers no moss
	Ÿ����		] a r_ll_ng s_one gathers no moss

	�⺻ ] �� ���ڰ� Ʋ�Ƚ��ϴ�. :: ___
	Ȯ�� ] Ÿ���� �Ϸ���� �ɸ� �ð� :: __

	���� >> ���� ������ ���ڿ� �Է�
	scanf("%[^\n]", string);

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXLEN 65535 // �ӽ÷� ���� char array�� Max Length

// Prototype
void print_signature();;
void printchara(char* input);
double diffclock(clock_t input1, clock_t input2);
void compare_char(char* origin, char* input);

// main method
void main(){
	// variable initialization
	// �����͸� �̿�ÿ��� ���� �������� Ȱ���Ҽ� �ְ�����
	// ���� ������ �̿��� �Ұ��ϹǷ� ������ ������ ũ�⸦ ��������� (Ư�� scanf�� �������)
	char ex_string[MAXLEN] = "a rolling stone gathers no moss";
	char input_string[MAXLEN] = "";
	
	// time_t�� ��� �ʴ������� ����� �����ϳ� �� ���� �ð� ����� �Ұ��� �ϹǷ�
	// clock_t(Ŭ��)�� �޾Ƽ� ���
	clock_t start_time, end_time;

	// �ð� ���̴� ����̹Ƿ� float ���� double�� �޾Ƽ� �ð��� ���
	double seconds = 0.0f;

	// ���� ���
	print_signature();

	// ���� ���ڿ� ���
	// ���� ���ڿ��� �Է� ������ ������, �ϴ��� �н�
	printchara(ex_string);

	// �Է� ����	
	start_time = clock();
	scanf("%[^\n]", input_string);
	end_time = clock();

	// ������ ���� �ٸ� ���ڼ��� ��ġ ���
	compare_char(ex_string, input_string);

	// clock�� �޾Ƽ� ����ϹǷ� ���� �Լ��� ���� ���
	seconds = diffclock(end_time, start_time);
	printf("Ÿ���� �Ϸ���� �ɸ� �ð� : %.2f second \n", seconds);	
	system("pause");
}

// ���� ���
void print_signature(){
	printf("����\n");
	printf("07082014 SGA51A �켱����\n");
	printf("================================================\n");
}

// ���ڿ����� ����, �߸��� ������ġ ���
// @param char* origin	���� ���ڿ�
// @param char* input	���� ���ڿ�
void compare_char(char* origin, char* input){
	char* wronglocate = (char*)malloc(sizeof(origin)*sizeof(char));
	int i = 0;
	int wrongcount = 0;
	while (true){
		if (origin[i] == '\0'){
			break;
		}
		else if (origin[i] != input[i]){
			wronglocate[i] = '^';
			wrongcount++;			
		}
		else{
			wronglocate[i] = ' ';
		} //if()
		i++;
	} // while()
	printchara(wronglocate);
	printf("%d ���ڰ� Ʋ�Ƚ��ϴ�.\n", wrongcount);	
}

// �����ð��� ��� print char array
// ���ڿ��� �޾Ƽ� ȭ�鿡 ���
// @param char* input ���ڿ�(character array)
void printchara(char* input){
	int i = 0;
	while (true){
		printf("%c", input[i]);
		i++;
		if (input[i] == '\0'){
			break;
		}
	}//while()
	printf("\n");
}

// Ŭ������ �ð� ���̸� ����Ͽ� �ʴ����� ����
// @param clock_t input1 ���μ����� ���� �ð�
// @param clock_t input2 ���μ����� ���۵� �ð�
// @return duration time in second
double diffclock(clock_t input1, clock_t input2){
	double diffticks = input1 - input2;
	// Ŭ��ƽ�� ���� 1ms���� 1���̹Ƿ� 
	// �̹� �������ִ� CLOCK_PER_SEC(c������ 1000)  �̿�
	// �Ͽ� ������ �ʴ����� ����
	double diffms = diffticks / (CLOCKS_PER_SEC);
	return diffms;
}
