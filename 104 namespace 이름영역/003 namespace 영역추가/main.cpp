// ������Ʈ �ȿ����� ������� travel1�� �̾ƿü� �ִ�.
// �׷��� �Ǹ� �ߺ��� �ɼ� �ְ� �׷��� ifndef�� �ʿ�� �Ѱ�
#include "Travel1.h"
#include "Travel2.h""

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// �̹� ����� �ִ� ���ӽ����̽��� main.cpp�� �̿�
// ���� ����.
namespace travel{
	int dark = 120;
}

void main(){
	cout << "�̹��� �ް��� �� ���� : "
		<< travel::travelname[travel::JEJU] << endl;

	cout << "���� �ް��� = "
		<< travel::travelname2[travel::PALLOW] << endl;

	cout << travel::dark << endl;
}

// ũ�� ������ �����ڸ�
// struct < .h .cpp < namespace

/*
	���� ]]
	OOP��� ������ �����ϱ� Object Oriendted Programming
	Class��?
*/