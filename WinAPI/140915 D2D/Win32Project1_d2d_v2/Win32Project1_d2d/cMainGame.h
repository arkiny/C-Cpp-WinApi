#pragma once
#include "cD2DRenderer.h"
class cMainGame
{
private:
	ID2D1Bitmap*	m_ipD2DBitmapBG;
	ID2D1Bitmap*	m_ipD2DBitmap;
	int x;
	int y;
	float m_fAngle;
	float m_fAlpha;
public:
	cMainGame();
	~cMainGame();
	void Update(float delta);
	void Render(cD2DRenderer& renderer);
	void LoadImages(cD2DRenderer& renderer,HWND hWnd);
};

