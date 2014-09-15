#pragma once
class cRenderer
{
public:
	cRenderer();
	~cRenderer();
	static void DrawBitmap(
		HDC hdc,
		HDC FrontMemDC,
		int destX, int destY, int destWidth, int destHeight,
		HBITMAP hBit,
		int srcX, int srcY, int srcWidth, int srcHeight,
		DWORD colorKey,
		bool bTransparent);
};

