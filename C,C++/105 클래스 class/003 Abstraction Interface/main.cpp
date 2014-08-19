#include "object.h"

/*
	Main
	�����Լ��� ���� ���α׷� ��ƾ�� �̷������� �귯����
	��� ������ ���ϼ� �ְ�... 
	�������� ���� �� Ŭ�������� ����
*/

#include <iostream>
//using std::cout;
//using std::endl;

void main(){
	// var init
	Object player = Object(0.0f, 0.0f);
	//cout << &player << endl;

	// memory intercept�� �Ͼ��. ���� �����͸� ����
	// new ���� �Ҵ��� �̿��ؼ� ���� ������ְ� ��� �Ѵ�? -> ���ο� �÷��̾ ���鶧
	// �׷� �̷��� ���� �ּҰ��� ���ϴ���? 
	// �ƴϸ� ���� �ּҿ��� ���� �ٲ�� ����?
	// ���� �ּҿ��� ���� �ٲ��. ���� memory leaking�� �Ͼ�� �ʴ´�.
	// memory leaking�� �ƴ϶� memory intercept�� �Ͼ��.
	// ���ο� �޸� �ּҷ� �ű�� �ʹٸ� �����͸� ���� �ű�� �Ǹ� memory leaking��
	// �Ͼ�� ������, ���� ���� �����ʹ� �Ƴ����� �ִ�.

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
	player.showAngle(enemy.getPos()); // 45��
}


