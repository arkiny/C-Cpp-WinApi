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

		//RECT getBackground(){
		//	return _background;
		//}

		//RECT getTitlebar(){
		//	return _titlebar;
		//}

		
		::Rectangle(hdc,
			_world->getBackground().left,
			_world->getBackground().top,
			_world->getBackground().right,
			_world->getBackground().bottom);
		HBRUSH myBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		::Rectangle(hdc,
			_world->getTitlebar().left,
			_world->getTitlebar().top,
			_world->getTitlebar().right,
			_world->getTitlebar().bottom);
		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

	}

private:
	World* _world;
};