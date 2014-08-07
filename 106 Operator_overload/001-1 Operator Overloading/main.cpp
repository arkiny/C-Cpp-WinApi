/*
	Operator ������
	= + -
	>> <<
	+= -=
	++ --

	������ �����ڵ�
	+ - * / % ^ & | ~ ! = < > += -= *= /= %= &= |=
	<< >> >>= <<= == != <= >= && || ++
	-- , ���...

	�����ε� �Ұ����� �����ڵ�
	sizeof . .* :: ?:

	Operator Overloading ������
	- �Լ��� �������� ���·� ��ȯ
	- �˱⽱��. ������.

	Important Property!
	- ���װ� ���� ������ �� �ľ�����
	
	���� ]] 
		bool bflag = (pt == pt2);
		float fx = pt[0]; // �迭ó�� ���µ�, ������ fX�� ����
		float fy = pt[1]; // ������ fY�� ����
		pt[2] -> error ó��
		!pt // ��ȣ�ٲٱ�
*/

#include <iostream>

using std::cout;
using std::endl;

typedef class point{
public:
	// ������ ȣ��� ���ÿ� �ʱ�ȭ
	point(float x, float y){
		cout << "--- constructor 3 ---" << endl;
		fX = x;
		fY = y;
	}

	~point(){
	}

	point& operator+(const point &rhs);
	point& operator-(const point &rhs);
	point& operator*(const point &rhs);
	point& operator/(const point &rhs);

	void operator()();

	point& add(const point &pt);

public:
	void show();

private:
	float fX = 0.0f;
	float fY = 0.0f;
}POINT;

point& point::add(const point& rp){
	fX = fX + rp.fX;
	fY = fY + rp.fY;
	return *this;
}

point& point::operator+(const point &rhs){
	fX = fX + rhs.fX;
	fY = fY + rhs.fY;
	return *this;
}

point& point::operator-(const point &rhs){
	fX = fX - rhs.fX;
	fY = fY - rhs.fY;
	return *this;
}

point& point::operator*(const point &rhs){
	fX = fX * rhs.fX;
	fY = fY * rhs.fY;
	return *this;
}

point& point::operator/(const point &rhs){
	fX = fX / rhs.fX;
	fY = fY / rhs.fY;
	return *this;
}

void point::operator()(){
	this->show();
}

void point::show(){
	cout << "fX = " << fX << ", fY = " << fY << endl;
}

/*
main
*/
void main(){
	POINT pt(1.2f, 7.8f);
	POINT pt2(5.5f, 6.6f);

	pt = pt + pt2;

	pt.show();
	pt();

}