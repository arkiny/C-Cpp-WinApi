#pragma once

struct MapSize{
	int _x = 0;
	int _y = 0;
};

class GameMap{
public:
	GameMap(){
		// 혹시 모르니 Double Checking
		_size._x = 0;
		_size._y = 0;
		_tileSize = 50;
	}

	GameMap(int x, int y, int tilesize){
		_size._x = x;
		_size._y = y;
		_tileSize = tilesize;
	}

	//getter
	MapSize getMapSize(){
		return _size;
	}

	int getTileSize(){
		return _tileSize;
	}

	//setter
	void setMapSize(int x, int y){
		_size._x = x;
		_size._y = y;
	}

	void getTileSize(int in){
		_tileSize = in;
	}

	
	POINT isoTo2D(POINT in){
		POINT ret = { 0, 0 };
		ret.x = (2 * in.y + in.x) / 2;
		ret.y = (2 * in.y - in.x) / 2;
		return ret;
	}

	// cartesian coordinate.
	// x is not row
	// 납작한 마름모의 위치를 리턴해준다.
	// @param 스크린위에 표시된 바둑판형 원좌표
	// @return 카테시안 (가로, 세로)형식의 좌표
	POINT TwoDtoISO (POINT in){
		POINT ret = { 0, 0 };
		ret.x = in.x - in.y;
		// 수정시 렌더부분도 꼭 체크해서 수정해줘야함
		ret.y = (in.x + in.y)/2;
		return ret;
	}

private:
	MapSize _size;
	//차후 database 추가
	int _tileSize = 50;
};