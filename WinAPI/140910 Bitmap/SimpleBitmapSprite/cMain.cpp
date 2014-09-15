#include "stdafx.h"
#include "cObject.h"
#include "cMain.h"
#include "cRenderer.h"


cMain::cMain(){
	//?
	memset(m_bKeyCodeArray, 0, sizeof(m_bKeyCodeArray));

	m_background.left = 0;
	m_background.top = 0;
	m_background.width = 1028;
	m_background.height = 768;

	m_player = new cPlayer();
	m_player->setControl(m_bKeyCodeArray);
	m_pMonster[0] = new cMonster();
	m_pMonster[1] = new cMonster(400, 640);
	// ´¾´¾ Æ÷¹®È­ ½ÃÅ°±â ±ÍÂú¾Æ...
}

cMain::~cMain(){
	if (m_player != NULL){
		delete m_player;
	}
	for (cMonster* x : m_pMonster){
		if (x != NULL){
			delete x;
		}
	}
}

void cMain::update(float delta){

	m_player->update(delta);
	//monster
	for (cMonster* x : m_pMonster){
		x->update(delta);
	}
}

void cMain::render(HDC hdc, HDC FrontMemDC){
	//background
	cRenderer::DrawBitmap(
		hdc,
		FrontMemDC,
		m_background.left, 
		m_background.top, 
		m_background.width, 
		m_background.height,
		hBitBack,
		m_background.left,
		m_background.top+50,
		m_background.width,
		m_background.height,
		0, false);

	m_player->render(hdc, FrontMemDC);
	for (cMonster* x : m_pMonster){
		x->render(hdc, FrontMemDC);
	}
	
}

// input
void cMain::OnKeyDown(WPARAM wParam)
{
	m_bKeyCodeArray[wParam] = true;
}
void cMain::OnKeyUp(WPARAM wParam)
{
	m_bKeyCodeArray[wParam] = false;
}

void cMain::OnLbuttonDown(
	int mouseX,
	int mouseY)
{

}

void cMain::OnCreate(HINSTANCE hInst, HWND hWnd)
{
	m_player->onCreate(hInst, hWnd);
	for (cMonster* x : m_pMonster){
		x->onCreate(hInst, hWnd);
	}
	hBitBack = (HBITMAP)LoadImage(
		hInst,
		L"images/background.bmp",
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE);
}

void cMain::OnDestroy()
{
	m_player->onDestroy();
	for (cMonster* x : m_pMonster){
		x->onDestroy();
	}
	::DeleteObject(hBitBack);
}