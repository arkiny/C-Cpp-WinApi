#include <iostream>
#include "State.h"
#include "iGameObj.h"

using std::cout;
using std::endl;

void StateIdle::enter(Orc* porc){
	cout << "IDLE STATE 진입..." << endl;
}

void StateIdle::execute(Orc* porc){
	
	int nhealth = porc->GetHealth();
	cout << "오크가 빈둥거립니다. \t"
		<< "HP = " << porc->GetHealth()
		<< endl;	
	//porc->SetHealth(--nhealth);
	

	// 오크 사정거리내에 적이 있는가? (어그로가 끌렸는가?)
	if (porc->getDist() <= porc->getRange()){		
		porc->ChangeState(new StateFight);
	}
	// 오크의 체력이 부족한가?
	else if (porc->GetHealth() < 20){		
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
	
	cout << "오크가 자면서 체력을 회복합니다. Z Z z z .." << endl
		<< "HP = " << porc->GetHealth()
		<< endl;

	if (porc->getDist() <= porc->getRange()){
		// 거리가 좁혀졌으면 전투상황에 다시 직면한다.
		porc->ChangeState(new StateFight);
	}
	// 오크가 체력 회복 했나?
	else if (porc->GetHealth() > 20){
		// 배회하러 간다
		porc->SetHealth(20);
		porc->ChangeState(new StateIdle);
	}
}

void StateSleep::exit(Orc* porc){
	cout << "StateSleep STATE 이탈 .." << endl;
}


/*
	State Fight
*/

void StateFight::enter(Orc* porc){
	cout << "FIGHT STATE 진입..." << endl;
}

void StateFight::execute(Orc* porc){
	// 내가 죽었는가?
	// 왜 0까지 안떨어지는지 모르겠다.
	// 일단 1로 넣어둠
 	if (porc->GetHealth() <= 1){
		porc->ChangeState(new StateDead);
	}
	// 내 체력이 별로 없는가?
	else if (porc->GetHealth() < 5){
		porc->SetHealth(5);
		porc->ChangeState(new StateRunAway);
	}
	// 적이 죽었는 가?
	else if (porc->getEnemyHealth() <= 0){
		porc->ChangeState(new StateIdle);
		porc->setEnemyRange(10); // 적 리셋
	}
	else  // 위의조건이 충족되지 않았을시 전투
	{
		// 새 매니저를 만들어서 전투상태 처리를해야 하나....
		// 일단 간단히 처리
		int nhealth = porc->GetHealth();
		int ehealth = porc->getEnemyHealth();

 		nhealth = nhealth - 4; // 차후에 enemy 공격력확인
		ehealth = ehealth - 2;

		porc->SetHealth(nhealth);
		porc->setEnemyHealth(ehealth);

		cout << "오크가 공격당해 데미지 4를 받습니다." << endl
			<< "HP = " << porc->GetHealth()
			<< endl;

		cout << "오크가 플레이어를 공격해 2를 를 줍니다." << endl
			<< "Player HP = " << porc->getEnemyHealth()
			<< endl;
	}
	

}

void StateFight::exit(Orc* porc){
	cout << "FIGHT STATE 종료..." << endl;
}

/*
	StateRunAway
*/

void StateRunAway::enter(Orc* porc){
	cout << "RUNAWAY STATE 진입..." << endl;
}

void StateRunAway::execute(Orc* porc){
	int dist = porc->getDist();	
	dist = dist + porc->getSpeed();
	porc->setDist(dist);
	cout << "오크가 " << porc->getSpeed() << "의 속도로 도망칩니다." << endl
		<< "플레이어와의 거리 : " << porc->getDist() << endl;
	if (porc->getDist() <= porc->getRange()){
		// 거리가 벌어지지 않았다면 한번 더 싸운다.
		porc->ChangeState(new StateFight);		
	}
	else if (dist > 10){ // 충분한 거리가 확보되면
		porc->ChangeState(new StateSleep);
	}
}

void StateRunAway::exit(Orc* porc){
	cout << "RUNAWAY STATE 종료..." << endl;
}

/*
	State- dead
*/
void StateDead::enter(Orc* porc){
	cout << "DEAD STATE 진입..." << endl;
}
void StateDead::execute(Orc* porc){
	cout << "오크가 쥬것음당 ㅠㅠ" << endl;
	// no exit;
}
void StateDead::exit(Orc* porc){
	cout << "DEAD STATE 종료..." << endl;
}