/*
virtual 가상 함수
- 상속받은 클래스의 함수를 우선 사용.
= 0 순수 가상함수 (pure virtual function)
- pvf에 대해서 상속 받은 클래스는 반드시 정의한다.
*/

#ifndef _STATE_H_
#define _STATE_H_

// prototype으로 사기침 ㅡㅡ
class Orc;

class iState
{
public:
	//소멸자에 virtual을 정의함으로서 child class의 소멸자역시 call가능
	virtual ~iState() {}
public:
	// 상태 진입
	// pure virtual function
	// 반드시 밑에서 정의를 해줘야 한다.
	virtual void enter(Orc* porc) = 0; // = 0 PURE VIRTUAL

	// 상태 진행중
	virtual void execute(Orc* porc) = 0;

	// 상태 이탈
	virtual void exit(Orc* porc) = 0;
};

/*
	Idle State
*/
class StateIdle : public iState
{
private:
	void enter(Orc* porc);
	void execute(Orc* porc);
	void exit(Orc* porc);
};


/*
	Sleep State
*/
class StateSleep : public iState
{
private:
	void enter(Orc* porc);
	void execute(Orc* porc);
	void exit(Orc* porc);
};


#endif