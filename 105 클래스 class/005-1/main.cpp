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
class IGameObj{
public:
	IGameObj() {};
	virtual ~IGameObj(){}; // 소멸자 같은 경우에는 virtual을 써줘야 한다.
	virtual void show() { // virtual을 걸게 되면 해당 함수, 혹은 내용이 무시된다..
		cout << "iGameObj ] --- show ---" << endl;
	}
};

/*
팔의 역할
- 물건을 집거나 잡을수 있는 역할 부여.
- ???
*/
class Arm : virtual public IGameObj
{
public:
	Arm() ;
	virtual ~Arm() ;

public:
	virtual void show();

	void setArm(int ncnt)	{ nCntArm = ncnt; }
	int getArm()			{ return nCntArm; }

private:
	int nCntArm;		// 팔의 개수
};

Arm::Arm()
{
	cout << "Arm ] --- constructor --- " << endl;
}

Arm::~Arm()
{
	cout << "Arm ] --- destructor --- " << endl;
}

void Arm::show()
{
	cout << "Arm ] --- " << nCntArm << " 개의 팔로 "
		<< "물건을 잡을 수 있다." << endl;
}


/*
Leg
- 다리 역할
- 이동능력 부여
*/
class Leg : virtual public IGameObj
{
public:
	Leg();
	virtual ~Leg();

public:
	virtual void show();

	void setLeg(int ncnt)	{ nCntLeg = ncnt; }
	int getLeg()			{ return nCntLeg; }

private:
	int nCntLeg;		// 팔의 개수
};

Leg::Leg()
{
	cout << "Leg ] --- constructor --- " << endl;
}

Leg::~Leg()
{
	cout << "Leg ] --- destructor --- " << endl;
}

void Leg::show()
{
	cout << "Leg ] --- " << nCntLeg << " 개의 다리로 "
		<< "걸을 수 있다." << endl;
}

/*
*/
class character : public Arm, public Leg
{
public:
	character();
	~character();

	void setname(string str)	{ name = str; }
	string getname()			{ return name; }

	void show();

private:
	string name;
};

character::character()
{
	cout << "Character ] --- constructor --- " << endl;
}

character::~character()
{
	cout << "Character ] --- destructor --- " << endl;
}

void character::show()
{
	cout << "내 이름은 " << name << endl;

	Arm::show();
	Leg::show();
}




/*
*/
void main()
{
	//character minion;

	//minion.setArm(3);
	//minion.setname("Poppy");
	//minion.setLeg(4);

	//minion.show();

	// 동적으로 character를 받았지만,
	// 캐스팅을 통해 Arm클래스의 function을 쓸수 있다.
	// 자식으로 객체를 만들고, 부모로 접근 (up casting)
	//character* pminion = new character;

	///*pminion->show();*/
	//Arm* parm = (Arm*)pminion;
	//parm->setArm(2);
	//parm->show();
	//
	//delete pminion;

	/*
		부모 객체를 만들고, 자식으로 접근
		하지만 삭제시 포인터 에러
	*/

	//Leg* plegmini = new character;

	//// leg의 show()가 call됨
	//plegmini->setLeg(10);
	//plegmini->show();

	//delete plegmini;

	IGameObj *pmini = new character;
	/*pmini->setLeg(2);*/
	
	//pmini->show();

	//character* pchar = (character*)pmini;
	character* pchar = dynamic_cast<character*>(pmini);
	// setType을 이용해서 관리
	pchar->setArm(1);
	pchar->setLeg(1);
	pchar->show();

	// delete error 나는 이유는 다형성 확보가 되지 않았기 때문이다.
	//delete pchar;
	delete pmini;
}

