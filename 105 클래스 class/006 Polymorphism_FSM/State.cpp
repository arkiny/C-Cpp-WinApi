#include <iostream>
#include "State.h"
#include "Orc.h"

using std::cout;
using std::endl;

void StateIdle::enter(Orc* porc){
	cout << "IDLE STATE 진입..." << endl;
}

void StateIdle::execute(Orc* porc){
	
	int nhealth = porc->GetHealth();
	porc->SetHealth(--nhealth);
	cout << "오크가 빈둥거립니다." 
		<<"HP = "<< porc->GetHealth()
		<<endl;

	// 오크가 피곤한가?
	if (porc->GetHealth() < 3){
		porc->SetHealth(3);
		porc->ChangeState(new StateSleep);
	}
}

void StateIdle::exit(Orc* porc){
	cout << "IDLE STATE 이탈 .." << endl;
}

/*
	StateSleep
*/
void StateSleep::enter(Orc* porc){
	cout << "StateSleep STATE 진입..." << endl;
}

void StateSleep::execute(Orc* porc){
	int nhealth = porc->GetHealth();
	nhealth += 2;
	porc->SetHealth(nhealth);
	
	cout << "Z Z z z .." << endl
		<< "HP = " << porc->GetHealth()
		<< endl;

	// 오크가 체력 회복 했나?
	if (porc->GetHealth() > 20){
		// 배회하러 간다
		porc->SetHealth(20);
		porc->ChangeState(new StateIdle);
	}
}

void StateSleep::exit(Orc* porc){
	cout << "StateSleep STATE 이탈 .." << endl;
}