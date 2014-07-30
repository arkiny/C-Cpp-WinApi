// 프로젝트 안에서는 어딜가나 travel1을 뽑아올수 있다.
// 그렇게 되면 중복이 될수 있고 그래서 ifndef가 필요로 한것
#include "Travel1.h"
#include "Travel2.h""

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// 이미 헤더에 있는 네임스페이스를 main.cpp에 이용
// 문제 없다.
namespace travel{
	int dark = 120;
}

void main(){
	cout << "이번에 휴가를 갈 곳은 : "
		<< travel::travelname[travel::JEJU] << endl;

	cout << "다음 휴가엔 = "
		<< travel::travelname2[travel::PALLOW] << endl;

	cout << travel::dark << endl;
}

// 크기 순서를 따지자면
// struct < .h .cpp < namespace

/*
	과제 ]]
	OOP라는 개념을 조사하기 Object Oriendted Programming
	Class란?
*/