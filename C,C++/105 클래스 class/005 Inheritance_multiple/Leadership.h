/*
	��ּ�ġ ����
	���� ��ġ������ Ư�� �߰�
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

