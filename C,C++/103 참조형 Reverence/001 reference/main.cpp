/*
	���� ( reference ) // ���纻�� ������ �������ش�.
	&	�ּ� ǥ��
	&&	and operator
	&	c++] reference
	- ������ �̸� ��� ���� ��� �̸� : ����
	- ����� �н������� ������ ������ �ش�.
	- ���� ����� ������, �ּ��� ������ �Ѵ�.
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
//	// 1. pwallet�� money�� �ּҸ� ����
//	// pwallet money�� �ּҸ� ���� ��
//	char *pwallet = &money;
//
//	// 2. rwallet ���۷����� money�� ���� ����
//	// rwallet�� money�� ���� �޾�����,
//	// �����δ� �ּҸ� ������ �ְ�, �װ� ���� �����ϴ� ���̴�.
//	char &rwallet = money;
//
//	cout << "rwallet = " << (int)rwallet << endl
//		 << "rwallet address = " << (int)&rwallet << endl
//		 << "money address = " << (int)&money << endl; // should be same with above, yes same
//
//	rwallet -= 10;
//	cout << "money = " << (int)money << endl; // 2000
//	// reference�� �߿��� ������ �Լ��Ӹ� �ƴ϶� �� class�� ���ؼ� �ʿ��ϴ�.
//	// namespace, reference �� �׷��� ��� �߿��ϴ�.
//
//	// 3. rwallet�� ũ��? ���� pointer�� 4����Ʈ
//	cout << "size of rwallet = " << sizeof(rwallet) << endl; // 1 bytes, pwallet �� ��ü��..
//
//	// 4. �Լ�ȭ �غ���
//	moneyExchange(rwallet, 40);
//	cout << "changed rwallet = " << (int)rwallet << endl;
//}
//
//void moneyExchange(char &input, char cinput){
//	// ��� input == money �̹Ƿ�....
//	input = cinput;
//}


// prototype
void moneyExchange(int &input, int cinput);

void main(){
	int money = 30;

	// 1. pwallet�� money�� �ּҸ� ����
	// pwallet money�� �ּҸ� ���� ��
	int *pwallet = &money;

	// 2. rwallet ���۷����� money�� ���� ����
	// rwallet�� money�� ���� �޾�����,
	// �����δ� �ּҸ� ������ �ְ�, �װ� ���� �����ϴ� ���̴�.
	int &rwallet = money;

	cout << "rwallet = " << rwallet << endl
		<< "rwallet address = " << &rwallet << endl
		<< "money address = " << &money << endl; // should be same with above, yes same

	rwallet -= 10;
	cout << "money = " << money << endl; // 2000
	// reference�� �߿��� ������ �Լ��Ӹ� �ƴ϶� �� class�� ���ؼ� �ʿ��ϴ�.
	// namespace, reference �� �׷��� ��� �߿��ϴ�.

	// 3. rwallet�� ũ��? ���� pointer�� 4����Ʈ
	cout << "size of rwallet = " << sizeof(rwallet) << endl; // 4 bytes, pwallet �� ��ü��..

	// 4. �Լ�ȭ �غ���
	moneyExchange(rwallet, 40);
	cout << "changed rwallet = " << rwallet << endl;
}

void moneyExchange(int &input, int cinput){
	// ��� input == money �̹Ƿ�....
	input = cinput;
}