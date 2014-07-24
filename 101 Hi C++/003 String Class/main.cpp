/*
	String Class
*/

#include <iostream>
#include <string>

// ���� : ������ ������
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
	//wstring wstr1 = L"�����ڵ� ����� ��Ʈ��";
	
	
	cout << str1 << endl;
	cout << "string class ũ�� = " << sizeof(str1) << endl;
	cout << "string class ���ڼ� = " << str1.length() << endl;
	//wcout << wstr1 << endl;

	//���ڿ� �����
	str1 = "Another String !";
	cout << str1 << endl;
	cout << "string class ũ�� = " << sizeof(str1) << endl;
	cout << "string class ���ڼ� = " << str1.length() << endl;

	// ���ڿ� ���ϱ�
	str1 += " Added String";
	cout << str1 << endl;
	cout << "string class ũ�� = " << sizeof(str1) << endl;
	cout << "string class ���ڼ� = " << str1.length() << endl;

	// �迭�� ȣȯ
	char arrStr[30] = {};
	strcpy(arrStr, str1.c_str());
	cout << arrStr << endl;

	// str.find("Ano") ���° ��ġ�� �ִ��� �߷�
	std::size_t found = str1.find("Str");
	cout << "Str�� " << found << "��° ��ġ�� �ֽ��ϴ�." << endl;

}

/*
	���� ]

	String class Ȱ��
	compare Ȱ�� or find Ȱ��
	c : str[][10] = { "first", "second", "third" };
	c++ : string[5] = .....;

	�ټ����� �ܾ� �迭
	___, ___, ___, ___, ___

	�Է� : ___
	�ش� �ܾ ����

	�꼺�� ���� 
*/