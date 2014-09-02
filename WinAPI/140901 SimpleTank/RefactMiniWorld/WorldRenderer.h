/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	WORLD Rendering Ŭ����
	World Ŭ������ ������ �ִ� ������ ���� World�� ȭ�鿡 Render�Ѵ�
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