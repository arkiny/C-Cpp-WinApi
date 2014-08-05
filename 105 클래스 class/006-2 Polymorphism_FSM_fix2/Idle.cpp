#include <iostream>
#include "Idle.h"

using std::cout;
using std::endl;

Idle::Idle()
{
}

Idle::~Idle()
{
}

int Idle::goNext(function<void(int)> callback, int &el, int &tl)
{
	if (el + tl > 0){
		cout << "��� ����, ���� ���� �߰�" << endl;
		callback(Running);
		return Running;
	}
	else {
		cout << "��� ��" << endl;
		callback(Idling);
		return Idling;
	}
}