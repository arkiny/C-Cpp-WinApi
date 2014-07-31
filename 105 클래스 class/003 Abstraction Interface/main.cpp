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
	
	//test
	player.showDistance(enemy.getPos());
	player.showAngle(enemy.getPos());
}