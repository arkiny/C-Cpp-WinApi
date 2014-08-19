/*
	중첩 구조체 (구조체 안에 구조체)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
	float m_fx; // x좌표
	float m_fy; // y좌표

	void setPos(float fx, float fy){
		m_fx = fx;
		m_fy = fy;
	}
	
	void show(){
		printf("( %.2f , %.2f )\n", m_fx, m_fy);
	}
}POINT;

struct character{
	//질문.... 이렇게 넣어서 만들어서
	char *name;
	POINT posTarget;
	POINT posCurrent;

	void setName(char *input){
		//name = malloc(sizeof(input))
		// 이렇게 받으면 문제가 생길수 있나? (메모리 누수?)
		// 이렇게 해서 출력을 하면 나오긴 나옴
		// 하지만 직접 입력해서 임시변수를 걸었을 때에는
		// 문제가 될수 있다. 따라서 딥카피가 중요
		// 동적 할당으로 그럼 옮겨 넣어야 하나?
		name = input;

		//name[0] = input[0];
	}
};

typedef character CHARACTER;
void showCharacter(CHARACTER *input);

void main(){
	/*POINT p1;
	p1.setPos(1.0f, 1.0f);
	p1.show();*/

	CHARACTER enemy1 = { "Tycus", { 3.5f, 4.6f }, { 7.7, 9.2f } };
	enemy1.setName("Tycus1");
	enemy1.posTarget.show();
	enemy1.posCurrent.show();

	showCharacter(&enemy1);

	/*
		--------- 캐릭터 정보 ----------
		이름 : Tycus
		현재위치 : 3.5f, 4.6f
		목표위치 : 7.7f, 9.2f
	*/
}

void showCharacter(CHARACTER *input){
	printf("----------캐릭터 정보----------\n");
	printf("이름 : %s\n", input->name);
	printf("현재좌표 : "); input->posCurrent.show();
	printf("목표위치 : "); input->posTarget.show();
}

