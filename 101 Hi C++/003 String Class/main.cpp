/*
	String Class
*/

#include <iostream>
#include <string>

// 장점 : 분할이 가능함
using std::string;
using std::cout;
using std::endl;

using std::wstring;
using std::wcout;

void main(){

	char strArr[20] = "array string";
	strArr[0] = 'a';
	strArr[1] = 'n';
	//...

	string str1 = "String Class";
	//wstring wstr1 = L"유니코드 사용한 스트링";
	
	
	cout << str1 << endl;
	cout << "string class 크기 = " << sizeof(str1) << endl;
	cout << "string class 글자수 = " << str1.length() << endl;
	//wcout << wstr1 << endl;

	//문자열 덮어쓰기
	str1 = "Another String !";
	cout << str1 << endl;
	cout << "string class 크기 = " << sizeof(str1) << endl;
	cout << "string class 글자수 = " << str1.length() << endl;

	// 문자열 더하기
	str1 += " Added String";
	cout << str1 << endl;
	cout << "string class 크기 = " << sizeof(str1) << endl;
	cout << "string class 글자수 = " << str1.length() << endl;

	// 배열과 호환
	char arrStr[30] = {};
	strcpy(arrStr, str1.c_str());
	cout << arrStr << endl;

	// str.find("Ano") 몇번째 위치에 있는지 추력
	std::size_t found = str1.find("Str");
	cout << "Str는 " << found << "번째 위치에 있습니다." << endl;

}

