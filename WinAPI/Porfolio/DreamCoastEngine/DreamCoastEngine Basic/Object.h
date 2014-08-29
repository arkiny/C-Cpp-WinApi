// 오브젝트는 맵위에서 좌표를 가진다.
// 차후 타입조정 및 인터페이스 조정으로
// 플레이어와 몬스터를 바꿀수 있다.

#pragma once

#include <Windows.h>

class Object{
public:
	Object(){
		_pos = {};
	}
	Object(int x, int y){
		_pos = { x, y };
	}

	POINT getObject(){ return _pos; }
	void setObject(int x, int y){
		_pos = { x, y };		
	};

private:
	POINT _pos;
};