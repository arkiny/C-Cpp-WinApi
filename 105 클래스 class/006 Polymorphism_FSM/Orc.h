/*
	Orc ĳ����
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

	// ���¸� ����
	void ChangeState(iState* pnew);
	void update();

	void SetHealth(int h) { 
		m_health = h; 
	}

	// const�� ��ġ��ȯ�� �Ͼ�� �ʴ´ٴ� ����, get���� �����ö� �����Ѵ�.
	int GetHealth() const { 
		return m_health;
	}

private:
	// ���� �� �������ΰ�? state�� switching ���ֱ� ���ؼ�
	iState *pstate = nullptr;		// ���� ����
	int m_health = 20;				// ü������

};


#endif