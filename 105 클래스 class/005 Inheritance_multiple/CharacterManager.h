/*
	ĳ���� �������� �����ϴ� ������ �Ŵ���
*/

#pragma once

#include <vector>
#include "Character.h"

using std::vector;

class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();
	
	// add character from user input
	// @return bool user input end?
	bool addCharacter();

	// print all character property to console
	void showAll();

private:
	vector<character*> vCharData;
};

