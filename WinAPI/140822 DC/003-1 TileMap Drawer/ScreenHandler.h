#pragma once

#include <Windows.h>

typedef struct TileMap{
	// 하지만 실제로는 19개 (여백포함)
	const int nrow = 18;
	const int ncolumn = 18;
	int tilew;
	int tileh;
	int top;
	int left;
	int right;
	int bottom;
}TILEMAP, *LPTILEMAP;

typedef struct Player{
	POINT curpos;
	POINT pos;
	RECT obj;
	BOOL moveFlag = false;
}PLAYER, *LPPLAYER;

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

	bool update(bool &playerAct);
	RECT getTileCoordnate(int x, int y);
	POINT getPlayerCoordinate(int x, int y);

	TILEMAP getMap(){
		return _tilemap;
	}

	PLAYER getPlayer(){
		return _player;
	}

	BOOL isCurInside(PLAYER &inplayer){
		return (inplayer.pos.x < _tilemap.ncolumn &&
			inplayer.pos.y < _tilemap.nrow &&
			inplayer.curpos.x >(_tilemap.tilew / 2) &&
			inplayer.curpos.y >(_tilemap.tileh / 2));
	}

private:	
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
	RECT drawer = { _tilemap.left, 	_tilemap.top, 
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