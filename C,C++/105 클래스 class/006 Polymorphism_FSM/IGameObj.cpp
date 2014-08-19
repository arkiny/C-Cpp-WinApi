#include "iGameObj.h"

/*
	Orc
*/
Orc::Orc()
{
	// ���� ���¸� IDLE�� �⺻����
	pstate = new StateIdle;
}

Orc::~Orc()
{
	// ���� ���¸� ���� ����
	if (pstate){
		delete pstate;
		pstate = nullptr;
	}
}


void Orc::update(){
	if (pstate == nullptr){
		return; // exception
	}
	
	// �������� ��Ȳ
	pstate->execute(this);
}

void Orc::ChangeState(iState *pnew){
	// error check : �������� ��� ����
	if (pstate == nullptr || pnew == nullptr){
		return; // exception
	}

	// �������� ��Ȳ

	pstate->exit(this);		// ���� ���¸� �����ϰ�
	delete pstate;			// �ش� ���¸� �����Ѵ�

	pstate = pnew;			// ���ο� ���¸� ���� ���·� ����
	pstate->enter(this);	// ���ο� ���·� ����
}

void Orc::attack(Player* in){
	in->SetHealth(in->GetHealth() - m_attack);
}

void Orc::setRange(Player* in){
	m_dist_enemy = m_position - in->getPosition();
}

/*
	Player
*/

void Player::update(Orc* in){
	this->move();
	this->attack(in);
}

void Player::attack(Orc* in){
	if (in->getPosition() - m_position <= m_range){
		// ��ũ�� ���� //
		in->SetHealth(in->GetHealth() - m_attack);
	}
}