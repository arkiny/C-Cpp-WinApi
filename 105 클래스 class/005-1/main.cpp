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
class IGameObj{
public:
	IGameObj() {};
	virtual ~IGameObj(){}; // �Ҹ��� ���� ��쿡�� virtual�� ����� �Ѵ�.
	virtual void show() { // virtual�� �ɰ� �Ǹ� �ش� �Լ�, Ȥ�� ������ ���õȴ�..
		cout << "iGameObj ] --- show ---" << endl;
	}
};

/*
���� ����
- ������ ���ų� ������ �ִ� ���� �ο�.
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
	int nCntArm;		// ���� ����
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
	cout << "Arm ] --- " << nCntArm << " ���� �ȷ� "
		<< "������ ���� �� �ִ�." << endl;
}


/*
Leg
- �ٸ� ����
- �̵��ɷ� �ο�
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
	int nCntLeg;		// ���� ����
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
	cout << "Leg ] --- " << nCntLeg << " ���� �ٸ��� "
		<< "���� �� �ִ�." << endl;
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
	cout << "�� �̸��� " << name << endl;

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

	// �������� character�� �޾�����,
	// ĳ������ ���� ArmŬ������ function�� ���� �ִ�.
	// �ڽ����� ��ü�� �����, �θ�� ���� (up casting)
	//character* pminion = new character;

	///*pminion->show();*/
	//Arm* parm = (Arm*)pminion;
	//parm->setArm(2);
	//parm->show();
	//
	//delete pminion;

	/*
		�θ� ��ü�� �����, �ڽ����� ����
		������ ������ ������ ����
	*/

	//Leg* plegmini = new character;

	//// leg�� show()�� call��
	//plegmini->setLeg(10);
	//plegmini->show();

	//delete plegmini;

	IGameObj *pmini = new character;
	/*pmini->setLeg(2);*/
	
	//pmini->show();

	//character* pchar = (character*)pmini;
	character* pchar = dynamic_cast<character*>(pmini);
	// setType�� �̿��ؼ� ����
	pchar->setArm(1);
	pchar->setLeg(1);
	pchar->show();

	// delete error ���� ������ ������ Ȯ���� ���� �ʾұ� �����̴�.
	//delete pchar;
	delete pmini;
}

