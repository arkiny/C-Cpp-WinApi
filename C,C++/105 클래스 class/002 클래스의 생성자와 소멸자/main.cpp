/*
	생성자 (consturctor) & 소멸자(destructor), 파괴자(destroyer)
	- 생성자 : Class 객체를 생성하면, 가장 먼저 실행
	- 소멸자 : Class 객체가 사라질때, 가장 마지막에 실행
	
	- 생성자와 소멸자는 클래스의 이름과 동일
		~ (tilde) 소멸자의 앞에 붙여준다.
	- 생성자와 소멸자는 반환값이 없다. (return 없다)
	- 생성자와 소멸자는 생성시 생성자가, 소멸시 소멸자가 자동 호출된다.

	- 생성자는 클래스 내부의 데이터를 초기화 할때 사용한다.
	- 소멸자는 클래스 내부의 데이터를 뒷정리 할때 사용한다.
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

	void setPoint(int inputX, int inputY); // 멤버 함수
	void showPoint();

private:
	int x; // 멤버변수 (member variable)
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