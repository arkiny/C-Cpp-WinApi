/*
	Polymorphism ������ (AI)
	- FSM ( Finite State Machine ) Turing Machine?

	Idle state
	checking -> tired?, threatend?

	Resting state
	checking -> tired?

	RunAway state
	checking ->	threatened?

	�����޴� ���� ������...
	�ο�ٰ� ��������.
*/


#include <iostream>
#include <conio.h>

#include "Orc.h"

void main(){
	Orc orc;

	char ch = 0;
	while (ch != 0x1b){ // esc ����
		if (kbhit()){
			fflush(stdin);
			ch = getch();
		}

		orc.update();

		//std::cout << "Loop...." << std::endl;

		_sleep(500); // 0.1�� sleep
	}
}