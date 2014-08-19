/*
	@author		Heedong Arkiny Lee
	@date		07242014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	�޸������� �׸� �� �̹��� �ҷ��ͼ� ȭ�� ���
	Ÿ�ϸ� �ҷ�����(ũ��� ���� ����)

	���� ] Ư�����ڴ� 2 byte�̰�,
	�� ���� ������ null ���ڰ� ������ ���
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct MAP{	
	int map[10][10];
};

// prototype
void show_map(MAP *input);
void map_init(MAP *input);
char keyinput();
void print_signature();

void main(){
	srand(time(NULL));
	FILE *pfile = nullptr;
	char key = -1;
	MAP new_map;
	map_init(&new_map);	
	int save_flag = 0;

	while (key != 'q' && key != 'Q'){
		print_signature();
		printf("Ÿ�� ���� �ƹ�Ű�� ������ �ڵ������� ������˴ϴ�.\n");
		printf("������ ���� �����ϰ� �����ø� (S)ave Ű��,\n");
		printf("������ ���� �ε��ϰ� �����ø� (L)oad Ű��,\n");
		printf("���α׷��� �����ϰ� �����ø� (Q)uit Ű�� �����ּ���.\n\n");
		show_map(&new_map);
		key = keyinput();
		switch (key)
		{			
		case 's':
		case 'S':
			pfile = fopen("udd.dat", "wb");	 // w: write, b : binary
			{
				fwrite(&new_map, sizeof(MAP), 1, pfile);
			}
			fclose(pfile);
			save_flag = 1;
			printf("����Ϸ�\n");
			system("pause");
			break;
		case 'l':
		case 'L':
			if (save_flag == 1){
				pfile = fopen("udd.dat", "rb"); {
					fread(&new_map, sizeof(MAP), 1, pfile);
				}
				fclose(pfile);
				printf("�ε��Ϸ�\n");
				system("pause");
			}
			else {
				printf("���̺� ������ �����ϴ�. \n");
				system("pause");
			}
			break;
		default:
			map_init(&new_map);
			break;
		}
		system("cls");
	}

}

// �� ��������
void map_init(MAP *input){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (rand() % 100 < 10){
				input->map[i][j] = 1;
			}
			else{
				input->map[i][j] = 0;
			}
		}
	}
}

void show_map(MAP *input){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (input->map[i][j] == 0){
				printf("��");
			}
			else{
				printf("��");
			}
		}
		printf("\n");
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
	printf("07232014 �⺻ ����\n");
	printf("------------------------------\n");
}
