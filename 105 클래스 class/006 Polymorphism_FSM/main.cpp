/*
	@author		Heedong Arkiny Lee
	@date		08072014
	@git		https://github.com/arkiny/SGA-Learning-Heedong


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

	���� ] Fight, RunAway �߰�

	���� ]
		Orc�ܿ� Player Object�� �̿��ؼ�
		Player�� Orc���� �ٰ����� ������ �߰��Ϸ��� ����....
		����� ���� ���������� ���� �������ִ� �Ŵ����� �ʿ��ϰ�,
		�װ� ¥�� ��, �Ѽ����� �ɸ��� ���Ƽ� �ϴ��� ������Ʈ�� ���ܳ���
		Orc�� ������Ʈ�ѷ� ���������� ó��

	�ǹ� ]
		State�� �ϴ� Orc*�� �޾Ƽ� ���� �ٸ� Object�� �����Ҷ�
		������ ������� �ִµ�, IGameObject���� Interface�� �̿��ؼ�
		������� ������ ������...	
*/

#include <iostream>
#include <conio.h>

#include "iGameObj.h"

void main(){
	Orc orc;

	char ch = 0;
	while (ch != 0x1b){ // esc ����
		if (kbhit()){
			fflush(stdin);
			ch = getch();
		}

		if (ch == ' '){
			orc.setDist(orc.getDist() - 1);
			std::cout << "�÷��̾ ��ũ���� �����մϴ�." << std::endl
				<< "�Ÿ� = " << orc.getDist() << std::endl;
		}
		ch = NULL;

		orc.update();

		//std::cout << "Loop...." << std::endl;

		_sleep(500); // 0.1�� sleep
	}
}