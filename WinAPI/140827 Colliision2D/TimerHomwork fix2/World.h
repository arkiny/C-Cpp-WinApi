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
				// TODO: 부딪혔을때 처리 추가
				// 예를 들면 오브젝트를 월드에서 삭제 같은거?
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

	// collider를 각 object에서 처리하는게 편한가 아니면
	// world에서 처리하는게 편한가.
	// 사각형 충돌? 혹은 거리를 계산해서 충돌?
	// 그럼 원 대 사각형 충돌은 어떻게 처리해야되지?
	// 거리를 원거리 따로, 사각형 거리 따로?
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