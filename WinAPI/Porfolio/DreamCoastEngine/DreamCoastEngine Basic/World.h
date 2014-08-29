#pragma once

#include <Windows.h>
//#include <vector> // Ȥ�� �� ���� database�� �ִ���?
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
		// ���� vector pointer �ʱ�ȭ�Ҷ� �߰�
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
	// �ϴ� ���� ������Ʈ���� ����
	Object _obj;
	UIInven _ui;
	

} *LPWORLD;