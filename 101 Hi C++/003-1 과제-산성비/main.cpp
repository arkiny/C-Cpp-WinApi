/*
	@author		Heedong Arkiny Lee
	@date		07242014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	���� ]

	String class Ȱ��
	compare Ȱ�� or find Ȱ��
	c : str[][10] = { "first", "second", "third" };
	c++ : string[5] = .....;

	�ټ����� �ܾ� �迭
	___, ___, ___, ___, ___

	�Է� : ___
	�ش� �ܾ ����

	�꼺�� ����? �񵿱�� �Է��� �ȵǼ� ���ҵ�
	�ǰ��ؼ� ������ ���ο� ������ �����Կ�..
*/

#include <iostream> // std::
#include <string>	// string, strcmp
#include <stdlib.h> // srand(), rand(), _sleep
#include <time.h>	// time()
#include <conio.h> // _getch();


using namespace std;

//  Database... ���߿��� ���Ͽ����� �޾ƿü��� ����
const string DATABASE[25]
= { "GuildWar", "Mabinogi", "Terra", "Aion", "Ragnarok",
"Rift", "City Racer", "Starcraft", "Command and Conquer", "Genesis",
"Granado Espada", "League of Legends", "Diablo", "Rainbow6", "Ghost Recon",
"Endwar", "HAWX", "Tropico", "Walking Dead", "Mirror's Edge",
"Battlefield", "Call of Duty", "Halflife", "Portal", "Team Fortress2"};

//prototype;
void showArray(string *input_array);
void var_init(string *input, string *input_array, int *score);
void upper_UI();

void main(){

	// Random Seed
	srand(time(NULL));

	// Variable Init
	// �Է¹��� ����
	string input = "";
	// DATABASE���� �������� ���ڿ��� �ҷ��� ȭ�鿡 ����Ѵ�.
	string output_string[5]	= {}; 
	int score = 0;
	time_t startTime = 0;
	time_t endTime = 0;
	time_t typingTime = 0;
	int combo = -1;
	int temp_score = -1;

	// ���� ���� �Է�
	var_init(&input, output_string, &score);


	// ���� ȭ�� ���
	upper_UI();
	cout << "���� ���� : " << score << endl;
	cout << "------------------------------" << endl;
	showArray(output_string);
	cout << "�ð��� ������Ʈ�� ��Ÿ���� ��� ���Ǹ�," << endl;
	cout << "�ƹ�Ű�� ġ�ø� ������ ���۵˴ϴ�." << endl;
	_getch();
	system("cls");

	// strcmp �޼ҵ�� �� string�� ��� ������ 0
	// ù���ڰ� �ٸ��� ���Ŀ� ���� ���� Ȥ�� ����� ������� �����Ѵ�.

	while (strcmp(input.c_str(), "exit") != 0){ // Ȥ�� exit break�� �Ȱɸ��� ���
		
		upper_UI();

		cout << "���� ���� : " << score << endl;
		cout << "------------------------------" << endl;
		showArray(output_string);
		
		cout << "�Է� : ";
		
		// ������Ʈ�� �߰��� Ÿ�� ġ�� �ð� ���
		startTime = time(NULL);
		getline(cin, input);
		endTime = time(NULL);
		typingTime = endTime - startTime;

		// ���Ḧ ���ҽ�
		if (strcmp(input.c_str(), "exit") == 0) {
			cout << "\n�������� : \n" << score << endl;
			cout << "���α׷� ����" << endl;
			break;
		}

		cout << "�Է¹��� �ܾ� : " << input << endl;
		
		// �� ������ �������� �޺��� score ����� �ʱ�ȭ
		combo = 0;
		temp_score = 0;
		for (int i = 0; i < 5; i++){
			// ���� ���� �� ã�Ƴ������, ������ �ʿ��� ����� ��ģ�ڿ�,
			// �� �ڸ��� ���ο� ���ڿ��� ä���ִ´�.
			if (strcmp(input.c_str(), output_string[i].c_str()) == 0){
				combo++;
				cout << output_string[i] << "-�Է� ����" << endl;
				temp_score = combo*input.length() - typingTime;
				cout << combo << "�޺� * " << input.length() << " �ܾ���� -" << typingTime << "�ð� = " << endl;
				cout << temp_score << "�����ϼ̽��ϴ�." << endl;
				score = temp_score + score;
				cout << "������� ���� : " << score << endl;

				output_string[i] = DATABASE[rand() % 25];
			}
			// ��Ÿ�����ÿ�
			else if (i == 4){
				score = score - 10;
				cout << "No such a word, ���� ���� - 10��" << endl;
			}
			else{
				// do nothing
			}
		}
		_sleep(1000);
		system("cls");
	}
}

// ���� ���� init
void var_init(string *input, string *input_array, int *score){
	*input = "";
	for (int i = 0; i < 5; i++){
		input_array[i] = DATABASE[rand() % 25];
	}
	*score = 0;
}

// ������ ��� ��� �Լ�
void showArray(string *input_array){
	for (int i = 0; i < 5; i++){
		cout << input_array[i] << " | ";
	}
	cout << endl;
}

// ui ���
void upper_UI(){
	cout << "����" << endl;
	cout << "SGA51A" << endl;
	cout << "07242014 ����" << endl;
	cout << "�Ʒ��� �����ִ� �ܾ��� �ϳ��� �Է��� �����ϼ���." << endl;
	cout << "�޺�(�ѹ��� ���� ĭ�� ������ ��) * �ð�(s) * �ܾ���̼��� �������˴ϴ�." << endl;
	cout << "����� exit�� ���ּ���." << endl;
	cout << "------------------------------------------------------------------" << endl;
}