#include "StdAfx.h"
#include "cMyGameManager.h"
#include "cPlayer.h"

cMyGameManager::cMyGameManager(void)
{
	_player = new cPlayer;
}


cMyGameManager::~cMyGameManager(void)
{
	delete _player;
}

void cMyGameManager::Render(HDC hdc)
{
	_player->Render(hdc);
	
}

void cMyGameManager::Update(float deltaTime)
{
	_player->Update(deltaTime);
}

void cMyGameManager::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	
	case WM_KEYDOWN:
		if(wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
		}
		return;

	}
}