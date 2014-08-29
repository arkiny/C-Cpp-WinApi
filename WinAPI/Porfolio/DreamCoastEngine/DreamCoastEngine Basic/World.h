#pragma once

#include <Windows.h>
//#include <vector> // 혹시 더 나은 database가 있는지?
#include "GameMap.h"
#include "Object.h"
#include "UIInven.h"


typedef class World{
public:
	World(){
		_map.setMapSize(0, 0);
		_ui.setpos(0, 0);
	}

	World(int size_x, int size_y){
		_map.setMapSize(size_x, size_y);
		_ui.setpos(0, 0);
	}

	~World(){
		// 차후 vector pointer 초기화할때 추가
	}

	//getter	
	GameMap getGameMap(){ return _map; }

	//setter
	void setGameMap(int size_x, int size_y){
		_map.setMapSize(size_x, size_y);
	}	

	//BOOL pick(int x, int y){

	//	::Rectangle(hdc,
	//		x - (tileWidth / 2),
	//		y - (tileHeight / 2),
	//		x + (tileWidth / 2),
	//		y + (tileHeight / 2));
	//}

	UIInven getUI(){
		return _ui;
	}
	
	void setUImove(bool in){
		_ui.setUImoving(in);
	}

	void uiMove(int x, int y){
		_ui.moveTo(x, y);
	}

	void setBtnStatus(int in){
		_ui.setBtnStatus(in);
	}

	void setOldCurpos(int x, int y){
		_ui.saveMBoldpos(x, y);
	}

private:
	GameMap _map;
	// 일단 단일 오브젝트부터 시작
	Object _obj;
	UIInven _ui;
	

} *LPWORLD;