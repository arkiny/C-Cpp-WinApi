#include "object.h"

/*
	Main
*/

void main(){
	// var init
	Object player = Object(0, 0);
	Object enemy = Object(5, 10);
	player.show();
	enemy.show();
	
	enemy.setPos(10, 10);
	enemy.show();

	//test
	player.showDistance(enemy.getPos()); // 14.14
	player.showAngle(enemy.getPos()); // 45µµ
}