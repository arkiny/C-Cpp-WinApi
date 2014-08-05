/*
	Polymorphism 다형성 (AI)
	- FSM ( Finite State Machine ) Turing Machine?

	Idle state
	checking -> tired?, threatend?, hasWeapon?
	
	Sleep state
	checking -> tired?

	RunAway state
	checking ->
	threatened?

	Battle state
	checking -> 
	win?
	myHP?


	state들을 미리 만들어놓고 조합해주면 AI를 지닌 캐릭터를 만들수가 있다.
	각각 class로 만들어서 AI매니저도 한번 만들어 볼까...

	질문 ]] 
	여기서 Callback을 통해서 FSM을 만드려면?
*/

#include "StateMachine.h"

void main(){
	StateMachine a = StateMachine();
}
