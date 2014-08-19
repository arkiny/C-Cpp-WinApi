/*
	template _ functon

	- Ʋ, ��Ʋ ... ���� Ÿ���� �������� ���� 
*/

#include <cmath>
#include <iostream>

using std::pow;
using std::sqrt;
using std::cout;
using std::endl;

#define TMPL template < typename T >
#define TMPL(T) template < typename T >

/*
	Prototype
*/
int ABS(int in);
int ABS2(int in);

TMPL(T)
T ABSw(T in);

/*
	main
*/
void main(){
	// absolute ���밪 ���ϱ� �Լ�
	int a = ABS(-4); 
	int b = ABS(-4); // int
	cout << a << endl; 
	cout << b << endl;

	auto c = ABSw(-4.47f); // float
	cout << "ABS=" << c << ", size=" << sizeof(c) << endl;
	auto d = ABSw(-6.12); // double
	cout << "ABS=" << d << ", size=" << sizeof(d) << endl;
}

/*
	ABS functions
*/
int ABS(int in){
	return sqrt(pow(in, 2));
}

int ABS2(int in){
	if (in < 0)	return -in;
	else return in;	
}

TMPL(T)
T ABSw(T in){
	return sqrt(pow(in, 2));
}