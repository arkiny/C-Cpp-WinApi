/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once;

#include <cmath>
#include "Object.h"

class World{
public:
	World(){
	}

	World(RECT &background, RECT &Titlebar){
		_background = background;
		Titlebar = _titlebar;
	}

	void updateMap(RECT& winRect){
		_background = winRect;		
		_titlebar.top = winRect.top;
		_titlebar.left = winRect.left;
		_titlebar.right = winRect.right;
		_titlebar.bottom = winRect.bottom/20;
	}

	void mLbtnDown(int x, int y){
		_mlbtnDown = true;
		_mX = x;
		_mY = y;

		if (cursorCollider(_mX, _mY)){
			_titlebar.left = _mX - _titlebar.left;
			_titlebar.right = _titlebar.right - _mX;
			_titlebar.top = _mY - _titlebar.top;
			_titlebar.bottom = _mY + _titlebar.top;
		}
	}
	
	void mLbtnUp(){
		_mlbtnDown = false;
	}

	void Update(float data){	
		if (_mlbtnDown){
			_titlebar.left = _mX - _titlebar.left;
			_titlebar.right = _titlebar.right - _mX;
			_titlebar.top = _mY - _titlebar.top;
			_titlebar.bottom = _mY + _titlebar.top;
		}
	}

	BOOL cursorCollider(int x, int y){
		BOOL ret = (x >= _titlebar.left && x <=_titlebar.right &&
			y >=_titlebar.top && y <= _titlebar.bottom);
			return ret;
	}

	// getter
	RECT getBackground(){
		return _background;
	}

	RECT getTitlebar(){
		return _titlebar;
	}


private:	
	RECT _background;
	RECT _titlebar;
	int _mX, _mY;
	BOOL _mlbtnDown = false;
};