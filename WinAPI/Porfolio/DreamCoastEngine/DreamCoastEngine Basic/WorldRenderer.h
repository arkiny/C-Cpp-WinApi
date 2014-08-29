//WorldRenderer->WorldRenderer Refers World Class
//- LineTo�� �̿�, IsoMetric���� Render�ϵ�, 
//�� ������ �߾ӿ� ��ǥ�� Text�� �����Ѵ�.
#pragma once
#include <Windows.h>

#include "World.h"

class WorldRenderer{
public:
	WorldRenderer(){}
	WorldRenderer(LPWORLD lpworld){
		_lpworld = lpworld; 
	}
	~WorldRenderer(){}

	//@param delta time in secons since the last render
	void render(HDC &hdc, RECT &winRect){
		drawMap(hdc, winRect);
		_lpworld->getUI().Render(hdc);
	}

private:
	// Drawing Map
	void drawMap(HDC &hdc, RECT &winRect){
		POINT pt;
		int x, y; // change normal coordinate to screenCoordnate
		int tileWidth = _lpworld->getGameMap().getTileSize();
		int tileHeight = tileWidth;
		TCHAR text[20] = L"";

		for (int i = 0; i < _lpworld->getGameMap().getMapSize()._x; i++){
			// columns
			for (int j = 0; j < _lpworld->getGameMap().getMapSize()._y; j++){
				// ���� �簢���� ��ǥ
				x = j*tileWidth; // on screen
				y = i*tileHeight;

				
				// ���� �簢���� �־�� �� ��ǥ���� ISOMetric���� ��ǥ�� ġȯ
				pt = _lpworld->getGameMap().TwoDtoISO({ x, y });

				drawTile(pt.x + (tileWidth * _lpworld->getGameMap().getMapSize()._x), 
					pt.y + 100, 0, hdc);

				// ��ǥ ���
				wsprintf(text, L"(%d, %d)", i, j);
				::TextOut(hdc, pt.x + (tileWidth *_lpworld->getGameMap().getMapSize()._x),
					pt.y + 100 - 5, text, 6);				
			}
		}

		// ���� PickRender�� ���� ���ܳ��� �ּ�
	/*	pt = _lpworld->getGameMap().TwoDtoISO({ 1*tileWidth, 2*tileHeight });
		drawTile(pt.x + (tileWidth *_lpworld->getGameMap().getMapSize()._x)
			, pt.y+100, 1, hdc);*/
	}

	void drawTile(int x, int y, int type, HDC &hdc){
		int tileWidth = _lpworld->getGameMap().getTileSize();
		// ������ twodToISO�� �� üũ�������
		// �Ʒ��� ���� ���� �������� �����ϰ� ������ش�.
		// twodToISO�� �������� ������ ���������� ��ǥ�� �������ش�.
		int tileHeight = tileWidth /2;
		if (type == 0){
			// �׸��̱⵵ �ϰ� �����⵵ �ϴ�.
			MoveToEx(hdc, x - tileWidth, y, NULL);
			LineTo(hdc, x, y + tileHeight);
			LineTo(hdc, x + tileWidth, y);
			LineTo(hdc, x, y - tileHeight);
			LineTo(hdc, x - tileWidth, y);			
		}
		else {
			MoveToEx(hdc, x - tileWidth, y - tileHeight, NULL);
			LineTo(hdc, x + tileWidth, y - tileHeight);
			LineTo(hdc, x + tileWidth, y + tileHeight);
			LineTo(hdc, x - tileWidth, y + tileHeight);
			LineTo(hdc, x - tileWidth, y - tileHeight);
		}
	}

	// private vars
	LPWORLD _lpworld;
};
