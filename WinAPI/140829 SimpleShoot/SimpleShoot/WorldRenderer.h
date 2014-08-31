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

		if (_world->getObstacle().size() > 0){
			if (!_world->EllipseCollider()){
				// todo : 차후 유동값으로 전환
				if (_world->getObstacle()[0]->getHP() > 0){
					::Ellipse(hdc,
						_world->getObstacle()[0]->getPos().x - _world->getObstacle()[0]->getSize(),
						_world->getObstacle()[0]->getPos().y - _world->getObstacle()[0]->getSize(),
						_world->getObstacle()[0]->getPos().x + _world->getObstacle()[0]->getSize(),
						_world->getObstacle()[0]->getPos().y + _world->getObstacle()[0]->getSize());
					::wsprintf(str, L"HP: %d", _world->getObstacle()[0]->getHP());
					::TextOut(hdc, _world->getObstacle()[0]->getPos().x - 10, _world->getObstacle()[0]->getPos().y - 10, str, 5);
				}
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

		for (int i = 0; i < _world->getBullets().size(); i++){
			::Ellipse(hdc,
				_world->getBullets()[i]->getPos().x - _world->getBullets()[i]->getSize(),
				_world->getBullets()[i]->getPos().y - _world->getBullets()[i]->getSize(),
				_world->getBullets()[i]->getPos().x + _world->getBullets()[i]->getSize(),
				_world->getBullets()[i]->getPos().y + _world->getBullets()[i]->getSize());
		}

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

	}

private:
	World* _world;
};