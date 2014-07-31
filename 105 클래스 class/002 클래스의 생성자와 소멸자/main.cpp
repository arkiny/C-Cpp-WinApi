/*
	������ (consturctor) & �Ҹ���(destructor), �ı���(destroyer)
	- ������ : Class ��ü�� �����ϸ�, ���� ���� ����
	- �Ҹ��� : Class ��ü�� �������, ���� �������� ����
	
	- �����ڿ� �Ҹ��ڴ� Ŭ������ �̸��� ����
		~ (tilde) �Ҹ����� �տ� �ٿ��ش�.
	- �����ڿ� �Ҹ��ڴ� ��ȯ���� ����. (return ����)
	- �����ڿ� �Ҹ��ڴ� ������ �����ڰ�, �Ҹ�� �Ҹ��ڰ� �ڵ� ȣ��ȴ�.

	- �����ڴ� Ŭ���� ������ �����͸� �ʱ�ȭ �Ҷ� ����Ѵ�.
	- �Ҹ��ڴ� Ŭ���� ������ �����͸� ������ �Ҷ� ����Ѵ�.
*/
#include <iostream>

using std::cout;
using std::endl;

class Point{
public:
	// Basic Constructor
	Point();
	// Constructor
	// @param int inputX
	// @param int inputY
	Point(int inputX, int inputY);

	// Destructor
	~Point();

	// return value of x
	// @return int
	int getX();

	// return value of x
	// @return int
	int getY();

	void setPoint(int inputX, int inputY); // ��� �Լ�
	void showPoint();

private:
	int x; // ������� (member variable)
	int y;
};

void Point::setPoint(int inputX, int inputY){
	x = inputX;
	y = inputY;
}

void Point::showPoint(){
	cout << "Point : " << x << ", " << y << endl;
}

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int inputX, int inputY){
	Point::x = inputX;
	Point::y = inputY;
	cout << ">>> Constructor Call <<<" << endl;
}

Point::~Point(){
	cout << ">>> Destructor Call <<<" << endl;
}

int Point::getX(){
	return Point::x;
}

int Point::getY(){
	return Point::y;
}

void main(){

	Point pos = Point(5,6);	
	cout << "Point : " << pos.getX() << "," << pos.getY() << endl;
	pos.setPoint(7, 8);
	pos.showPoint();

	Point pos1 = Point();
	pos1.showPoint();

}