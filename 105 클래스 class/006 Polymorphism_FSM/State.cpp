#include <iostream>
#include "State.h"
#include "Orc.h"

using std::cout;
using std::endl;

void StateIdle::enter(Orc* porc){
	cout << "IDLE STATE ����..." << endl;
}

void StateIdle::execute(Orc* porc){
	
	int nhealth = porc->GetHealth();
	porc->SetHealth(--nhealth);
	cout << "��ũ�� ��հŸ��ϴ�." 
		<<"HP = "<< porc->GetHealth()
		<<endl;

	// ��ũ�� �ǰ��Ѱ�?
	if (porc->GetHealth() < 3){
		porc->SetHealth(3);
		porc->ChangeState(new StateSleep);
	}
}

void StateIdle::exit(Orc* porc){
	cout << "IDLE STATE ��Ż .." << endl;
}

/*
	StateSleep
*/
void StateSleep::enter(Orc* porc){
	cout << "StateSleep STATE ����..." << endl;
}

void StateSleep::execute(Orc* porc){
	int nhealth = porc->GetHealth();
	nhealth += 2;
	porc->SetHealth(nhealth);
	
	cout << "Z Z z z .." << endl
		<< "HP = " << porc->GetHealth()
		<< endl;

	// ��ũ�� ü�� ȸ�� �߳�?
	if (porc->GetHealth() > 20){
		// ��ȸ�Ϸ� ����
		porc->SetHealth(20);
		porc->ChangeState(new StateIdle);
	}
}

void StateSleep::exit(Orc* porc){
	cout << "StateSleep STATE ��Ż .." << endl;
}