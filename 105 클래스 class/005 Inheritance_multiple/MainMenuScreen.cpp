#include <iostream>
#include "MainMenuScreen.h"
using std::cout;
using std::endl;
using std::cin;

MainMenuScreen::MainMenuScreen()
{
}

MainMenuScreen::MainMenuScreen(StateManager& input){
	bool exit_call = false;
	char keyinput = 0;
	while (!exit_call){
		cout << "장수 관리자" << endl;
		cout << "1. 신규 장수 등록" << endl;
		cout << "2. 등록 장수 전체보기" << endl;
		cout << "x. 종료" << endl;
		cout << "입력 : ";
		cin >> keyinput;
		switch (keyinput)
		{
		case '1':
			while (input.addState()); // infinity loop until add done
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		system("cls");
	}
}

MainMenuScreen::~MainMenuScreen()
{
}