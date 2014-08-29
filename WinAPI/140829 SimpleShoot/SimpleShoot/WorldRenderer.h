/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once;
#include <Windows.h>
#include "World.h"

class WorldRenderer{
public:	
	WorldRenderer(World* world){		
		_world = world;
	}
	
	void render(HDC hdc){
		TCHAR str[6] = L"";
		if (!_world->EllipseCollider()){
			if (_world->getObstacle().getHP() > 0){
				::Ellipse(hdc,
					_world->getObstacle().getPos().x - _world->getObstacle().getSize(),
					_world->getObstacle().getPos().y - _world->getObstacle().getSize(),
					_world->getObstacle().getPos().x + _world->getObstacle().getSize(),
					_world->getObstacle().getPos().y + _world->getObstacle().getSize());
				::wsprintf(str, L"HP: %d", _world->getObstacle().getHP());
				::TextOut(hdc, _world->getObstacle().getPos().x - 10, _world->getObstacle().getPos().y - 10, str, 5);
			}
		}
				
		HBRUSH myBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);		
		/*::Rectangle(hdc,
			_world->getPlayer().getPos().x - _world->getPlayer().getSize(),
			_world->getPlayer().getPos().y - _world->getPlayer().getSize(),
			_world->getPlayer().getPos().x + _world->getPlayer().getSize(),
			_world->getPlayer().getPos().y + _world->getPlayer().getSize());*/
		::Ellipse(hdc,
			_world->getPlayer().getPos().x - _world->getPlayer().getSize(),
			_world->getPlayer().getPos().y - _world->getPlayer().getSize(),
			_world->getPlayer().getPos().x + _world->getPlayer().getSize(),
			_world->getPlayer().getPos().y + _world->getPlayer().getSize());
		
		
		myBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		if (!_world->getBullets().empty()){
			::Ellipse(hdc,
				_world->getBullets()[0]->getPos().x - _world->getBullets()[0]->getSize(),
				_world->getBullets()[0]->getPos().y - _world->getBullets()[0]->getSize(),
				_world->getBullets()[0]->getPos().x + _world->getBullets()[0]->getSize(),
				_world->getBullets()[0]->getPos().y + _world->getBullets()[0]->getSize());
			
		}

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

	}

private:
	World* _world;
};