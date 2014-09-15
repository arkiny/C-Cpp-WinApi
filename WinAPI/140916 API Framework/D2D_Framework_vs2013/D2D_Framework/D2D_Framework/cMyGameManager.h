#pragma once
#include "cD2DRenderer.h"
#include "cgamemgr.h"
class cD2DRenderer;
class cMyGameManager :
	public cGameMgr
{
public:
	cMyGameManager(void);
	virtual ~cMyGameManager(void);
	virtual void Render(cD2DRenderer&);
	virtual void Update(float deltaTime);
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual void OnInit(cD2DRenderer&);
private:
	ID2D1Bitmap*	m_ipD2DBitmapBG;
	ID2D1Bitmap* m_ipD2DBitmap;
	float x;
	float y;
	float m_fAngle;
	float m_fAlpha;
};

