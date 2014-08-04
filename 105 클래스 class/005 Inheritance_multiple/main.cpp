/*
	다중 상속 (multiple inheritance)
	- 여러 부모 클래스를 하나의 자식 클래스로 상속 
	- 부모 n : 자식 1 상속
	
	다중상속 부분에 있어서 c++에서도 중요하고도 많이 생각해봐야
	할 부분이다.

	과제 ]]
		전투력 = 1
		팔을 다는데 팔을 달면 개당 전투력 +5
		다리를 다는데 다리가 추가되면 전투력 +3
		하나 추가 붙이고
*/
#include "Character.h"

/*
*/
void main(){
	character minion;

	minion.setArm(3);
	minion.setLeg(3);
	minion.setName("Poppy");
	minion.show();
}