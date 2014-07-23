/*
	@author		Heedong Arkiny Lee
	@date		07212014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	�޸������� �׸� �� �̹��� �ҷ��ͼ� ȭ�� ���
	Ÿ�ϸ� �ҷ����� ( ũ��� ���� ���� )

	���� ] Ư�����ڴ� 2 byte�̰�, 
		  �� ���� ������ null ���ڰ� ������ ���

	���� : �߰� ���� ����

	!! �� Ÿ�ϸ� �׸��⸦ �׸��ΰڴ� !!
	!! Ÿ�ϸ� ���ܿ�.... !!
	
	���� ���α׷����� �λ����Ӹ���� ����
	���̺�/�ε��� �Ǵ� ����ٿ� �λ� 
	....

	1. Circular Array�� array 13���� ������ ���ѷ��ε��� ����
		- ��� ���μ����� �����Ҽ��� ������, �� �ʿ��Ѹ�ŭ�� ������ �޸� ������ ����
		- ���� ������ �ٷ� ���� ��Ȳ�� �������� �������� �����Ƿ�, ���̺�/�ε�����
		 ��Ӽ��� ������ �ִ�.
	2. �÷��̾ ������ �ڸ��� ���ο� ��Ȳ���� ������Ʈ
		- 13��¥�� �迭�� ������ ������ �ֻ��� �ΰ��� 12���� ���ü� �����Ƿ�, 
	      12�� �������ÿ� ���ڸ��� ���ƿ��Ƿ� ����� ������ ���ϱ� ����
	3. ���̳ʸ� ����, �ҷ����⸦ ���� ���̺�/�ε尡��...
	  - ���� �õ� ���� ����ǹǷ�, ���̺�/�ε� ��Ӽ��� ������.
		�ٵ� ��¥ �λ��� ���̺�/�ε尡 ���ٰ� �մϴ�....
*/

#include <stdio.h>		// FILE, fread, fwrite, printf
#include <stdlib.h>		// system(), rand(), srand(), _sleep()
#include <time.h>		// time()
#include <conio.h>		// _getch()

typedef struct game_info{
	int player_position;				// ���� �������� �÷��̾� ��ġ
	int current_money;					// �÷��̾ ������
	const int map_size = 13;			// �ʻ�����, ���⼱ 13���� ����
	int current_map[13];				// ������
	unsigned int rseed;					// ���� �õ� ��ȣ
}GAME_INFO;

void map_init(game_info *input);
int update(GAME_INFO *input);
void map_render(GAME_INFO *input);
void map_render_comp(GAME_INFO *input);
void icon_printer(int *input);
char keyinput();
void player_update(GAME_INFO *input, int status);
void print_signature();

void main(){	
	GAME_INFO play;
	char key = -1;
	int step; // ���� ĭ�� ��Ȳ
	map_init(&play);
	FILE* pfile = nullptr;
	int save_flag = 0;
	
	while (key != 'q' || key != 'Q'){
		// �� ����
		print_signature();
		map_render(&play);
		step = update(&play);
		printf("\n");
		map_render(&play);
		printf("\n");
		player_update(&play, step);
		// ���� ���� ��Ȳ
		if (play.current_money < 0){
			printf("����� ������ �Ǿ� �Ÿ��� ���ɰ� �Ǿ����ϴ�..\n");
			printf("���� ����Ÿ�� �ε��Ͻðڽ��ϱ�? (y/n)\n");
			key = keyinput();
			// �ֻ����� �����̶� �ٷ� ����Ȳ���� �ٸ� ��Ȳ�� ���ü� ����
			if (key == 'y' || key == 'Y'){
				if (save_flag == 0){
					printf("���̺� ������ �����ϴ�. \n");
					printf("������ �����մϴ�. \n");
					system("pause");
					break;
				}
				else{
					pfile = fopen("udd.dat", "rb");	 // w: write, b : binary
					{
						fread(&play, sizeof(GAME_INFO), 1, pfile);
					}
					fclose(pfile);
					printf("�ε� �Ϸ�\n");
					system("pause");
				}
			}
			else if (key == 'x' || 'X'){
				break;
			}
			else{
				printf("����� �ٽ� �Է����ּ���.\n");
			}
		}
		// ���ǿ���...
		else if (play.current_money > 500000000){
			printf("5���� �� ����� ġŲ���� ������ ��ſ� �����Ȱ�� ������ �Ǿ����ϴ�.\n");
			break;
		}
		else{
			key = keyinput();
		}
		// ���� �ҷ�����
		switch (key)
		{
		case 's':
		case 'S':
			pfile = fopen("udd.dat", "wb");	 // w: write, b : binary
			{
				fwrite(&play, sizeof(GAME_INFO), 1, pfile);
			}
			fclose(pfile);
			save_flag = 1;
			printf("���� �Ϸ�\n");
			system("pause");
			break;
		case 'L':
		case 'l':
			if (save_flag == 1){
				pfile = fopen("udd.dat", "rb");	 // w: write, b : binary
				{
					fread(&play, sizeof(GAME_INFO), 1, pfile);
				}
				fclose(pfile);
				printf("�ε� �Ϸ�\n");
				system("pause");
			}
			else {
				printf("���̺� ������ �����ϴ�. ������ �׳� �����մϴ�.\n");
				system("pause");
			}
			break;
		default:
			break;
		}
		system("cls");
	}
}

