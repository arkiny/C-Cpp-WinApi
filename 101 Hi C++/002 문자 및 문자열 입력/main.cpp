#include <iostream>

using namespace std;

void main(){
	//문자입력
	//cout << 
	char str[20] = {};

	// 띄어쓰기가 있으면 처리 안됨
	// str 주소
	/*cin >> str;
	cout << str << endl;*/

	// 띄어쓰기 처리
	cin.getline(str, 20);
	cout << str << endl;
}