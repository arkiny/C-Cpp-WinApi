/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	스크린샷의 편의성을 위해 cpp로 나누진 않았습니다.
	화면 컨트롤을 위한 클래스인데

	너무 구조가 병신같아서 refactoring 하고 싶은데...
	의욕이 들면 함
*/

#pragma once

#include <Windows.h>

// Tilemap information
typedef struct TileMap{
	// 하지만 실제로는 19개 (여백포함)
	const int nrow = 18;			
	const int ncolumn = 18;
	float tilew;		// width of the tile
	float tileh;		// height of the tile
	float top;		// x coordinate of the lefttop
	float left;		// y coordinate of the lefttop
	float right;		// x coordinate of the rightbottom
	float bottom;		// y coordinate of the rightbottom
}TILEMAP, *LPTILEMAP;

// Player info
typedef struct Player{
	POINT curpos;			// mouse cursor position info when the last event
	POINT pos;				// current player position (refactored)
	RECT obj;				// real player rectangle
	BOOL moveFlag = false;	// will it move?
}PLAYER, *LPPLAYER;

// World handling class
class WorldRenderer{
public:
	WorldRenderer(HWND &hwnd, HDC &hdc, RECT &clientRect, PLAYER &player){
		_hwnd = hwnd;
		_hdc = hdc;
		_player = player;
		_clientRect = clientRect;
		_tilemap.tilew = _clientRect.right / (_tilemap.ncolumn + 1); // 여백을 위해 한칸 더 추가
		_tilemap.tileh = _clientRect.bottom / (_tilemap.nrow + 1);
		_tilemap.top = clientRect.top + (_tilemap.tileh / 2);
		_tilemap.left = clientRect.left + (_tilemap.tilew / 2);
		_tilemap.right = _tilemap.left + (_tilemap.tilew * _tilemap.ncolumn);
		_tilemap.bottom = _tilemap.top + (_tilemap.tileh * _tilemap.nrow);
	}

	// rendering world
	bool update(bool &playerAct);

	// getTile Rectangle
	RECT getTileCoordnate(int x, int y);

	// getPlayer Coordinate within client
	POINT getPlayerCoordinate(int x, int y);

	// return tilemap
	TILEMAP getMap(){
		return _tilemap;
	}

	// return player info
	PLAYER getPlayer(){
		return _player;
	}

	// bordering check
	BOOL isCurInside(PLAYER &inplayer){
		return (inplayer.pos.x < _tilemap.ncolumn &&
			inplayer.pos.y < _tilemap.nrow &&
			inplayer.curpos.x >(_tilemap.tilew / 2) &&
			inplayer.curpos.y >(_tilemap.tileh / 2));
	}

private:
	// make palyer rect using x, y coordinate
	RECT makePlayerRect(int retX, int retY){
		RECT  ret = { retX*_tilemap.tilew + (_tilemap.tilew / 2),
			retY*_tilemap.tileh + (_tilemap.tileh / 2),
			retX*_tilemap.tilew + (_tilemap.tilew / 2) + _tilemap.tilew,
			retY*_tilemap.tileh + (_tilemap.tileh / 2) + _tilemap.tileh };
		return ret;
	};

	HDC _hdc;
	HWND _hwnd;
	RECT _clientRect;
	TILEMAP _tilemap;
	PLAYER _player;
};

bool WorldRenderer::update(bool &playerAct){
	_hdc = ::GetDC(_hwnd);
	::Rectangle(_hdc, _tilemap.left, _tilemap.top, _tilemap.right, _tilemap.bottom);
	RECT drawer = { _tilemap.left, _tilemap.top,
		_tilemap.left + _tilemap.tilew,
		_tilemap.top + _tilemap.tileh };

	for (int i = 0; i < _tilemap.nrow; i++){
		for (int j = 0; j < _tilemap.ncolumn; j++){
			::Rectangle(_hdc,
				drawer.left,
				drawer.top,
				drawer.right,
				drawer.bottom);
			drawer.left = drawer.right;
			drawer.right = drawer.right + _tilemap.tilew;
		}
		drawer.left = _tilemap.left;
		drawer.right = _tilemap.left + _tilemap.tilew;
		drawer.top = drawer.bottom;
		drawer.bottom = drawer.bottom + _tilemap.tileh;
	}
	::ReleaseDC(_hwnd, _hdc);

	int retX, retY;

	if (playerAct){
		_hdc = ::GetDC(_hwnd);
		retX = _player.pos.x;
		retY = _player.pos.y;

		// get cursorPos
		::GetCursorPos(&_player.curpos);
		// convert it to client
		::ScreenToClient(_hwnd, &_player.curpos);

		// in tilemap range
		if (isCurInside(_player)){
			_player.obj = makePlayerRect(retX, retY);
			::Ellipse(_hdc, _player.obj.left, _player.obj.top, _player.obj.right, _player.obj.bottom);
			::ReleaseDC(_hwnd, _hdc);
		}
		else{
			// out of tilemap range
		}
	}
	return true;
}

POINT WorldRenderer::getPlayerCoordinate(int x, int y){
	POINT ret;
	int retX, retY;

	retX = (x - (_tilemap.tilew / 2)) / _tilemap.tilew;
	retY = (y - (_tilemap.tileh / 2)) / _tilemap.tileh;
	ret = { retX, retY };

	return ret;
}


RECT WorldRenderer::getTileCoordnate(int x, int y){
	int retX, retY;

	POINT in = this->getPlayerCoordinate(x, y);

	retX = in.x;
	retY = in.y;

	RECT ret = makePlayerRect(retX, retY);

	return ret;
}