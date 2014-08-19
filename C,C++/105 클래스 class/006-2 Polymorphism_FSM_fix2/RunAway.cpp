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
		cout << "도망 종료, 다음 조건 확인(피로도)" << endl;
		callback(Sleeping);
		return Sleeping;
	}
	else {
		cout << "도망 중" << endl;
		callback(Running);
		tl = tl - 1;
		return Running;
	}
}