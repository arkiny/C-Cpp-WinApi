#include "stdafx.h"
#include "cObject.h"
#include "cRenderer.h"

cMonster::cMonster(){
	m_fMonAniAccumTime = 0.0f;
	m_nMonAniFrame = 0;
	_posX = 300;
	_posY = 640;

	m_monsterSprites[0] = MYSPRITE(60 * 0, 60 * 0, 60, 60);
	m_monsterSprites[1] = MYSPRITE(60 * 1, 60 * 0, 60, 60);
	m_monsterSprites[2] = MYSPRITE(60 * 2, 60 * 0, 60, 60);
	m_monsterSprites[3] = MYSPRITE(60 * 3, 60 * 0, 60, 60);
}

cMonster::cMonster(int x, int y){
	m_fMonAniAccumTime = 0.0f;
	m_nMonAniFrame = 0;
	_posX = x;
	_posY = y;

	m_monsterSprites[0] = MYSPRITE(60 * 0, 60 * 0, 60, 60);
	m_monsterSprites[1] = MYSPRITE(60 * 1, 60 * 0, 60, 60);
	m_monsterSprites[2] = MYSPRITE(60 * 2, 60 * 0, 60, 60);
	m_monsterSprites[3] = MYSPRITE(60 * 3, 60 * 0, 60, 60);
}

cMonster::~cMonster(){

}

void cMonster::update(float delta){
	m_fMonAniAccumTime += delta;
	if (m_fMonAniAccumTime > 0.4f)
	{
		m_nMonAniFrame++;
		if (m_nMonAniFrame > 3)
			m_nMonAniFrame = 0;
		m_fMonAniAccumTime = 0.0f;
	}
}
void cMonster::render(HDC hdc, HDC FrontMemDC){
	//monster
	cRenderer::DrawBitmap(
		hdc,
		FrontMemDC,
		_posX, _posY, m_monsterSprites[m_nMonAniFrame].width,
		m_monsterSprites[m_nMonAniFrame].height,
		hMonster,
		m_monsterSprites[m_nMonAniFrame].left,
		m_monsterSprites[m_nMonAniFrame].top,
		m_monsterSprites[m_nMonAniFrame].width,
		m_monsterSprites[m_nMonAniFrame].height,
		RGB(0, 128, 255), true);
}
void cMonster::onCreate(HINSTANCE hInst, HWND hWnd){
	hMonster = (HBITMAP)LoadImage(
		hInst,
		L"images/Poring.bmp",
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE);
}
void cMonster::onDestroy(){
	::DeleteObject(hMonster);
}