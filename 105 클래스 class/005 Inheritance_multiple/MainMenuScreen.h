/*
MainMenu 출력을 위한 클래스
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

