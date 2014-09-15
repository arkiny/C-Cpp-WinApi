#pragma once
class cPlayer;
class cD2DRenderer;
class cGameMgr
{
public:
	cGameMgr(void);
	virtual ~cGameMgr(void);
	virtual void Render(cD2DRenderer&) = 0;
	virtual void Update(float deltaTime)=0;
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)=0;
	virtual void OnInit(cD2DRenderer&) = 0;
};

