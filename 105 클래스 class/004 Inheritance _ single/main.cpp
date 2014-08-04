/*
	단일 상속 (single inheritance)
	- 부모 클래스 하나를 자식 클래스 하나에 상속
	- 부모 1 : 자식 1
*/

#include <iostream>

using std::cout;
using std::endl;

class base
{
protected:
	void show1(){
		cout << "base ] protected show" << endl;		
	}

public:
	base();
	~base();
	void show2(){
		cout << "base ] public show" << endl;		
	}

private:

};

base::base()
{

}

base::~base()
{
}


//class derived : private base
class derived : public base
// 상속받을때 키워드 보다 parent 일때 우선순위가 더 높다.
{
public:
	derived();
	~derived();
	void show(){
		this->show1();
	}
private:

};

derived::derived()
{
}

derived::~derived()
{
}

class GrandDerived : public derived
{
public:
	GrandDerived();
	~GrandDerived();

private:

};

GrandDerived::GrandDerived()
{
}

GrandDerived::~GrandDerived()
{
}

/*
	main
*/
void main(){
	derived child;
	child.show();
	//child.show1(); // public이 상속되면 보임
	//child.show2(); // private으로 상속되면 보이긴 하지만 권한이 없어서 실행할수 없다.

	//
	base *pbase = nullptr;
	pbase = new derived();  // 부모의 포인터를 만들어서 자식클래스로 생성이 가능
							// 상속 구조기 때문에 가능, 							

	delete pbase;
	pbase = nullptr;

	// 
	base *pbase = new GrandDerived(); // 손자 클래스로 생성

	//
	derived *pder = nullptr;
	pder = new derived();

	//// ex
	//minion* pmini1 = new miniMelee;
	//minion* pmini2 = new miniRange;
	//minion* pmini3 = new miniMagic;

	//// 어떤 미니언이 생성되던간에 매니저에서 관리해줄수 있다.
	//// 뒤에 뭐가 나오든 간에
	//MiniList->push(pmini1);
	//MiniList->push(pmini2);
	//MiniList->push(pmini3);
	
	delete pbase;
	pbase = nullptr;
}