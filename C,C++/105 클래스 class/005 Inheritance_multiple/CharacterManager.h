/*
	ĳ���� �������� �����ϴ� ������ �Ŵ���
*/

#pragma once

#include <vector>
#include "State.h"

using std::vector;

class StateManager
{
public:
	StateManager();
	~StateManager();
	
	// add State from user input
	// @return bool user input end?
	bool addState();

	// print all State property to console
	void showAll();

private:
	vector<State*> vCharData;
};

