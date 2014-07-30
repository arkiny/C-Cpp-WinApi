/*����]

	@author		Heedong Arkiny Lee
	@date		07292014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Original Specification -------------------------------------
	����� ���� ]]

	pet ����ü ���� ]]
		- �̸�,������
	
	�� ))

	ö�� 20�ϰ� �ؿܿ����� ������
	"�ٷ���"�� "�߷���"�� ���ڿ��� �ñ��
	���̸� �Ϸ翡 �ѹ� �ش�

	���̸� ������ ������ 1�� ����
	���̸� �������� ������ 2�� ����
	�������� 0�� �Ǹ� ����

	20�ϰ� ��Ƽ��

	�Լ� ]] & ���·� ����ü ����

	-------------------------------------------------------------
	������ ��(�����غ� ��) -
	1. ����ü ��ſ� ����ü �ּҸ� ���� vector�� &���·� ����
		-> pointer�� reference�� ����!
	2. vector�� �̿������Ƿ� ����� ���ڰ� �����ӱ� ������,
		���̵� ������ ����� ���ڷ� �ǽ�

	�� �� ������ ���� ���� ��
	1. ���⼭ double pointer�� �̿��Ѵٸ�?
	2. ���⼭ double pointer�� ���� �ʿ�����?
	------------------------------------------------------------
	
	���� ���� �������̽��� �ȳ���
*/

#include <iostream> // cout, cin, endl
#include <string>	// string
#include <vector>	// vector
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Global Constant Variable
const unsigned int DEFAULT_AFFECTION_POINT = 25; // default affection point
const string catName[] = { "����", "����", "����", "����", 
						"�˷�", "����", "����", "����", 
						"����", "����", "ȣ��", "���" };

typedef struct cat {
	string name;							// ����� �̸�
	unsigned int affection_point;			// ������

	// ����̰� ���������� �ȵ��������� Ȯ��
	bool isRunAway(){
		return affection_point <= 0;
	}

	// ���� ���� ���
	void feed(){
		affection_point += 1;
	}

	// ���� ������ ���
	void no_feed(){
		affection_point -= 2;
	}
}CAT;

//prototype
void screenRender(vector<CAT*> &input, int day);
void initCats(vector<CAT*> &input, int size);
void clearCats(vector<CAT*> &input);
int startScreen();
void printBadEnding();
void printGoodEnding();
bool step_feed(vector<CAT*> &input, int select);

//main
void main(){
	// seeding
	srand(time(NULL));

	// var init
	int day = 0; // ����
	int nCat = 0; // ����� ��
	int choice = 0; // ����
	bool badEnding = false;
	vector<CAT*> cats; // ����̵� �޸� �ּҰ���

	// ùȭ�� ��°� ���ÿ� ����� ���ڸ� ���Ѵ�.
	nCat = startScreen();

	// ����� ����ŭ ����� �ʱ�ȭ
	// @�̸� ó���Ҽ� �ְ�?
	initCats(cats, nCat); // ���� ���۽� ����� ���� ������ �ְ� ó��


	while (day != 21){
		screenRender(cats, day);
		cin >> choice;
		badEnding = step_feed(cats, choice);
		if (badEnding){			
			break;
		} // if
		day++;
		system("cls");
	} // while

	if (badEnding){
		printBadEnding();
	}
	else {
		printGoodEnding();
	}// if

	// �޸� ����
	clearCats(cats);
}// main

// �Է��� ����ŭ ����� ����
// �����Ҵ� �̿�
// @param vector<CAT*> &input, CAT�ּҵ��� ����(������ ����)
// @param int size �߰��� ����̵� ����
void initCats(vector<CAT*> &input, int size){
	//@todo ����� �̸� ó��
	//�����Ϳ� ���۷����� ����! ���� �ڵ尡 ���⽺�� �������±���!
	void *ptr = nullptr;
	for (int i = 0; i < size; i++){
		// ���� �Ҵ�
		ptr = new CAT({ catName[rand() % 12], DEFAULT_AFFECTION_POINT });
		input.push_back((CAT*)ptr);
	}
	ptr = nullptr;
} // initCats

// ����̵��̶� ����� �ڿ�
// ������ ����̰� ������ �ٷ� ���μ����� ���߰� ��Ȳ�� �����Ѵ�.
// @param vector<CAT*> &input ����̵�
// @param int select ���� ����� ��ȣ
// @return bool ������ ����̰� �ִ°�?
bool step_feed(vector<CAT*> &input, int select){
	bool ret = false;
	for (int i = 0; i < input.size(); i++){
		if (select - 1 == i){
			input.at(i)->feed();
		}
		else {
			input.at(i)->no_feed();
			if (input.at(i)->isRunAway()){
				ret = true;
				break;
			}
		}
	}
	return ret;
}// step_feed

// �޸� ����
// @param vector<CAT*> &input �޸� ������ ���� vector
void clearCats(vector<CAT*> &input){
	void *ptr = nullptr;
	while (!input.empty()){
		ptr = input.back();
		delete ptr;
		input.pop_back();
		ptr = nullptr;
	}
} // clearCats

// ùȭ��, ���� �� ����� ���ڸ� �Է¹޾Ƽ� �����Ѵ�.
// @return �Է¹��� ����� ����
int startScreen(){
	int ret = 0;
	cout << "����� ������ �����ϱ�" << endl
		<< "------------------------------------------------------------" << endl
		<< "�� ���α׷��� ����̵���� �������� �����ϸ鼭" << endl
		<< "20�ϰ� ����̵��� �������� 0���Ϸ� �������� �ʰ�," << endl
		<< "�����ϴ� �����Դϴ�." << endl
		<< "���̵��� ���� ��� ������� ���ڷ� �����˴ϴ�." << endl
		<< "------------------------------------------------------------" << endl
		<< "�� ������ ����̿� ���� ��ðڽ��ϱ�?" << endl << endl
		<< "�Է� : ";
	cin >> ret;
	while (ret <= 1){
		cout << "0������ 1�����δ� ������ �����Ҽ� �����ϴ�." << endl << endl
			<< "�ٽ� �Է��� �ּ��� : ";
		cin >> ret;
	}
	system("cls");
	return ret;
} // startScreen

void screenRender(vector<CAT*> &input, int day){
	cout << "����̶� ����ֱ� ����"<< endl
		<< day << " ����" << endl
		<< "------------------------------------------------------------" << endl;
	for (int i= 0; i < input.size(); i++){
		cout << i + 1<<". " << "�̸� : " << input.at(i)->name 
			<< "\t������ : " << input.at(i)->affection_point << endl;
	}
	cout << "------------------------------------------------------------" << endl
		<< "����̵��� ����� ��� �;��մϴ�. ��� ����̿� ����ֽðڽ��ϱ�?" << endl
		<< "(�ش����� ������ 1 ���, �ٸ� ����̵��� ������ ������ 2 �ϰ�)" << endl << endl
		<< "���� : ";
}// screendRender

// ���ǿ��� ���
void printGoodEnding(){
	cout << "�׷��� 20������ ����� ����̵�� ������ �ູ�ϰ� ��Ҵ�ϴ�." << endl
		<< endl
		<< "Happy Ending" << endl;
	system("pause");
}

// ��忣�� ���
void printBadEnding(){
	cout << "����, ����̰� ���������Ⱦ�� �Ф�" << endl
		<< endl
		<< "Game Over" << endl;
	system("pause");
}