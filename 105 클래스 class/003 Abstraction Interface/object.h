#ifndef _OBJECT_H_
#define _OBJECT_H_
/*
Abstraction ( �߻�ȭ )
- Interface Ŭ������ ����ڰ��� ��ȣ�ۿ�
*/

#include <iostream>

using std::cout;
using std::endl;

typedef struct Point{
	// �ƿ� ���⼭ �ʱ�ȭ�ع����� �ٽ� ���� �ʿ䰡 �������� ����
	float fx = 0.0f;
	float fy = 0.0f;
}POINT, *LPPOINT;

class Object
{
public:
	Object();
	~Object();
	void show();

private:
	/*POINT pos = {};*/ //�ֱٹ����� c++���� �̰� �����ϰ� �ٲ�
	POINT pos;
};

#endif