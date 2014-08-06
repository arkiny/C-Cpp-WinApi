#include "iGameObj.h"

/*
	Orc
*/
Orc::Orc()
{
	// 현재 상태를 IDLE로 기본설정
	pstate = new StateIdle;
}

Orc::~Orc()
{
	// 현재 상태를 최종 정리
	if (pstate){
		delete pstate;
		pstate = nullptr;
	}
}


void Orc::update(){
	if (pstate == nullptr){
		return; // exception
	}
	
	// 정상적인 상황
	pstate->execute(this);
}

void Orc::ChangeState(iState *pnew){
	// error check : 비정상일 경우 리턴
	if (pstate == nullptr || pnew == nullptr){
		return; // exception
	}

	// 정상적인 상황

	pstate->exit(this);		// 현재 상태를 종료하고
	delete pstate;			// 해당 상태를 삭제한다

	pstate = pnew;			// 새로운 상태를 현재 상태로 만듦
	pstate->enter(this);	// 새로운 상태로 진입
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
		// 오크를 공격 //
		in->SetHealth(in->GetHealth() - m_attack);
	}
}