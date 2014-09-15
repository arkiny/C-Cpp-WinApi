#include "stdafx.h"
#include "cPlayer.h"


/*
실습 플레이어 클래스 완성
몬스터 클래스 추가
Grid 클래스 추가 (50*50)
*/

cPlayer::cPlayer()
{
	playerX = 0;
	playerY = 0;
	playerPivotX = 25;
	playerPivotY = 25;
	hPlayerBitmap = nullptr;
	playerCollisionBox = {};	
}


cPlayer::~cPlayer()
{
}
