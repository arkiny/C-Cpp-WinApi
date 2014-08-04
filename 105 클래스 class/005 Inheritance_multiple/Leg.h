#pragma once

class Leg : public IGameObject
{
public:
	Leg();
	~Leg();

	void show();
	void setLeg(int n_input) { nCntLeg = n_input; }
	int getLeg(){ return nCntLeg; }

private:
	int nCntLeg;
};

