/*
	무력 능력치
*/

#pragma once

class Physical /*: public IGameObject*/
{
public:
	// constructor
	Physical();

	// constructor with one int parameter
	Physical(int);

	// destructor
	~Physical();

	// printout ability point to console
	void show();

	// set ability point
	// @param int which will be saved into physical var
	void setPhysical(int);

	// @return get physical score
	int getPhysical();

private:
	int nContPhysical;			// number of the Physicals
};

