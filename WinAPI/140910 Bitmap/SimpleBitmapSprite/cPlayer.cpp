#include "stdafx.h"
#include "cObject.h"
#include "cRenderer.h"

cPlayer::cPlayer(){
	m_fAccumTime = 0.0f;
	m_nAniFrame = 0;
	_posX = 0;
	_posY = 560;

	m_playerSprites[0] = MYSPRITE(180 * 1, 180 * 0, 140, 180);
	m_playerSprites[1] = MYSPRITE(180 * 2, 180 * 0, 140, 180);
	m_playerSprites[2] = MYSPRITE(180 * 3, 180 * 0, 140, 180);
	m_playerSprites[3] = MYSPRITE(180 * 4, 180 * 0, 140, 180); // 여기가지 대기
	m_playerSprites[4] = MYSPRITE(180 * 0, 180 * 1, 140, 180);
	m_playerSprites[5] = MYSPRITE(180 * 1, 180 * 1, 140, 180);
	m_playerSprites[6] = MYSPRITE(180 * 2, 180 * 1, 140, 180);
	m_playerSprites[7] = MYSPRITE(180 * 3, 180 * 1, 140, 180);
	m_playerSprites[8] = MYSPRITE(180 * 4, 180 * 1, 140, 180);
	m_playerSprites[9] = MYSPRITE(180 * 5, 180 * 1, 140, 180); // 여기까지 오른쪽이동
	m_playerSprites[10] = MYSPRITE(180 * 0, 180 * 2, 140, 180); // 왼쪽으로 이동 애니메이션
	m_playerSprites[11] = MYSPRITE(180 * 1 - 20, 180 * 2, 140, 180); // 칼 짤려서 수정
	m_playerSprites[12] = MYSPRITE(180 * 2 - 20, 180 * 2, 140, 180);
	m_playerSprites[13] = MYSPRITE(180 * 3 - 20, 180 * 2, 140, 180);
	m_playerSprites[14] = MYSPRITE(180 * 4 - 20, 180 * 2, 140, 180);
	m_playerSprites[15] = MYSPRITE(180 * 5 - 20, 180 * 2, 140, 180);
}

cPlayer::~cPlayer(){}

//void cPlayer::setControl(bool* array){
//	_control = array;
//}

void cPlayer::update(float delta){
	m_fAccumTime += delta;
	//player
	if (_control[VK_RIGHT]) // moving right
	{
		_posX += 10;
		if (m_nAniFrame < 4)
			m_nAniFrame = 4;
		if (m_fAccumTime > 0.2f)
		{
			m_nAniFrame++;
			m_fAccumTime = 0;
		}
		if (m_nAniFrame > 9)
			m_nAniFrame = 4;
	}
	else if (_control[VK_LEFT]){ // moving left
		_posX -= 10;
		if (m_nAniFrame < 11)
			m_nAniFrame = 11;
		if (m_fAccumTime > 0.2f)
		{
			m_nAniFrame++;
			m_fAccumTime = 0;
		}
		if (m_nAniFrame > 15)
			m_nAniFrame = 11;

	}
	else { // idle
		if (m_fAccumTime > 0.2f)
		{
			m_nAniFrame++;
			if (m_nAniFrame > 3)
				m_nAniFrame = 0;

			m_fAccumTime = 0.0f;
		}
	}
}

void cPlayer::render(HDC hdc, HDC FrontMemDC){
	//player
	cRenderer::DrawBitmap(
		hdc,
		FrontMemDC,
		_posX, _posY,
		180,
		180,
		hBit,
		0,
		0,
		180,
		180,
		RGB(50, 150, 200), true);
	cRenderer::DrawBitmap(
		hdc,
		FrontMemDC,
		_posX, _posY,
		m_playerSprites[m_nAniFrame].width,
		m_playerSprites[m_nAniFrame].height,
		hBit,
		m_playerSprites[m_nAniFrame].left,
		m_playerSprites[m_nAniFrame].top,
		m_playerSprites[m_nAniFrame].width,
		m_playerSprites[m_nAniFrame].height,
		RGB(50, 150, 200), true);
}

void cPlayer::onCreate(HINSTANCE hInst, HWND hWnd){
	hBit = (HBITMAP)LoadImage(
		hInst,
		L"images/swordsman.bmp",
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE);
}

void cPlayer::onDestroy(){
	::DeleteObject(hBit);
}