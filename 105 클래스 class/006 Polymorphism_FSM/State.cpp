#include <iostream>
#include "State.h"
#include "iGameObj.h"

using std::cout;
using std::endl;

void StateIdle::enter(Orc* porc){
	cout << "IDLE STATE ����..." << endl;
}

void StateIdle::execute(Orc* porc){
	
	int nhealth = porc->GetHealth();
	cout << "��ũ�� ��հŸ��ϴ�. \t"
		<< "HP = " << porc->GetHealth()
		<< endl;	
	//porc->SetHealth(--nhealth);
	

	// ��ũ �����Ÿ����� ���� �ִ°�? (��׷ΰ� ���ȴ°�?)
	if (porc->getDist() <= porc->getRange()){		
		porc->ChangeState(new StateFight);
	}
	// ��ũ�� ü���� �����Ѱ�?
	else if (porc->GetHealth() < 20){		
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
	
	cout << "��ũ�� �ڸ鼭 ü���� ȸ���մϴ�. Z Z z z .." << endl
		<< "HP = " << porc->GetHealth()
		<< endl;

	if (porc->getDist() <= porc->getRange()){
		// �Ÿ��� ���������� ������Ȳ�� �ٽ� �����Ѵ�.
		porc->ChangeState(new StateFight);
	}
	// ��ũ�� ü�� ȸ�� �߳�?
	else if (porc->GetHealth() > 20){
		// ��ȸ�Ϸ� ����
		porc->SetHealth(20);
		porc->ChangeState(new StateIdle);
	}
}

void StateSleep::exit(Orc* porc){
	cout << "StateSleep STATE ��Ż .." << endl;
}


/*
	State Fight
*/

void StateFight::enter(Orc* porc){
	cout << "FIGHT STATE ����..." << endl;
}

void StateFight::execute(Orc* porc){
	// ���� �׾��°�?
	// �� 0���� �ȶ��������� �𸣰ڴ�.
	// �ϴ� 1�� �־��
 	if (porc->GetHealth() <= 1){
		porc->ChangeState(new StateDead);
	}
	// �� ü���� ���� ���°�?
	else if (porc->GetHealth() < 5){
		porc->SetHealth(5);
		porc->ChangeState(new StateRunAway);
	}
	// ���� �׾��� ��?
	else if (porc->getEnemyHealth() <= 0){
		porc->ChangeState(new StateIdle);
		porc->setEnemyRange(10); // �� ����
	}
	else  // ���������� �������� �ʾ����� ����
	{
		// �� �Ŵ����� ���� �������� ó�����ؾ� �ϳ�....
		// �ϴ� ������ ó��
		int nhealth = porc->GetHealth();
		int ehealth = porc->getEnemyHealth();

 		nhealth = nhealth - 4; // ���Ŀ� enemy ���ݷ�Ȯ��
		ehealth = ehealth - 2;

		porc->SetHealth(nhealth);
		porc->setEnemyHealth(ehealth);

		cout << "��ũ�� ���ݴ��� ������ 4�� �޽��ϴ�." << endl
			<< "HP = " << porc->GetHealth()
			<< endl;

		cout << "��ũ�� �÷��̾ ������ 2�� �� �ݴϴ�." << endl
			<< "Player HP = " << porc->getEnemyHealth()
			<< endl;
	}
	

}

void StateFight::exit(Orc* porc){
	cout << "FIGHT STATE ����..." << endl;
}

/*
	StateRunAway
*/

void StateRunAway::enter(Orc* porc){
	cout << "RUNAWAY STATE ����..." << endl;
}

void StateRunAway::execute(Orc* porc){
	int dist = porc->getDist();	
	dist = dist + porc->getSpeed();
	porc->setDist(dist);
	cout << "��ũ�� " << porc->getSpeed() << "�� �ӵ��� ����Ĩ�ϴ�." << endl
		<< "�÷��̾���� �Ÿ� : " << porc->getDist() << endl;
	if (porc->getDist() <= porc->getRange()){
		// �Ÿ��� �������� �ʾҴٸ� �ѹ� �� �ο��.
		porc->ChangeState(new StateFight);		
	}
	else if (dist > 10){ // ����� �Ÿ��� Ȯ���Ǹ�
		porc->ChangeState(new StateSleep);
	}
}

void StateRunAway::exit(Orc* porc){
	cout << "RUNAWAY STATE ����..." << endl;
}

/*
	State- dead
*/
void StateDead::enter(Orc* porc){
	cout << "DEAD STATE ����..." << endl;
}
void StateDead::execute(Orc* porc){
	cout << "��ũ�� ������� �Ф�" << endl;
	// no exit;
}
void StateDead::exit(Orc* porc){
	cout << "DEAD STATE ����..." << endl;
}