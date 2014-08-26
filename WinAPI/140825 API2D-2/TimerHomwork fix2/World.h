/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once;

#include "Object.h"

class World{
public:
	World(){
		_obstacle = Obstacle({ 300, 300 }, 50);
		_player = Player({ 500, 500 }, 50);
		_map = {};
	}

	World(Obstacle &obs){
		_obstacle = obs;
		_map = {};
	}

	void updateMap(RECT& winRect){
		_map = winRect;
	}

	void kbDown(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player.setDir(RIGHT);
			break;
		case VK_LEFT:
			_player.setDir(LEFT);
			break;
		case VK_UP:
			_player.setDir(UP);
			break;
		case VK_DOWN:
			_player.setDir(DOWN);
			break;
		}
	}

	void kbUp(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player.unsetDir(RIGHT);
			break;
		case VK_LEFT:
			_player.unsetDir(LEFT);
			break;
		case VK_UP:
			_player.unsetDir(UP);
			break;
		case VK_DOWN:
			_player.unsetDir(DOWN);
			break;
		}
	}

	void Update(float data){
		if (_obstacle.checkBound(_map)){
			switch (_obstacle.getDir())
			{
			case LEFT:
				_obstacle.setDir(RIGHT);
				break;
			case RIGHT:
				_obstacle.setDir(LEFT);
				break;
			default:
				break;
			}
		}
		_obstacle.update();
		if (_player.checkBound(_map)){
			// do nothing
		}
		else {
			_player.update();
		}
		
	}

	// getter
	Obstacle getObstacle(){	return _obstacle;}	
	Player getPlayer(){ return _player; }
	

private:
	RECT _map;
	Obstacle _obstacle;
	Player _player;
};