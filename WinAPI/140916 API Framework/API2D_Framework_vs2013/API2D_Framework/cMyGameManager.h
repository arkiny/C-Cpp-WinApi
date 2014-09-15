#pragma once
#include "cgamemgr.h"
class cMyGameManager :
	public cGameMgr
{
public:
	cMyGameManager(void);
	virtual ~cMyGameManager(void);
	virtual void Render(HDC hdc);
	virtual void Update(float deltaTime);
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
	cPlayer* _player;
};

