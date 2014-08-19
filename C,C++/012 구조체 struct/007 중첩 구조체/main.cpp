/*
	��ø ����ü (����ü �ȿ� ����ü)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
	float m_fx; // x��ǥ
	float m_fy; // y��ǥ

	void setPos(float fx, float fy){
		m_fx = fx;
		m_fy = fy;
	}
	
	void show(){
		printf("( %.2f , %.2f )\n", m_fx, m_fy);
	}
}POINT;

struct character{
	//����.... �̷��� �־ ����
	char *name;
	POINT posTarget;
	POINT posCurrent;

	void setName(char *input){
		//name = malloc(sizeof(input))
		// �̷��� ������ ������ ����� �ֳ�? (�޸� ����?)
		// �̷��� �ؼ� ����� �ϸ� ������ ����
		// ������ ���� �Է��ؼ� �ӽú����� �ɾ��� ������
		// ������ �ɼ� �ִ�. ���� ��ī�ǰ� �߿�
		// ���� �Ҵ����� �׷� �Ű� �־�� �ϳ�?
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
		--------- ĳ���� ���� ----------
		�̸� : Tycus
		������ġ : 3.5f, 4.6f
		��ǥ��ġ : 7.7f, 9.2f
	*/
}

void showCharacter(CHARACTER *input){
	printf("----------ĳ���� ����----------\n");
	printf("�̸� : %s\n", input->name);
	printf("������ǥ : "); input->posCurrent.show();
	printf("��ǥ��ġ : "); input->posTarget.show();
}

