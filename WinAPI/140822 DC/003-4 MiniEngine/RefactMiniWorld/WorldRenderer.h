/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	WORLD Rendering 클래스
	World 클래스가 가지고 있는 정보를 통해 World를 화면에 Render한다
*/

#pragma once

#include <Windows.h>
#include "World.h"

class WorldRenderer{
public:
	WorldRenderer(){
	}

	WorldRenderer(HWND hwnd, World world){
		_hwnd = hwnd;
		_world = world;
		RECT clientRect;
		::GetClientRect(_hwnd, &clientRect);
		_world.updateWorld(clientRect);
	}

	void moveAnimation(int mx, int my){
		RECT draw;

		draw = _world.getTileRect(_world.getTileCoordinate(mx, my).x,
			_world.getTileCoordinate(mx, my).y);

		HDC hdc = ::GetDC(_hwnd);
		::Ellipse(hdc,
			draw.left,
			draw.top,
			draw.right,
			draw.bottom);
		::ReleaseDC(_hwnd, hdc);
	}

	void update(){
		HDC _hdc = ::GetDC(_hwnd);
		RECT clientRect;
		::GetClientRect(_hwnd, &clientRect);

		_world.updateWorld(clientRect);

		for (int i = 0; i < _world.getNumRow() - 1; i++){
			for (int j = 0; j < _world.getNumColumn() - 1; j++){
				::Rectangle(_hdc,
					(_world.getTile().left + (i*_world.getTile().right) + (_world.getTile().right / 2)),
					(_world.getTile().top + (j*_world.getTile().bottom) + (_world.getTile().bottom / 2)),
					(_world.getTile().right + (i*_world.getTile().right) + (_world.getTile().right / 2)),
					(_world.getTile().bottom + (j*_world.getTile().bottom) + (_world.getTile().bottom / 2)));
			}
		}

		if (!_world.getObjects().empty()){
			for (int i = 0; i < _world.getObjects().size(); i++){
				RECT obj = _world.getTileRect(_world.getObjects()[i]->_pos.x, _world.getObjects()[i]->_pos.y);
				::Ellipse(_hdc, obj.left, obj.top, obj.right, obj.bottom);
			}
		}

		::ReleaseDC(_hwnd, _hdc);
	}

private:
	HWND _hwnd;
	World _world;
};