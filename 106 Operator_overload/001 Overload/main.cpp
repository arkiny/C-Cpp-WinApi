/*
	Operator 연산자
	= + -
	>> <<
	+= -=
	++ --

	가능한 연산자들
	+ - * / % ^ & | ~ ! = < > += -= *= /= %= &= |=
	<< >> >>= <<= == != <= >= && || ++
	-- , 

	오버로딩 불가능한 연산자들


	Operator Overloading 재정의
	- 함수를 연산자의 형태로 변환
	- 알기쉽다. 직관적.
*/

#include <iostream>

using std::cout;
using std::endl;

typedef class point{
public:
	// default constructor
	point() : fX(1.0f), fY(1.0f) // 기본 초기화(Old school)
	{
		cout << "--- constructor 1 ---" << endl;
	};
	
	// Second constructor
	// deep copy
	point(point& p){ 
		cout << "--- constructor 2 ---" << endl;
		// 1. p의 변수들을 떠와서 카피
		/*fX = p.fX;
		fY = p.fY;*/

		// 2. p를 통째로 떠옴
		*this = p;
	}

	// third constructor
	// 생성자 호출과 동시에 초기화
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
	// 생성자1
	POINT pt;
	pt.show();

	POINT pt1(1.2f, 3.4f);
	
	// 생성자3
	POINT pt2 = POINT(5.6f, 7.8f);

	pt1.show();
	pt2.show();

	// 생성자2
	POINT* pt3 = new POINT(pt1);
	pt3->show();

	//POINT* pt2 = new POINT(1.2f, 3.4f);
	//POINT p2 = POINT(1.2f, 3.4f);

	pt = pt1 + pt2;
	pt.show();

	delete pt3;
}