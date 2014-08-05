/*
	통솔수치 관리
	차후 수치에따른 특성 추가
*/
#pragma once

class Leadership /*: public IStateect*/
{
public:
	// consturctor
	Leadership();

	// destructor
	~Leadership();

	// print out to console
	void show();

	// set leadership
	// @param int 
	void setLeadership(int);

	// @return leadership oint
	int getLeadership();

private:
	int nLeadership;
};

