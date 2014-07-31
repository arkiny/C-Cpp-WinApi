#include "object.h"

void Object::show(){
	cout << ">>> Object Class <<<" << endl;
	cout << "posX = " << pos.fx << ", posY=" << pos.fy << endl;
}

Object::Object(){
	cout << ">>> Object Constructed <<<" << endl;
	// 초기화 방법은 여러가지가 있으니...
	/*pos.fx = 0.0f;
	pos.fy = 0.0f;*/
	//혹은
	//pos = POINT(); // 구조체도 일종의 class이므로 숨겨진 생성자, 소멸자가 있다.
}

Object::~Object(){
	cout << ">>> Object Destructed <<<" << endl;
}