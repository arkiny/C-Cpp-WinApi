#include <iostream>
#include "MainMenuScreen.h"
using std::cout;
using std::endl;
using std::cin;

MainMenuScreen::MainMenuScreen()
{
}

MainMenuScreen::MainMenuScreen(CharacterManager& input){
	bool exit_call = false;
	char keyinput = 0;
	while (!exit_call){
		cout << "��� ������" << endl;
		cout << "1. �ű� ��� ���" << endl;
		cout << "2. ��� ��� ��ü����" << endl;
		cout << "x. ����" << endl;
		cout << "�Է� : ";
		cin >> keyinput;
		switch (keyinput)
		{
		case '1':
			while (input.addCharacter()); // infinity loop until add done
			break;
		case '2':
			input.showAll();
			system("pause");
			break;
		case 'x':
		case 'X':
			exit_call = true;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		system("cls");
	}
}

MainMenuScreen::~MainMenuScreen()
{
}