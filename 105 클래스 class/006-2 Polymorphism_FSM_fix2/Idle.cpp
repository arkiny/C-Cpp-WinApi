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
		cout << "대기 중지, 중지 조건 발견" << endl;
		callback(Running);
		return Running;
	}
	else {
		cout << "대기 중" << endl;
		callback(Idling);
		return Idling;
	}
}