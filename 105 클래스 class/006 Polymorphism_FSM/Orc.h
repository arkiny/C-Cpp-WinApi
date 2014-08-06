/*
	Orc 캐릭터
*/

#ifndef _ORC_H_
#define _ORC_H_

#include "State.h"

class iGameObj{
public:
	virtual ~iGameObj(){};
};

class Orc : public iGameObj
{
public:
	Orc();
	~Orc();

public: // interface

	// 상태를 변경
	void ChangeState(iState* pnew);
	void update();

	void SetHealth(int h) { 
		m_health = h; 
	}

	// const는 수치변환이 일어나지 않는다는 보장, get으로 가져올때 보증한다.
	int GetHealth() const { 
		return m_health;
	}

private:
	// 굳이 왜 포인터인가? state를 switching 해주기 위해서
	iState *pstate = nullptr;		// 현재 상태
	int m_health = 20;				// 체력지수

};


#endif