/*
	���� ��� (multiple inheritance)
	- ���� �θ� Ŭ������ �ϳ��� �ڽ� Ŭ������ ��� 
	- �θ� n : �ڽ� 1 ���
	
	���߻�� �κп� �־ c++������ �߿��ϰ� ���� �����غ���
	�� �κ��̴�.

	���� ]]
		������ = 1
		���� �ٴµ� ���� �޸� ���� ������ +5
		�ٸ��� �ٴµ� �ٸ��� �߰��Ǹ� ������ +3
		�ϳ� �߰� ���̰�
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