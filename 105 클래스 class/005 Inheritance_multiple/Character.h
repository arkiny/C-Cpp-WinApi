#pragma once

#include <string>
#include "Arm.h"
#include "Leg.h"

using std::string;
/*
	
*/
class character : public Arm, public Leg
{
public:
	character();
	~character();
	void setName(string input_str)	{ name = input_str; }
	string getName()				{ return name; }
	void show();

private:
	string name;
};