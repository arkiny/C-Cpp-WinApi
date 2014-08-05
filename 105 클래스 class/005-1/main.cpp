/*
	���� ��� ( multiple inheritance )
	- ���� �θ� Ŭ������ �ϳ��� �ڽ� Ŭ������ ���
	- �θ� n : �ڽ� 1 ���

	-virtual : ������ .... -> �����϶�� �Ҹ�
	- virtual�� ��� ����ϴ��Ŀ� ���� polymorphism �̿��� �ٸ��� �Ҽ� �ִ�.
	- ����ȯ�� �߿��ϴ�
	- �����ؼ� ��ӹ��� function�� �������� �ƴ��̻� virtual�� �̿��Ѵ�.
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


/*
	�ֻ���� Ŭ����
	- Ư���� ������ �ϱ⺸��, ������ �ϼ��������� �⺻Ŭ����
*/
class IState{
public:
	IState() {};
	virtual ~IState(){}; // �Ҹ��� ���� ��쿡�� virtual�� ����� �Ѵ�.
	virtual void show() { // virtual�� �ɰ� �Ǹ� �ش� �Լ�, Ȥ�� ������ ���õȴ�..
		cout << "IState ] --- show ---" << endl;
	}
};

/*
���� ����
- ������ ���ų� ������ �ִ� ���� �ο�.
- ???
*/
class Idle : virtual public IState
{
public:
	Idle() ;
	virtual ~Idle() ;

public:
	virtual void show();

	void setIdle(int ncnt)	{ nCntIdle = ncnt; }
	int getIdle()			{ return nCntIdle; }

private:
	int nCntIdle;		// ���� ����
};

Idle::Idle()
{
	cout << "Idle ] --- constructor --- " << endl;
}

Idle::~Idle()
{
	cout << "Idle ] --- destructor --- " << endl;
}

void Idle::show()
{
	cout << "Idle ] --- " << nCntIdle << " ���� �ȷ� "
		<< "������ ���� �� �ִ�." << endl;
}


/*
RunAway
- �ٸ� ����
- �̵��ɷ� �ο�
*/
class RunAway : virtual public IState
{
public:
	RunAway();
	virtual ~RunAway();

public:
	virtual void show();

	void setRunAway(int ncnt)	{ nCntRunAway = ncnt; }
	int getRunAway()			{ return nCntRunAway; }

private:
	int nCntRunAway;		// ���� ����
};

RunAway::RunAway()
{
	cout << "RunAway ] --- constructor --- " << endl;
}

RunAway::~RunAway()
{
	cout << "RunAway ] --- destructor --- " << endl;
}

void RunAway::show()
{
	cout << "RunAway ] --- " << nCntRunAway << " ���� �ٸ��� "
		<< "���� �� �ִ�." << endl;
}

/*
*/
class State : public Idle, public RunAway
{
public:
	State();
	~State();

	void setname(string str)	{ name = str; }
	string getname()			{ return name; }

	void show();

private:
	string name;
};

State::State()
{
	cout << "State ] --- constructor --- " << endl;
}

State::~State()
{
	cout << "State ] --- destructor --- " << endl;
}

void State::show()
{
	cout << "�� �̸��� " << name << endl;

	Idle::show();
	RunAway::show();
}




/*
*/
void main()
{
	//State minion;

	//minion.setIdle(3);
	//minion.setname("Poppy");
	//minion.setRunAway(4);

	//minion.show();

	// �������� State�� �޾�����,
	// ĳ������ ���� IdleŬ������ function�� ���� �ִ�.
	// �ڽ����� ��ü�� �����, �θ�� ���� (up casting)
	//State* pminion = new State;

	///*pminion->show();*/
	//Idle* pIdle = (Idle*)pminion;
	//pIdle->setIdle(2);
	//pIdle->show();
	//
	//delete pminion;

	/*
		�θ� ��ü�� �����, �ڽ����� ����
		������ ������ ������ ����
	*/

	//RunAway* pRunAwaymini = new State;

	//// RunAway�� show()�� call��
	//pRunAwaymini->setRunAway(10);
	//pRunAwaymini->show();

	//delete pRunAwaymini;

	IState *pmini = new State;
	/*pmini->setRunAway(2);*/
	
	//pmini->show();

	//State* pchar = (State*)pmini;
	State* pchar = dynamic_cast<State*>(pmini);
	// setType�� �̿��ؼ� ����
	pchar->setIdle(1);
	pchar->setRunAway(1);
	pchar->show();

	// delete error ���� ������ ������ Ȯ���� ���� �ʾұ� �����̴�.
	//delete pchar;
	delete pmini;
}

