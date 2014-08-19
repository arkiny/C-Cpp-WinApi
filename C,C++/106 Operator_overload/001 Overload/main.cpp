/*
	Operator ������
	= + -
	>> <<
	+= -=
	++ --

	������ �����ڵ�
	+ - * / % ^ & | ~ ! = < > += -= *= /= %= &= |=
	<< >> >>= <<= == != <= >= && || ++
	-- , 

	�����ε� �Ұ����� �����ڵ�


	Operator Overloading ������
	- �Լ��� �������� ���·� ��ȯ
	- �˱⽱��. ������.
*/

#include <iostream>

using std::cout;
using std::endl;

typedef class point{
public:
	// default constructor
	point() : fX(1.0f), fY(1.0f) // �⺻ �ʱ�ȭ(Old school)
	{
		cout << "--- constructor 1 ---" << endl;
	};
	
	// Second constructor
	// deep copy
	point(point& p){ 
		cout << "--- constructor 2 ---" << endl;
		// 1. p�� �������� ���ͼ� ī��
		/*fX = p.fX;
		fY = p.fY;*/

		// 2. p�� ��°�� ����
		*this = p;
	}

	// third constructor
	// ������ ȣ��� ���ÿ� �ʱ�ȭ
	point(float x, float y){
		cout << "--- constructor 3 ---" << endl;
		fX = x;
		fY = y;
	}

	~point(){
		cout << "--- destructor ---" << endl;
	}

	point &operator+(const point &rhs){
		fX = fX + rhs.fX;
		fY = fY + rhs.fY;
		return *this;
	}

public:
	void show();

private:
	float fX = 2.0f;
	float fY = 2.0f;
}POINT;

void point::show(){
	cout << "fX = " << fX << ", fY = " << fY << endl;
}

/*
	main
*/
void main(){
	// ������1
	POINT pt;
	pt.show();

	POINT pt1(1.2f, 3.4f);
	
	// ������3
	POINT pt2 = POINT(5.6f, 7.8f);

	pt1.show();
	pt2.show();

	// ������2
	POINT* pt3 = new POINT(pt1);
	pt3->show();

	//POINT* pt2 = new POINT(1.2f, 3.4f);
	//POINT p2 = POINT(1.2f, 3.4f);

	pt = pt1 + pt2;
	pt.show();

	delete pt3;
}