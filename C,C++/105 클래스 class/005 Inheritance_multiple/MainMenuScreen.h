/*
MainMenu ����� ���� Ŭ����
*/
#pragma once

#include "StateManager.h"

class MainMenuScreen
{
public:
	// constructor with no funtion
	MainMenuScreen();

	// constructor which has render main menu screen
	// @param StateManager manager which will be shown on the console
	MainMenuScreen(StateManager&);
	~MainMenuScreen();

private:
};

