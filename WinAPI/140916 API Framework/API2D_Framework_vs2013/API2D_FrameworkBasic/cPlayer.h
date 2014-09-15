#pragma once
class cPlayer
{
public:
	cPlayer();
	~cPlayer();

private:
	float playerX;
	float playerY;
	HBITMAP hPlayerBitmap;
	RECT playerCollisionBox;
	float playerPivotX;
	float playerPivotY;
};

