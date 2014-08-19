/*
	namespace 이름영역
	:: 범위 연산자 ( scope resolution operator )

	일부만 적고 tab 누르면 기본 템플릿 열어줌!
*/

#include <iostream>

void main(){
	//1. std::
	std::cout << "std::cout 형태 출력" << std::endl;

	//2. using std::
	using std::cout;
	using std::endl;

	cout << "더이상 std::를 언급하지 않아도 cout, endl을 사용가능" << endl;

	//3. using namespace std
	using namespace std;
	cout << "std 이름영역을 모두 사용한다." << endl;

	int k = 0;
	cin >> k;
}