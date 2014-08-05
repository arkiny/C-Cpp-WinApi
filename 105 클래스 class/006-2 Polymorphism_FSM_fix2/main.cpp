/*
	@author		Heedong Arkiny Lee
	@date		08062014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Polymorphism ������ (AI)
	- FSM ( Finite State Machine ) Turing Machine?

	Idle state
	checking -> tired?, threatend?

	Resting state
	checking -> tired?

	RunAway state
	checking ->	threatened?	

	state���� �̸� �������� �������ָ� AI�� ���� ĳ���͸� ������� �ִ�.
	���� class�� ���� AI�Ŵ����� �ѹ� ����� ����...

	���� ]]
	1. Interface���� �̿��ؼ� state �Ŵ����� ������ٰ� ����(���� ����)
	2. callback(�����ð��� ��� void (*pf)()���) �� �̿��ؼ� �ݹ��ؼ� ������ٰ� ����
		-> function ���̺귯���� �̿��ؿ� �κ������� �ذ�
	3. Interface �̿��ϴ� �� �����ϰ� state class�� ���Ͽ� ���� state�� �����ϱ�� ����
	4. ���� IBattle�� ���� �׷��� ���̸� �ø����ٰ� �ϴ� C++ Interface�� ���� ���ϰ� ����

	��� �� ]]
	������ callback�� ���� ���� �����Ͱ� �ƴ϶�
	function �� bind�� �̿��ϸ� �ݹ��� ������ �ִ�...(C++11 �̻�)
	(�ٵ� ���� �������ϸ� �ݹ� �ʿ� ���� ��)

	���� �� ���� ]]
	1. ���⼭ Interface���� ���ؼ� FSM�� �������?	
	2. Interface�� �̿��� ���� Ŭ������ �����̵�(+ ���� ����)
*/

#include "State.h"
#include "StateMachine.h"
void main()
{	
	StateMachine a = StateMachine();
	a.render();
}