// map initialize
// ���� �õ嵵 ���� �޴´�
void map_init(game_info *input){		
	input->current_money = 350000;
	input->player_position = 0;
	input->current_map[0] = 8;
	for (int i = 1; i < input->map_size; i++){
		input->current_map[i] = rand() % 8;
	}
	input->rseed = time(NULL);
	srand(input->rseed);
}

// �÷��̾� �̵� ��, �̵��� ���� �ʾ�����Ʈ
// �÷��̾ ���� �� ��Ȳ ����
int update(GAME_INFO *input){
	int firstDice = rand() % 6 + 1;				// ù��° �ֻ���
	int secondDice = rand() % 6 + 1;			// �ι�° �ֻ���
	int sumDice = firstDice + secondDice;		// �� �ֻ����� ��
	int ret;
	
	// ������ ����
	printf("�ֻ����� �����ϴ�.");
	for (int i = 0; i < 3; i++){
		printf(".");
		_sleep(500);
	} 
	printf("\n");
	
	int i = 0;

	// �÷��̾ �̵��ϸ鼭 ĭ ������Ʈ
	while (i < sumDice){
		// �÷��̾ �������� ���� ��Ȳ�ٲ��ֱ� ������Ʈ
		if (i + input->player_position < input->map_size){
			input->current_map[i + input->player_position] = rand() % 8;
		}
		// ������ġ�� �ٸ��� ���� ������ �Ѿ�� ���� ������
		// ���� ó������ �ٽ� ����Ҽ� �ֵ���
		else {
			input->current_map[i + input->player_position - input->map_size] 
				= rand() % 8;
		}
		i++;
	}	

	// �÷��̾� ������ Ȯ��
	if (i + input->player_position < input->map_size){
		// Ȯ������ ���� ������ ��Ȳ ���Ͽ� ���� ������ ����
		ret = input->current_map[i + input->player_position]; 
		input->player_position = i + input->player_position;
	}
	else {
		ret = input->current_map[i + input->player_position - input->map_size];
		// Ȯ������ ���� ������ ��Ȳ ���Ͽ� ���� ������ ����
		input->player_position = i + input->player_position - input->map_size;
	}

	// debug
	/*for (int i = 0; i < input->map_size; i++){
		printf(" %d ", input->current_map[i]);
	}*/
	printf("\n");
	printf("ù��° �ֻ��� �� : %d\n", firstDice);
	printf("�ι�° �ֻ��� �� : %d\t �ֻ��� �հ� : %d\n", secondDice, sumDice);
	// debug

	return ret;
}

