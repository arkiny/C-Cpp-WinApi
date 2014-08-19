/*
	template_class
*/

#include <iostream>

using std::cout;
using std::endl;

#define TMLPLC template<typename T>

// template은 타입네임이 들어갈 자리에
// time을 정해주게 하는 문법을 넣어주는것
// 아.. 솔솔 기억난다 Generic.....
//template < typename T >
TMLPLC
class Point
{
public:
	Point(){};
	~Point(){};

public:
	void set(T x, T y);
	void show() const;

private:
	T x_ = 0;
	T y_ = 0;
} ;

typedef Point<int> POINT;


//template < typename T >
TMLPLC
void Point<T>::set(T x, T y){
	x_ = x;
	y_ = y;
}

//template < typename T >
TMLPLC
void Point<T>::show() const{
	cout << x_ << ", " << y_ << endl;
}


void main(){
	Point<int> p1;
	p1.set(5, 6);
	p1.show();
}