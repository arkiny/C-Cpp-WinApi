/*
	���� ��� (single inheritance)
	- �θ� Ŭ���� �ϳ��� �ڽ� Ŭ���� �ϳ��� ���
	- �θ� 1 : �ڽ� 1
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
// ��ӹ����� Ű���� ���� parent �϶� �켱������ �� ����.
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
	//child.show1(); // public�� ��ӵǸ� ����
	//child.show2(); // private���� ��ӵǸ� ���̱� ������ ������ ��� �����Ҽ� ����.

	//
	base *pbase = nullptr;
	pbase = new derived();  // �θ��� �����͸� ���� �ڽ�Ŭ������ ������ ����
							// ��� ������ ������ ����, 							

	delete pbase;
	pbase = nullptr;

	// 
	base *pbase = new GrandDerived(); // ���� Ŭ������ ����

	//
	derived *pder = nullptr;
	pder = new derived();

	//// ex
	//minion* pmini1 = new miniMelee;
	//minion* pmini2 = new miniRange;
	//minion* pmini3 = new miniMagic;

	//// � �̴Ͼ��� �����Ǵ����� �Ŵ������� �������ټ� �ִ�.
	//// �ڿ� ���� ������ ����
	//MiniList->push(pmini1);
	//MiniList->push(pmini2);
	//MiniList->push(pmini3);
	
	delete pbase;
	pbase = nullptr;
}