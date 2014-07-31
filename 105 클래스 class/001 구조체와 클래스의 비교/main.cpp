/*
	구조체와 클래스의 차이점
	- 구조체는 기본적으로 public, 클래스는 기본적으로 private
	- 구조체도 object의 일부이다.
*/

#include <iostream>

using std::cout;
using std::endl;

// 구조체는 기본적으로 public의 성격을 가지고 있다.
struct pointS{
	int x;
	int y;
};

class PointC{
private: // 데이터는 기본적으로 숨기는게 좋은
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