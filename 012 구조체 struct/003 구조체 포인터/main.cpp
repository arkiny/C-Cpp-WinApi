/*
@author		Heedong Arkiny Lee
@date		07162014
@git		https://github.com/arkiny/SGA-Learning-Heedong

����ü ������
*/

#include <stdio.h> // printf()

struct POINT{
	float fX; // x��
	float fY; // y��

	void show(){
		printf("--- show point ---\n");
		printf("X = %.2f ,  Y = %.2f\n", fX, fY); // ���ڸ������� ���
	}

	// plus method
	// @param POINT input ����� �ٸ� �Լ�
	// @return POINT this.x, this.y�� �Է¹��� struct�� x��� y���� ������ ��
	POINT plus(POINT input){
		POINT ret = { fX + input.fX, fY + input.fY };
		return ret;
	}
};

// prototype
POINT PlusPoint(POINT p1, POINT p2);
POINT Al_PlusPoint(POINT p1, POINT p2);
void print_signature();

// main
void main(){
	// Variable Init
	POINT p1 = { 1.0f, 2.0f };
	POINT p2 = { 5.0f, 6.0f };
	POINT p5 = {};
	POINT p6 = {};
	POINT p7 = {};
	// p3 = p1 + p2 �� ���ְ� �ʹ�.
	/*p3 = { (p1.fX + p2.fX), (p1.fY + p2.fY) };
	p3.show();*/


	print_signature();
	// ���� ]]

	/*
	1. p3 = PlusPoint(p1, p2);
	2. p3 = p1.plus(p2);*/
	// �����ð��� �ѰŶ� �������� �𸣰� �ִٰ� ���ݳ�;
	// ���� �� ����Ŀ�, ���� �� ���, ����, ��� ��
	// �ڼ��Ѱ� �� �Լ� �ּ� ����
	printf("\noriginal p5-\n");
	p5.show();
	printf("changed p5-\n");
	p5 = PlusPoint(p1, p2);
	p5.show();

	printf("\noriginal p7-\n");
	p7.show();
	printf("changed p7-\n");
	p7 = Al_PlusPoint(p1, p2);
	p7.show();

	printf("\noriginal p6-\n");
	p6.show();
	printf("changed p6-\n");
	p6 = p1.plus(p2);
	p6.show();
	/////////////////////////////////////////////////
} // main()


// PlusPoint
// @Param POINT p1, �Է¹��� ù��° ��ü, x��� y�൥��Ÿ�� ������ �ִ�.
// @Param POINT p2, �Է¹��� �ι�° ��ü
// @return POINT p1�� x, y �� p2�� x,y�� ���� ������ x,y�� ���� POINT�� ����
POINT PlusPoint(POINT p1, POINT p2){
	POINT ret = { p1.fX + p2.fX, p1.fY + p2.fY }; // �� POINT�� ������ �����ͼ� ���� ���
	return ret;
} // PlusPoint();

// Alternative PlustPoint
// ��ü ������ �̿��Ͽ� ����� ���
// �̹� �츮�� Struct�ȿ� ����� �Լ��� ������ �ִ�?!
POINT Al_PlusPoint(POINT p1, POINT p2){
	return p1.plus(p2); // Struct���� �Լ��� �״�� �̿��ؼ� ����
} // PlusPoint();


// ���� ���
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07162014 ����\n");
	printf("============================================================\n");
}