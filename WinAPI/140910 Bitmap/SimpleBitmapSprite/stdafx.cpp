// stdafx.cpp : source file that includes just the standard includes
// SimpleBitmapSprite.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

MYSPRITE::MYSPRITE(){ left = 0; top = 0; width = 0; height = 0; }
MYSPRITE::MYSPRITE(int _l, int _t, int _w, int _h){
	left = _l;
	top = _t;
	width = _w;
	height = _h;
}
MYSPRITE::~MYSPRITE(){}