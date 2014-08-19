/*
	지력수치 관리
	차후 수치에따른 특성 추가
*/
#pragma once

class Intelligence /*: public IStateect*/
{
public:
	// consturctor
	Intelligence();

	// constructor with one int parameter which will be saved
	// into IQ score variable
	Intelligence(int);

	// destructor
	~Intelligence();

	// print out nIQ ability to console
	void show();

	// set IQ
	// @param int input IQ
	void setIQ(int);

	// @return IQ ability points
	int getIQ();

private:
	int nIQ;			// IQ score
};

