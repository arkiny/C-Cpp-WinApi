/*
virtual ���� �Լ�
- ��ӹ��� Ŭ������ �Լ��� �켱 ���.
= 0 ���� �����Լ� (pure virtual function)
- pvf�� ���ؼ� ��� ���� Ŭ������ �ݵ�� �����Ѵ�.
*/

#ifndef _STATE_H_
#define _STATE_H_

// prototype���� ���ħ �Ѥ�
class Orc;

class iState
{
public:
	//�Ҹ��ڿ� virtual�� ���������μ� child class�� �Ҹ��ڿ��� call����
	virtual ~iState() {}
public:
	// ���� ����
	// pure virtual function
	// �ݵ�� �ؿ��� ���Ǹ� ����� �Ѵ�.
	virtual void enter(Orc* porc) = 0; // = 0 PURE VIRTUAL

	// ���� ������
	virtual void execute(Orc* porc) = 0;

	// ���� ��Ż
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