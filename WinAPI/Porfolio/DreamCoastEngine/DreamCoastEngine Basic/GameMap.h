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

	// 입력 받는 타일의 좌표는 db에서의 좌표	
	// 이렇게 되면 클릭할때마다 좌표를 한번씩 다 스캔하게 되는데....
	POINT twoDtoISOcheck(POINT tile, POINT cur){
		
		// db에서의 좌표를 화면좌표로 변환하고,
		// 그 화면 좌표를 중심으로 사각형을 생성한다.
		RECT tileArea = { 
			tile.x - _tileSize ,
			tile.y - _tileSize ,
			tile.x + _tileSize ,
			tile.y + _tileSize };

		POINT ret = tile;

		int xFromTilePos = cur.x - tile.x;
		int yFromTilePos = cur.y - tile.y;

		// 커서 좌표를 받아와서 범위를 확인한다.
		if ( tileArea.left >= cur.x && tileArea.right <= cur.x &&
			tileArea.top >= cur.y && tileArea.bottom<= cur.y){
			if (yFromTilePos < xFromTilePos){
				if (yFromTilePos < (-xFromTilePos)) --ret.y;
				else ++ret.x;
			}
			else if (yFromTilePos > xFromTilePos){
				if (yFromTilePos < (-xFromTilePos)) --ret.x;
				else ++ret.y;
			}
			// 커서가 tile 포인트의 범위 안에 있을때
			// 왼쪽 위에 있을 때 현재 위치의 -1, -1
			// 오른쪽 위에 있을때 현재 위치의 0, -1
			// 왼쪽 아래에 있을때 현재 위치의 -1, 1
			// 오른쪽 아래에 있을때 현재 위치의 0, 1			
			// 정확하게 마름모 안에 있을때 0, 0
		};
		return ret;
	}

private:
	MapSize _size;
	//차후 database 추가
	int _tileSize = 50;
};