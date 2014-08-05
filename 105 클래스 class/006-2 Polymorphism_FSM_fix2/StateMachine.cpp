#include <iostream>
#include "StateMachine.h"

using std::cin;
using std::cout;
using std::endl;
using std::bind;

StateMachine::StateMachine()
{
	elevel = 0;
	tlevel = 0;
}

StateMachine::StateMachine(State &in){
	current = in;
	elevel = 0;
	tlevel = 0;
}

StateMachine::~StateMachine()
{
}

void StateMachine::step(){
	this->goNext(elevel, tlevel);
}

void StateMachine::goNext(int &el, int &tl){
	using namespace std::placeholders; // to use _1
	current.goNext(bind(&StateMachine::setState, this, _1), el, tl);
}

void StateMachine::setState(int type){
	current.setState(type);
}

void StateMachine::incElevel(int in){
	elevel = elevel + in;
}

void StateMachine::incTlevel(int in){
	tlevel = tlevel + in;
}

void StateMachine::render(){
	int input = -1;
	int input2 = -1;
	while (input != 4){
		cout << "State Machine v0.0001 - 갈길이 멀다 버젼" << endl
			<< "------------------------------------------" << endl
			<< "1. One Step" << endl
			<< "2. 위험도 증가" << endl
			<< "3. 피로도 증가" << endl
			<< "4. 종료" << endl
			<< "------------------------------------------" << endl
			<< "현재 위험도: " << tlevel << "\t\t피로도: " << elevel << endl
			<< "------------------------------------------" << endl
			<< "명령 : ";
		cin >> input;
		switch (input)
		{
		case 1:
			this->step();
			break;
		case 2:
			cout << "위험도 증가수치를 입력해주세요(양수로..)" << endl
				<< "입력 : ";
			cin >> input2;
			this->incTlevel(input2);
			break;
		case 3:
			cout << "피로도 증가수치를 입력해주세요(양수로..)" << endl
				<< "입력 : ";
			cin >> input2;
			this->incElevel(input2);
			break;
		case 4:
			cout << "종료 합니다." << endl;
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}