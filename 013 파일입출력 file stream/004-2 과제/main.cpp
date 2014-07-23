/*
	@author		Heedong Arkiny Lee
	@date		07242014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	메모장으로 그린 맵 이미지 불러와서 화면 출력
	타일맵 불러오기(크기는 고정 설정)

	주의 ] 특수문자는 2 byte이고,
	각 열의 끝에는 null 문자가 있음을 고려
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
		printf("타일 맵은 아무키나 누르면 자동적으로 재생성됩니다.\n");
		printf("생성된 맵을 저장하고 싶으시면 (S)ave 키를,\n");
		printf("생성된 맵을 로딩하고 싶으시면 (L)oad 키를,\n");
		printf("프로그램을 종료하고 싶으시면 (Q)uit 키를 눌러주세요.\n\n");
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
			printf("저장완료\n");
			system("pause");
			break;
		case 'l':
		case 'L':
			if (save_flag == 1){
				pfile = fopen("udd.dat", "rb"); {
					fread(&new_map, sizeof(MAP), 1, pfile);
				}
				fclose(pfile);
				printf("로딩완료\n");
				system("pause");
			}
			else {
				printf("세이브 파일이 없습니다. \n");
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

// 맵 랜덤생성
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
				printf("╊");
			}
			else{
				printf("■");
			}
		}
		printf("\n");
	}
}


// 유저로부터 키를 받아와서 출력하는 메뉴
char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput

// 서명
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07232014 기본 과제\n");
	printf("------------------------------\n");
}
