#include <iostream>
#include "Resting.h"

using std::cout;
using std::endl;

Resting::Resting()
{
}

Resting::~Resting()
{
}

int Resting::goNext(function<void(int)> callback, int &el, int &tl)
{
	if (el == 0){
		cout << "�޽� ����, ���� ���� Ȯ��(��� ����)" << endl;
		callback(Idling);
		return Idling;
	}
	else {
		cout << "�޽� ��" << endl;
		callback(Sleeping);
		el--;
		return Sleeping;
	}
}