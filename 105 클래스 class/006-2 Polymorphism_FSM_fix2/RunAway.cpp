#include <iostream>
#include "RunAway.h"

using std::cout;
using std::endl;

RunAway::RunAway()
{
}

RunAway::~RunAway()
{
}

int RunAway::goNext(function<void(int)> callback, int &el, int &tl)
{
	if (tl == 0){
		cout << "���� ����, ���� ���� Ȯ��(�Ƿε�)" << endl;
		callback(Sleeping);
		return Sleeping;
	}
	else {
		cout << "���� ��" << endl;
		callback(Running);
		tl = tl - 1;
		return Running;
	}
}