/*
	다중 상속 ( multiple inheritance )
	- 여러 부모 클래스를 하나의 자식 클래스로 상속
	- 부모 n : 자식 1 상속

	-virtual : 가상의 .... -> 무시하라는 소리
	- virtual을 어떻게 사용하느냐에 따라서 polymorphism 이용을 다르게 할수 있다.
	- 형변환도 중요하다
	- 엔간해서 상속받은 function은 최하위가 아닌이상 virtual을 이용한다.
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


/*
	최상단의 클래스
	- 특별한 역할을 하기보단, 구조를 완성짓기위한 기본클래스
*/
class IState{
public:
	IState() {};
	virtual ~IState(){}; // 소멸자 같은 경우에는 virtual을 써줘야 한다.
	virtual void show() { // virtual을 걸게 되면 해당 함수, 혹은 내용이 무시된다..
		cout << "IState ] --- show ---" << endl;
	}
};

/*
팔의 역할
- 물건을 집거나 잡을수 있는 역할 부여.
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
	int nCntIdle;		// 팔의 개수
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
	cout << "Idle ] --- " << nCntIdle << " 개의 팔로 "
		<< "물건을 잡을 수 있다." << endl;
}


/*
RunAway
- 다리 역할
- 이동능력 부여
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
	int nCntRunAway;		// 팔의 개수
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
	cout << "RunAway ] --- " << nCntRunAway << " 개의 다리로 "
		<< "걸을 수 있다." << endl;
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
	cout << "내 이름은 " << name << endl;

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

	// 동적으로 State를 받았지만,
	// 캐스팅을 통해 Idle클래스의 function을 쓸수 있다.
	// 자식으로 객체를 만들고, 부모로 접근 (up casting)
	//State* pminion = new State;

	///*pminion->show();*/
	//Idle* pIdle = (Idle*)pminion;
	//pIdle->setIdle(2);
	//pIdle->show();
	//
	//delete pminion;

	/*
		부모 객체를 만들고, 자식으로 접근
		하지만 삭제시 포인터 에러
	*/

	//RunAway* pRunAwaymini = new State;

	//// RunAway의 show()가 call됨
	//pRunAwaymini->setRunAway(10);
	//pRunAwaymini->show();

	//delete pRunAwaymini;

	IState *pmini = new State;
	/*pmini->setRunAway(2);*/
	
	//pmini->show();

	//State* pchar = (State*)pmini;
	State* pchar = dynamic_cast<State*>(pmini);
	// setType을 이용해서 관리
	pchar->setIdle(1);
	pchar->setRunAway(1);
	pchar->show();

	// delete error 나는 이유는 다형성 확보가 되지 않았기 때문이다.
	//delete pchar;
	delete pmini;
}

