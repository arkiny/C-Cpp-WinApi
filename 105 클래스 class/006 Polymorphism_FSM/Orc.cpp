#include "Orc.h"

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
	delete pstate;		// 해당 상태를 삭제한다

	pstate = pnew;		// 새로운 상태를 현재 상태로 만듦
	pstate->enter(this);	// 새로운 상태로 진입
}