// ���� �� ��Ȳ�� �´� ������Ʈ
void player_update(GAME_INFO *input, int status){
	switch (status)
	{
	case 0:
		printf("\nȸ�翡�� ������ �޾ҽ��ϴ�..... \n ī��ȸ����� �����մϴ�....\n");
		printf("200������ ���忡 �Աݵ˴ϴ�.\n");
		input->current_money = input->current_money + 2000000;
		break;
	case 1:
		printf("\n����� ���߿� ������ ������ ����� �����ϴ�.\n");
		printf("��ſ��Ե� �ڵ������� �μ�Ƽ�갡 ���Խ��ϴ�.\n");
		printf("50������ ���忡 �Աݵ˴ϴ�.\n");
		input->current_money = input->current_money + 500000;
		break;
	case 2:
		printf("\n������...�Ĵ븦 �ȴ��ִ� ȸ���, �Ĵ밡 �����ϴ�....\n");
		printf("�ֱ� ����� ��Ⱑ �������� ���λ�ϴ�...\n");
		printf("��Ÿ��� ���������� �����ϴ�...\n");
		printf("150������ ���忡�� �����ϴ�.\n");
		input->current_money = input->current_money - 1500000;
		break;
	case 3:
		printf("\n�� ���� �� ���ڱ� ���ڸ� ���ƾ� �˴ϴ�.\n");
		printf("50������ ���忡�� �����ϴ�.\n");
		input->current_money = input->current_money - 500000;
		break;
	case 4:
		printf("\nȸ���� Ⱦ���� �ߵ�� ���� ������ �����մϴ�.\n");
		printf("�Ʋ����ٰ� �Ʋ������� ���� �����ϴ�...\n");
		printf("50������ ���忡�� �����ϴ�.\n");
		input->current_money = input->current_money - 500000;
		break;
	case 5:
		printf("\n��� ����� ������ �ζǸ� �纾�ϴ�.\n");
		printf("��÷�Ǿ����ϴ�!...... 5��\n");
		printf("5õ���� ���忡 �Աݵ˴ϴ�.\n");
		input->current_money = input->current_money + 5000;
		break;
	case 6:
		printf("\n....������ ����� ģ���� ���������ϴ�. \n");
		printf("����� ��� ����� �з��Ǿ����ϴ�.\n");
		input->current_money = 0;
		break;
	case 7:
		printf("\n�ų��� ����! \n");
		printf("������ �ֱ� ���ϴ뼼�� �����ڰ� ��°̴ϴ�.\n");
		printf("10������ ���忡�� �����ϴ�.\n");
		input->current_money = input->current_money + 100000;
		break;
	default:
		break;
	}

	printf("����� ���� : %d ��\n", input->current_money);
}

// �̵���Ȳ�� ���Ҽ� �ְ�
void map_render_comp(GAME_INFO *input){
	for (int i = 0; i < input->map_size; i++){
		printf("%d ", input->current_map[i]);
	}
	printf("\n");
}

// ��� �÷��̾ ó���� ���̵��� �����ؼ� ����ϴ� �Լ�
// 13���� ������ ȭ���� �Ѿ�� �ǹǷ� �ϴ� 9���� ����Ѵ�.
// ������ �÷��̾ ������ ù��°�� �ְ� �����ϰ� ������ش�.
void map_render(GAME_INFO *input){
	printf("���� ���� �ݾ� : %d\n", input->current_money);
	for (int i = 0; i < 9; i++){
		if (i + input->player_position < input->map_size){
			icon_printer(&(input->current_map[input->player_position + i]));
		}
		else {
			icon_printer(&(input->current_map
				[i + input->player_position - input->map_size]));
		}
	}
	printf("\n");
	printf("   ��");
}

// �׳� �� Ÿ�� �μ��ϴ� �Լ�
// @param int *input ���� ���������� �ٸ� �� �׸���.
void icon_printer(int *input){
	switch (*input)
	{
	case 0:
		printf("| ���� |");
		break;
	case 1:
		printf("| ��� |");
		break;
	case 2:
		printf("| ������ |");
		break;
	case 3:
		printf("| ���� |");
		break;
	case 4:
		printf("| ���� |");
		break;
	case 5:
		printf("| �ζ� |");
		break;
	case 6:
		printf("| �Ļ� |");
		break;
	case 7:
		printf("| ���� |");
		break;
	case 8:
		printf("| ��� |");
		break;
	default:
		break;
	}
}

// �����κ��� Ű�� �޾ƿͼ� ����ϴ� �޴�
char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput

// ����
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07232014 ����\n");
	printf("-------------------------------------------------------------\n");
	printf("  ���̺�/�ε��� �Ǵ� �ູ�� ���� ���α׷��� �λ� ����  \n");
	printf("| ���� : �ƹ�Ű | ���� : s, S  | �ҷ����� : l, L | ���� : q, Q |\n");
	printf("-------------------------------------------------------------\n");
}
