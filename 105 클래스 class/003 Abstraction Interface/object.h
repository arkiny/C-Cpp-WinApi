#ifndef _OBJECT_H_
#define _OBJECT_H_
/*
Abstraction ( 추상화 )
- Interface 클래스와 사용자간의 상호작용
*/

#include <iostream>

using std::cout;
using std::endl;

typedef struct Point{
	// 아예 여기서 초기화해버리면 다시 만질 필요가 없어져서 편함
	float fx = 0.0f;
	float fy = 0.0f;
}POINT, *LPPOINT;

class Object
{
public:
	Object();
	~Object();
	void show();

private:
	/*POINT pos = {};*/ //최근버전의 c++에서 이게 가능하게 바뀜
	POINT pos;
};

#endif