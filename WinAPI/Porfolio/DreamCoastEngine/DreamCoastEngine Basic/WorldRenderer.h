//WorldRenderer->WorldRenderer Refers World Class
//- LineTo를 이용, IsoMetric으로 Render하되, 
//각 마름모 중앙에 좌표를 Text로 렌더한다.
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
				// 원래 사각형의 좌표
				x = j*tileWidth; // on screen
				y = i*tileHeight;

				
				// 원래 사각형이 있어야 할 좌표에서 ISOMetric위의 좌표로 치환
				pt = _lpworld->getGameMap().TwoDtoISO({ x, y });

				drawTile(pt.x + (tileWidth * _lpworld->getGameMap().getMapSize()._x), 
					pt.y + 100, 0, hdc);

				// 좌표 출력
				wsprintf(text, L"(%d, %d)", i, j);
				::TextOut(hdc, pt.x + (tileWidth *_lpworld->getGameMap().getMapSize()._x),
					pt.y + 100 - 5, text, 6);				
			}
		}

		// 차후 PickRender를 위해 남겨놓은 주석
	/*	pt = _lpworld->getGameMap().TwoDtoISO({ 1*tileWidth, 2*tileHeight });
		drawTile(pt.x + (tileWidth *_lpworld->getGameMap().getMapSize()._x)
			, pt.y+100, 1, hdc);*/
	}

	void drawTile(int x, int y, int type, HDC &hdc){
		int tileWidth = _lpworld->getGameMap().getTileSize();
		// 수정시 twodToISO도 꼭 체크해줘야함
		// 아래의 식은 원래 정마름모를 납작하게 만들어준다.
		// twodToISO는 원래부터 납작한 정마름모의 좌표를 리턴해준다.
		int tileHeight = tileWidth /2;
		if (type == 0){
			// 그림이기도 하고 범위기도 하다.
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
