/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	World �ڵ鷯 Ŭ����
	ȭ�� ������ ���� ������
*/

#pragma once

#include <Windows.h>
#include <vector>

using std::vector;

class GameMap{
public:
	GameMap(){

	}



	~GameMap(){}

private:
	const int _tileSize = 15;

};

class World{
public:
	World(){
		_rScreen = { 0, 0, 1028, 768 };
	}

	World(RECT &winRect){
		_rScreen = winRect;
	}

	~World();


	void update(float delta);
	void render(HDC &hdc);

private:
	RECT _rScreen;
	int _tileSize = 25;

	void screenToTile(POINT pos, int size){

	}
	
	void tileToScreen(POINT pos, int size){

	}
};