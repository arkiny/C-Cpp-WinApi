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
	//2. ȣȯ�Ǵ� �޸� DC ����
	HDC BackMemDC = ::CreateCompatibleDC(hdc);
	//--------- ��� ------------------
	HBITMAP oldBit = (HBITMAP)::SelectObject(BackMemDC, hBit);
	//4. BitBlt ( �޸� DC => ȭ��DC )	
	if (bTransparent)
	{
		::TransparentBlt(FrontMemDC,
			destX, destY, destWidth, destHeight, //ȭ�� DC ����
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //�ҽ� Bitmap ����
			colorKey);
	}
	else
	{
		::StretchBlt(FrontMemDC,
			destX, destY, destWidth, destHeight, //ȭ�� DC ����
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //�ҽ� Bitmap ����
			SRCCOPY);
	}

	//5. �޸�����( ��Ʈ���ڵ� ��������, �޸�DC ����)
	::SelectObject(BackMemDC, oldBit);
	::DeleteDC(BackMemDC);
}
