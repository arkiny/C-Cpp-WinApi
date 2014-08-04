/*
	Physical, Leadership, Intelligence를 상속받아
	처리하는 클래스
*/

#pragma once

#include <string>
#include "Physical.h"
#include "Leadership.h"
#include "Intelligence.h"

using std::string;

class character : public Physical, public Leadership, public Intelligence
{
public:
	// default constructr
	character();

	// destructor
	~character();

	// set general's name
	// @param string name
	void setName(string);

	// get general's name
	// @return string general's name
	string getName();

	// show all inherited class to console
	void show();

	// @return int sum of all ability points
	int getPowerLevel();

	// print out sum of all ability points
	void showPowerLevel();

private:
	string name; // general's name
	int battle_power; // sum of general's ability
};