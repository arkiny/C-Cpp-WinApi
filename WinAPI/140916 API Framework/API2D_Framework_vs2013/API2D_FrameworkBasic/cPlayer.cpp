#include "stdafx.h"
#include "cPlayer.h"


/*
�ǽ� �÷��̾� Ŭ���� �ϼ�
���� Ŭ���� �߰�
Grid Ŭ���� �߰� (50*50)
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
