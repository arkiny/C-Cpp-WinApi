/*
	@author		Heedong Arkiny Lee
	@date		08062014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Polymorphism 다형성 (AI)
	- FSM ( Finite State Machine ) Turing Machine?

	Idle state
	checking -> tired?, threatend?

	Resting state
	checking -> tired?

	RunAway state
	checking ->	threatened?	

	state들을 미리 만들어놓고 조합해주면 AI를 지닌 캐릭터를 만들수가 있다.
	각각 class로 만들어서 AI매니저도 한번 만들어 볼까...

	과정 ]]
	1. Interface만을 이용해서 state 매니저를 만드려다가 실패(갈아 엎음)
	2. callback(수업시간에 배운 void (*pf)()등등) 을 이용해서 콜백해서 만드려다가 실패
		-> function 라이브러리를 이용해여 부분적으로 해결
	3. Interface 이용하는 걸 포기하고 state class를 통하여 직접 state를 제어하기로 결정
	4. 원래 IBattle을 통해 그래프 깊이를 늘리려다가 일단 C++ Interface에 적응 못하고 포기

	배운 것 ]]
	더러운 callback을 위해 따로 포인터가 아니라
	function 및 bind를 이용하면 콜백을 쓸수가 있다...(C++11 이상)
	(근데 구조 재정립하면 콜백 필요 없을 듯)

	과제 후 질문 ]]
	1. 여기서 Interface만을 통해서 FSM을 만드려면?	
	2. Interface를 이용한 형제 클래스간 수평이동(+ 변수 관리)
*/

#include "State.h"
#include "StateMachine.h"
void main()
{	
	StateMachine a = StateMachine();
	a.render();
}

