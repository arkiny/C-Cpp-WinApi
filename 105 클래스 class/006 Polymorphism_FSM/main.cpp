/*
	@author		Heedong Arkiny Lee
	@date		08072014
	@git		https://github.com/arkiny/SGA-Learning-Heedong


	Polymorphism 다형성 (AI)
	- FSM ( Finite State Machine ) Turing Machine?

	Idle state
	checking -> tired?, threatend?

	Resting state
	checking -> tired?

	RunAway state
	checking ->	threatened?

	위협받는 것을 과제로...
	싸우다가 도망간다.

	과제 ] Fight, RunAway 추가

	과정 ]
		Orc외에 Player Object를 이용해서
		Player가 Orc에게 다가가는 과정을 추가하려고 도전....
		만드는 도중 전투과정을 따로 관리해주는 매니저가 필요하고,
		그거 짜는 데, 한세월이 걸릴거 같아서 일단은 오브젝트만 남겨놓고
		Orc내 변수컨트롤로 원시적으로 처리

	의문 ]
		State가 일단 Orc*를 받아서 만약 다른 Object를 적용할때
		문제가 생길수도 있는데, IGameObject같은 Interface를 이용해서
		만들수도 있을거 같은데...	
*/

#include <iostream>
#include <conio.h>

#include "iGameObj.h"

void main(){
	Orc orc;

	char ch = 0;
	while (ch != 0x1b){ // esc 종료
		if (kbhit()){
			fflush(stdin);
			ch = getch();
		}

		if (ch == ' '){
			orc.setDist(orc.getDist() - 1);
			std::cout << "플레이어가 오크에게 접근합니다." << std::endl
				<< "거리 = " << orc.getDist() << std::endl;
		}
		ch = NULL;

		orc.update();

		//std::cout << "Loop...." << std::endl;

		_sleep(500); // 0.1초 sleep
	}
}