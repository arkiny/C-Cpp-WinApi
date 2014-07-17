/*
	@author		Heedong Arkiny Lee
	@date		07172014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	���� ] �������� �Ÿ����ϱ�

	struct POINT { x, y }

	�Ÿ� = calcDistance (&p1, &p2);

	POINT tower
	POINT enemy
	BOOL = tower.isinRange(&enemy) ;
	-> true "�߽�!"
	-> false "���"


	[[ �������� �Ÿ����� Ȱ�� ]]

	#include <math.h>
	pow( ,n) -> n������
	sqrt() -> ������ (��Ʈ ����)
*/


#include <stdio.h>	// printf()
#include <math.h>	// sqrt(), pow()
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()
#include <conio.h>	// _getch()

// Contant define
const int SIGHT_RANGE = 10;				//����ī�޶� ���ù���

// ��ǥ�� ����θ� �̷�����ٰ� ������ ��?
// Ȥ�� ������ �̷���� ��ǥ�� �ִٰ� �����Ҷ�
// ������ ������ �����Ƿ� �ϴ� ������ �������� �����ϸ�
// x1 = 1, x2 = 7
// x1 = -1, x2 = 7
// x1 = 1, x2 = -7
// x1 = -1, x2 = -7
// �� ��� ����� ���� ���ϸ�
// ��ȣ�� ���� ���� �μ��� ����,
// ��ȣ�� �ٸ� ���� �μ��� ��ģ��.
// ������ �������� �ڷ� ������ ���� �ɵ�
typedef struct POINT{
	float fX; // x��
	float fY; // y��

	// target�� �ڽŰ� �Ÿ��� ���ؼ� target�� �ڽ��� �þ� �ȿ� �ִ���
	// Ȯ�� �ϴ� �Լ�
	// @param point *target Ÿ���� �� point ��
	bool isinRange(POINT *target){
		// �� ������ �Ÿ���(��Ÿ��� ���� �̿�) �þ� �Ÿ����� ������? ������ true
		// ���� ������ false;
		return  this->distanceTo(target) <= SIGHT_RANGE; 
	}// is in Range

	// target�� �ڽŰ��� �Ÿ��� ���ؼ� �����ִ� �Լ�
	// @param point *target �Ÿ������� �� target
	float distanceTo(POINT *target){
		float a, b;
		// x�� �Ÿ� ���
		if (fX == target->fX){		// ���� ���ڰ� ������ 0
			a = 0;
		}
		else if (fX < target->fX){	// this.fX�� �����ÿ� Ÿ���� fX���� this.fX�� ��
			a = target->fX - fX;
		}
		else {						// �ݴ��� ���
			a = fX - target->fX;
		}// if()

		// y�� �Ÿ� ���
		if (fY == target->fY){		// ���� ���ڰ� ���� �� 0
			b = 0;
		}
		else if (fY < target->fY){	// this.fY�� �����ÿ� Ÿ���� fY���� fY�� ��
			b = target->fY - fY;
		}
		else {						// �ݴ��� ���
			b = fY - target->fY;
		} //if()

		// �� �������� �Ÿ��� ��Ÿ����� ������Ģ�� �̿��Ͽ� ���
		// sqrt(x�࿡�� ���������� �Ÿ�^2 + y�࿡���� ���� ������ �Ÿ�^2)
		return  sqrt(pow(a, 2) + pow(b, 2));
	}

	// ����ü�� ���� ��ǥ�� �μ��ϴ� helper method
	void printout(){
		printf("(%.2f, %.2f)\n", fX, fY);
	}
}point;

// prototype
float calcDistance(point *p1, point *p2);
void watch_Vision();
char keyinput();

// main
void main(){
	// seeding
	srand(time(NULL));	
	// for exit flag
	char exit_flag = 0;
	
	while (exit_flag != 'x' && exit_flag != 'X'){ // xŰ�� ������ ��� ����
		watch_Vision();
		exit_flag = keyinput();
		system("cls");
	} // while
} // main

// Test�� ���� �Լ�
// main �Լ��� �ּ�ȭ�� ���� �̰����� ����
void watch_Vision(){
	point watcher = { rand() % 20, rand() % 20 };	// ����ī�޶� ��ġ
	point thief = { rand() % 20, rand() % 20 };		// ���ϳ� ��ġ
	float dist = calcDistance(&watcher, &thief);	// �Ѱ��� �Ÿ�
	bool alert = watcher.isinRange(&thief);			// ����ī�޶�� ������ �߰��ߴ°�?
	
	printf("�������� �� ���� ��� �� �������� �Ÿ��� Ȯ���Ͽ�,\n");
	printf("������ ����ī�޶��� �þ�(�Ÿ� 10m) �ȿ� �ִ��� Ȯ���ϴ� �Լ��Դϴ�.\n");
	printf("------------------------------------------------------------\n");
	printf("����ī�޶� ��ġ : "); watcher.printout();
	printf("   ���� ��ġ    : "); thief.printout();	
	printf("  �Ѱ��� �Ÿ�   :     %.2fm\n", dist);
	printf("\n����ī�޶� �߰��Ͽ����ϱ�?\n");
	if (alert){
		printf("\a!!!!!!!!!!!!!!!!!!Enemy Insight!!!!!!!!!!!!!!!!!!\n\n");
	}
	else {
		printf("                     All clear!\n\n");
	} // if
	printf("�����Ͻ÷��� x��, ��� �׽�Ʈ �Ͻ÷��� �ƹ�Ű�� �����ּ���.\n");
} // watch_Vision

// �̹� �ش� struct �ȿ� helper method�� ����� ���⿡ ���ٷ� ó�� ����
// �� ��ǥ �ΰ��� �޾Ƽ� �Ÿ��� ����Ͽ� float���� �����Ѵ�
// @param point *p1 ���� ��ǥ 1
// @param point *p2 ���� ��ǥ 2
// @return float �ѻ����� �Ÿ�
float calcDistance(point *p1, point *p2){
	return p1->distanceTo(p2);
} // calcDistance

char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput