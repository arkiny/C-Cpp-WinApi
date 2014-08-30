// World
// World를 구성하는 클래스
// 일단 게임내 상호 작용까지 관리해주는 클래스

#pragma once

#include <Windows.h>
#include "GameMap.h"

class World{
public:
	World(){

	}

	World(RECT& winRect){
		// 윈도우 크기에 맞추어서 화면에 렌더되는
		// 타일맵 사이즈 재조정
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