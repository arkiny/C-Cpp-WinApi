/*
	typedef (typed define)
	- Re-define standard data type
	- ������ ���������� ������ �Ѵ�.
*/

#include <stdio.h> // printf()
// 1.
// unsinged int��� UNIT�� ������ ����
// �ƹ��ų� ���� �ִ°� �ƴ϶� ������ �����͸� ���������ټ� �ִ�.
typedef unsigned int UINT;

// 2.
// #define �� ���������� �ƴ϶� �������Ҽ� �ִ�.
// kkkk �� ���� unsigned int �ΰ̴ϴ�.
// �� ����� �Ҽ� �ִ� �̴ϴ�.
#define kkkk unsigned int

// 3.
// #define���� ����� �����Ϸ���, const �� ����� �����ϴ°� ����.
#define PI 3.141592
const float fPI = 3.141592f;

// �̷��� ���� point�� POINT �Ѵ� ������ �ְ� �Ǵ°�...
// ������ �˾ҳ�....
typedef struct point{

}POINT, pOiNT; // ������ ���ǵ� ����

// ������ �Ѱ��� ������ ����
typedef POINT pOINT;


int main(){
	// ���� ����ü�ϱ� �ٸ� ����ü�ϱ�?
	// ���� ����ü..
	point p1;
	POINT p2;
	pOiNT p3;
	pOINT p4;

	kkkk n = 1000;
	float f = fPI;

	return 0;
}