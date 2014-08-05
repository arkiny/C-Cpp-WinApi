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
		cout << "State Machine v0.0001 - ������ �ִ� ����" << endl
			<< "------------------------------------------" << endl
			<< "1. One Step" << endl
			<< "2. ���赵 ����" << endl
			<< "3. �Ƿε� ����" << endl
			<< "4. ����" << endl
			<< "------------------------------------------" << endl
			<< "���� ���赵: " << tlevel << "\t\t�Ƿε�: " << elevel << endl
			<< "------------------------------------------" << endl
			<< "��� : ";
		cin >> input;
		switch (input)
		{
		case 1:
			this->step();
			break;
		case 2:
			cout << "���赵 ������ġ�� �Է����ּ���(�����..)" << endl
				<< "�Է� : ";
			cin >> input2;
			this->incTlevel(input2);
			break;
		case 3:
			cout << "�Ƿε� ������ġ�� �Է����ּ���(�����..)" << endl
				<< "�Է� : ";
			cin >> input2;
			this->incElevel(input2);
			break;
		case 4:
			cout << "���� �մϴ�." << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}