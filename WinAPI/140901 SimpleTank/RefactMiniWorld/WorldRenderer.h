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

	WorldRenderer(World* world){		
		_world = world;
	}

	void render(HDC &hdc){
		_world->render(hdc);
	}

private:
	World *_world;
};