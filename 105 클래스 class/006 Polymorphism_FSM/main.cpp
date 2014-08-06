/*
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
*/


#include <iostream>
#include <conio.h>

#include "Orc.h"

void main(){
	Orc orc;

	char ch = 0;
	while (ch != 0x1b){ // esc 종료
		if (kbhit()){
			fflush(stdin);
			ch = getch();
		}

		orc.update();

		//std::cout << "Loop...." << std::endl;

		_sleep(500); // 0.1초 sleep
	}
}