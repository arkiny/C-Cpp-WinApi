/*
	Operator 연산자
	= + -
	>> <<
	+= -=
	++ --

	가능한 연산자들
	+ - * / % ^ & | ~ ! = < > += -= *= /= %= &= |=
	<< >> >>= <<= == != <= >= && || ++
	-- , 등등...

	오버로딩 불가능한 연산자들
	sizeof . .* :: ?:

	Operator Overloading 재정의
	- 함수를 연산자의 형태로 변환
	- 알기쉽다. 직관적.

	Important Property!
	- 단항과 이항 성격을 잘 파악하자
	
	과제 ]] 
		bool bflag = (pt == pt2);
		float fx = pt[0]; // 배열처럼 쓰는데, 내부의 fX를 리턴
		float fy = pt[1]; // 내부의 fY를 리턴
		pt[2] -> error 처리
		!pt // 부호바꾸기
*/

#include <iostream>

using std::cout;
using std::endl;

typedef class point{
public:
	// 생성자 호출과 동시에 초기화
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