/*
	C plus plus
	C++

	:: scope resoultion operator
	( ���� ������ )
*/

#include <iostream>

using namespace std;

// ������� ���� ���°� �ƴ϶� ��ü�� ���� ����.
// namespace
// class
int main(){
	std::cout << "CPP�� ó�� ����ϱ�" << std::endl;
	std::cout << "���๮�� Ȯ�� \n" << "\n";

	// using ���Ŀ� cout �� endl�� 
	// �׳� cout, endl�� ����ϸ� �ȴ�.
	using std::cout;
	using std::endl;

	enum week {Mo, Tu, We, Th, f};
	week::Mo;

	cout << "using ���� cout" 
		<< endl;

	// cout ��� ��� Ŭ����
	// cin �Է� ��� Ŭ����

	int ncarrot = 0;
	cout << "����� � �Ծ����ϱ�? ";
	
	//ncarrot ��
	cin >> ncarrot;
	cout << "����� " << ncarrot << " �� �Ծ����ϴ�." << endl;

	// ����� 10������ � �Ծ����ϴ�.
	cout << "����� 10������  " << dec << " �� �Ծ����ϴ�." << endl;

	// ����� 16������ � �Ծ����ϴ�.
	cout << "����� 16������ " << hex << ncarrot << endl; 
	
	// ����� 8������ � �Ծ����ϴ�.
	cout << "����� 8������ " << oct << ncarrot << endl;

	// prinf�ʹ� �ٸ���.... class�̹Ƿ� ���ο��� ������ �ٲ�� ������
	// ��� 8������ ����� �ȴ�.
	cout << dec << 10 << endl;

	// ������ ����
	cout << 14.78f << " / " << 9.61f << " = " << 14.78f / 9.61f << endl;

	// ������ ������? printf�� �޸� �� �浹�� ���� �ʴ´�...
	cout.precision(3);
	cout << 14.78f << " / " << 9 << " = " << 14.78f / 9 << endl;
}