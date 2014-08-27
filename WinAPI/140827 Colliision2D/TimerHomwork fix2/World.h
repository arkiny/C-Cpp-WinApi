/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once;

//#include <cmath>
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
		if (!collider()){
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
			else {
				// TODO: �ε������� ó�� �߰�
				// ���� ��� ������Ʈ�� ���忡�� ���� ������?
			}
			_obstacle.update();
		}

		if (_player.checkBound(_map)){
			// do nothing
		}
		else {
			_player.update();
		}	

	}

	// collider�� �� object���� ó���ϴ°� ���Ѱ� �ƴϸ�
	// world���� ó���ϴ°� ���Ѱ�.
	// �簢�� �浹? Ȥ�� �Ÿ��� ����ؼ� �浹?
	// �׷� �� �� �簢�� �浹�� ��� ó���ؾߵ���?
	// �Ÿ��� ���Ÿ� ����, �簢�� �Ÿ� ����?
	BOOL collider(){
		//top		
		//bottom
		//left
		//right
		int collidingRange = _player.getSize() + _obstacle.getSize();
		int hRange = abs(_player.getPos().x - _obstacle.getPos().x);
		int vRange = abs(_player.getPos().y - _obstacle.getPos().y);
	
		return	(hRange <= collidingRange) &&
				(vRange <= collidingRange);		
	}

	// getter
	Obstacle getObstacle(){	return _obstacle;}	
	Player getPlayer(){ return _player; }
	

private:	
	RECT _map;
	Obstacle _obstacle;
	Player _player;
};