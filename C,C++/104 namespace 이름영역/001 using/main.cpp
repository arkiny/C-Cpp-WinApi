/*
	namespace �̸�����
	:: ���� ������ ( scope resolution operator )

	�Ϻθ� ���� tab ������ �⺻ ���ø� ������!
*/

#include <iostream>

void main(){
	//1. std::
	std::cout << "std::cout ���� ���" << std::endl;

	//2. using std::
	using std::cout;
	using std::endl;

	cout << "���̻� std::�� ������� �ʾƵ� cout, endl�� ��밡��" << endl;

	//3. using namespace std
	using namespace std;
	cout << "std �̸������� ��� ����Ѵ�." << endl;

	int k = 0;
	cin >> k;
}