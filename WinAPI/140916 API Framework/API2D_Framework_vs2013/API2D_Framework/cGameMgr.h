#pragma once
class cPlayer;
class cGameMgr
{
public:
	cGameMgr(void);
	virtual ~cGameMgr(void);
	virtual void Render(HDC hdc)=0;
	virtual void Update(float deltaTime)=0;
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)=0;

};

