#include "Orc.h"

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
	delete pstate;		// �ش� ���¸� �����Ѵ�

	pstate = pnew;		// ���ο� ���¸� ���� ���·� ����
	pstate->enter(this);	// ���ο� ���·� ����
}