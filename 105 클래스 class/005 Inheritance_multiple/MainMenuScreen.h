/*
MainMenu ����� ���� Ŭ����
*/
#pragma once

#include "CharacterManager.h"

class MainMenuScreen
{
public:
	// constructor with no funtion
	MainMenuScreen();

	// constructor which has render main menu screen
	// @param CharacterManager manager which will be shown on the console
	MainMenuScreen(CharacterManager&);
	~MainMenuScreen();

private:
};

