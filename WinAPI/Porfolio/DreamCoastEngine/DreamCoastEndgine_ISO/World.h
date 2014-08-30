// World
// World�� �����ϴ� Ŭ����
// �ϴ� ���ӳ� ��ȣ �ۿ���� �������ִ� Ŭ����

#pragma once

#include <Windows.h>
#include "GameMap.h"

class World{
public:
	World(){

	}

	World(RECT& winRect){
		// ������ ũ�⿡ ���߾ ȭ�鿡 �����Ǵ�
		// Ÿ�ϸ� ������ ������
	}

	~World(){
	}

	void update(float delta){

	}

	POINT mbClick(int x, int y){
		return _gameMap.mbClick(x, y);
	}

	void render(HDC& hdc){
		_gameMap.render(hdc);
	}

private:
	//helper method
	RECT _worldScreen;
	GameMap _gameMap;
};