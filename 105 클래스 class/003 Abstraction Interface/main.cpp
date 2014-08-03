#include "object.h"

/*
	Main
	메인함수는 이제 프로그램 루틴이 이런식으로 흘러간다
	라는 느낌만 보일수 있게... 
	세부적인 것은 각 클래스에서 설정
*/

#include <iostream>
//using std::cout;
//using std::endl;

void main(){
	// var init
	Object player = Object(0.0f, 0.0f);
	//cout << &player << endl;

	// memory intercept가 일어난다. 따라서 포인터를 만들어서
	// new 동적 할당을 이용해서 새로 만들어주고 써야 한다? -> 새로운 플레이어를 만들때
	// 그럼 이렇게 쓰면 주소값도 변하는지? 
	// 아니면 동일 주소에서 값만 바뀌는 건지?
	// 동일 주소에서 값만 바뀐다. 따라서 memory leaking은 일어나지 않는다.
	// memory leaking이 아니라 memory intercept가 일어난다.
	// 새로운 메모리 주소로 옮기고 싶다면 포인터를 만들어서 옮기게 되면 memory leaking이
	// 일어날수 있지만, 현재 원래 데이터는 아낄수가 있다.

	//player = Object(0.5f, 1.0f);
	//cout << &player << endl;

	Object enemy = Object(5.0f, 10.0f);
	player.show();
	enemy.show();
	
	enemy.setPos(6.0f, 10.0f);
	enemy.show();

	enemy.movePos(4.0f, 0.0f); // (10,10)
	enemy.show();

	//test
	player.showDistance(enemy.getPos()); // 14.14
	player.showAngle(enemy.getPos()); // 45도
}


