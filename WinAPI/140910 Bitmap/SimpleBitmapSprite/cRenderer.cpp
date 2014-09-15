#include "stdafx.h"
#include "cRenderer.h"

cRenderer::cRenderer()
{
}


cRenderer::~cRenderer()
{
}


void cRenderer::DrawBitmap(
	HDC hdc,
	HDC FrontMemDC,
	int destX, int destY, int destWidth, int destHeight,
	HBITMAP hBit,
	int srcX, int srcY, int srcWidth, int srcHeight,
	DWORD colorKey,
	bool bTransparent)
{
	//2. 호환되는 메모리 DC 생성
	HDC BackMemDC = ::CreateCompatibleDC(hdc);
	//--------- 배경 ------------------
	HBITMAP oldBit = (HBITMAP)::SelectObject(BackMemDC, hBit);
	//4. BitBlt ( 메모리 DC => 화면DC )	
	if (bTransparent)
	{
		::TransparentBlt(FrontMemDC,
			destX, destY, destWidth, destHeight, //화면 DC 영역
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //소스 Bitmap 영역
			colorKey);
	}
	else
	{
		::StretchBlt(FrontMemDC,
			destX, destY, destWidth, destHeight, //화면 DC 영역
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //소스 Bitmap 영역
			SRCCOPY);
	}

	//5. 메모리정리( 비트맵핸들 돌려놓기, 메모리DC 해제)
	::SelectObject(BackMemDC, oldBit);
	::DeleteDC(BackMemDC);
}
