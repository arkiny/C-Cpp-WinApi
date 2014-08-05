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
		cout << "휴식 종료, 다음 조건 확인(대기 조건)" << endl;
		callback(Idling);
		return Idling;
	}
	else {
		cout << "휴식 중" << endl;
		callback(Sleeping);
		el--;
		return Sleeping;
	}
}