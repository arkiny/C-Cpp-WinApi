/*
	����ü�� Ŭ������ ������
	- ����ü�� �⺻������ public, Ŭ������ �⺻������ private
	- ����ü�� object�� �Ϻ��̴�.
*/

#include <iostream>

using std::cout;
using std::endl;

// ����ü�� �⺻������ public�� ������ ������ �ִ�.
struct pointS{
	int x;
	int y;
};

class PointC{
private: // �����ʹ� �⺻������ ����°� ����
	int x;
	int y;

public:
	bool setX(int inputX){
		   x = inputX;
		   return true;
	}

	int getX(){
		   return x;
	}
	
	bool setY(int inputY){
		y = inputY;
		return true;
	}

	int getY(){
		return y;
	}
};


void main()
{
	pointS pos1;
	pos1.x = 15;
	pos1.y = 27;
	cout << pos1.x << "," << pos1.y << endl;

	PointC pos2;
	pos2.setX(15);
	pos2.setY(27);
	cout << pos2.getX() << "," << pos2.getY() << endl;
}