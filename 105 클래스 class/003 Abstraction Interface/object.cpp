#include "object.h"

void Object::show(){
	cout << ">>> Object Class <<<" << endl;
	cout << "posX = " << pos.fx << ", posY=" << pos.fy << endl;
}

Object::Object(){
	cout << ">>> Object Constructed <<<" << endl;
	// �ʱ�ȭ ����� ���������� ������...
	/*pos.fx = 0.0f;
	pos.fy = 0.0f;*/
	//Ȥ��
	//pos = POINT(); // ����ü�� ������ class�̹Ƿ� ������ ������, �Ҹ��ڰ� �ִ�.
}

Object::~Object(){
	cout << ">>> Object Destructed <<<" << endl;
}