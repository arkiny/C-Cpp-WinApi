/*
	참조 ( reference ) // 복사본이 원본에 영향을준다.
	&	주소 표현
	&&	and operator
	&	c++] reference
	- 변수의 이름 대신 쓰는 대용 이름 : 별명
	- 복사된 분신이지만 원본에 영향을 준다.
	- 값의 모양을 띄지만, 주소의 역할을 한다.
*/

#include <iostream>

using std::cout;
using std::endl;

//// prototype
//void moneyExchange(char &input, char cinput);
//
//void main(){
//	char money = 30; 
//
//	// 1. pwallet에 money의 주소를 전달
//	// pwallet money의 주소를 받은 것
//	char *pwallet = &money;
//
//	// 2. rwallet 레퍼런스에 money의 값을 전달
//	// rwallet은 money의 값을 받았지만,
//	// 실제로는 주소를 가지고 있고, 그걸 토대로 수정하는 것이다.
//	char &rwallet = money;
//
//	cout << "rwallet = " << (int)rwallet << endl
//		 << "rwallet address = " << (int)&rwallet << endl
//		 << "money address = " << (int)&money << endl; // should be same with above, yes same
//
//	rwallet -= 10;
//	cout << "money = " << (int)money << endl; // 2000
//	// reference가 중요한 이유는 함수뿐만 아니라 각 class를 위해서 필요하다.
//	// namespace, reference 도 그렇고 모두 중요하다.
//
//	// 3. rwallet의 크기? 원래 pointer는 4바이트
//	cout << "size of rwallet = " << sizeof(rwallet) << endl; // 1 bytes, pwallet 그 자체다..
//
//	// 4. 함수화 해보기
//	moneyExchange(rwallet, 40);
//	cout << "changed rwallet = " << (int)rwallet << endl;
//}
//
//void moneyExchange(char &input, char cinput){
//	// 사실 input == money 이므로....
//	input = cinput;
//}


// prototype
void moneyExchange(int &input, int cinput);

void main(){
	int money = 30;

	// 1. pwallet에 money의 주소를 전달
	// pwallet money의 주소를 받은 것
	int *pwallet = &money;

	// 2. rwallet 레퍼런스에 money의 값을 전달
	// rwallet은 money의 값을 받았지만,
	// 실제로는 주소를 가지고 있고, 그걸 토대로 수정하는 것이다.
	int &rwallet = money;

	cout << "rwallet = " << rwallet << endl
		<< "rwallet address = " << &rwallet << endl
		<< "money address = " << &money << endl; // should be same with above, yes same

	rwallet -= 10;
	cout << "money = " << money << endl; // 2000
	// reference가 중요한 이유는 함수뿐만 아니라 각 class를 위해서 필요하다.
	// namespace, reference 도 그렇고 모두 중요하다.

	// 3. rwallet의 크기? 원래 pointer는 4바이트
	cout << "size of rwallet = " << sizeof(rwallet) << endl; // 4 bytes, pwallet 그 자체다..

	// 4. 함수화 해보기
	moneyExchange(rwallet, 40);
	cout << "changed rwallet = " << rwallet << endl;
}

void moneyExchange(int &input, int cinput){
	// 사실 input == money 이므로....
	input = cinput;
}