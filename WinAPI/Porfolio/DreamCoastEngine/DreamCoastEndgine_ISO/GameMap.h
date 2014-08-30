#pragma once

#include <vector>
#include <Windows.h>

using std::vector;

typedef struct Tile{
	int type;
}TILE, *LPTILE;

typedef class GameMap{
public:
	GameMap(){}
	~GameMap(){}

	void update(float delta){
	}

	void render(HDC &hdc){		
		drawMap(hdc);
	}

	POINT mbClick(int x, int y){
		for (int j = 0; j < _vertical; j++){
			for (int i = 0; i < _horizontal; i++){
				if (isInISOTile({ x, y }, { i, j })){
					//_pick = { i, j };
					//_picked = true;
					return { i, j };
					break;
				}
			}			
		}
		//_picked = false;
		return{ 11, 11 };
	}

	void drawPickTile(int x, int y, HDC &hdc){
		if (_picked){
			drawTile(x, y, 1, hdc);
		}
	}

private:
	POINT _pick;
	BOOL _picked = false;

	int _vertical = 10;
	int _horizontal = 10;

	int _tileWidth = 50;
	int _tileHeight = 50;

	int moveX = _tileWidth * 10;
	int moveY = _tileHeight;


	// 맵 정보 저장 [세로축][가로축]
	// int _mapInfo[10][10] = 0

	// 차후 추가 내용
	// 맵 크기는 고정이 아니기에 유동적으로 관리할수 있는 벡터를 이용한다.
	// 일단 다 0으로 고정해놓고 실시
	//vector<LPTILE> _mapArray;

	// 타일 그리기 Helper method
	void drawTile(int x, int y, int type, HDC &hdc){

		int drawWidth = _tileWidth;
		int drawHeight = _tileHeight / 2;


		switch (type)
		{
		case 0:		// 일반 타일일 경우
			//MoveToEx(hdc, x - drawWidth + moveX, y + moveY, NULL);
			//LineTo(hdc, x + moveX, y + drawHeight + moveY);
			//LineTo(hdc, moveX + x + drawWidth, moveY + y);
			//LineTo(hdc, moveX + x, moveY + y - drawHeight);
			//LineTo(hdc, moveX + x - drawWidth, moveY + y);
			MoveToEx(hdc, x - drawWidth, y, NULL);
			LineTo(hdc, x, y + drawHeight);
			LineTo(hdc, x + drawWidth, y);
			LineTo(hdc, x,  y - drawHeight);
			LineTo(hdc, x - drawWidth, y);
			break;
		default:	// 다른 경우
			MoveToEx(hdc, moveX + x - _tileWidth, moveY + y - _tileHeight, NULL);
			LineTo(hdc, moveX + x + _tileWidth, moveY + y - _tileHeight);
			LineTo(hdc, moveX + x + _tileWidth, moveY + y + _tileHeight);
			LineTo(hdc, moveX + x - _tileWidth, moveY + y + _tileHeight);
			LineTo(hdc, moveX + x - _tileWidth, moveY + y - _tileHeight);
			break;
		}
	}

	void drawMap(HDC &hdc){
		POINT pt;	

		int x, y, nx, ny;
		TCHAR text[20] = L"";
		
		
		for (int j = 0; j < _vertical; j++){
			for (int i = 0; i < _horizontal; i++){
				x = j*_tileWidth;
				y = i*_tileHeight;

				pt = twoDtoISO({ x, y });

				drawTile(pt.x, pt.y, 0, hdc);
				//drawTile(x, y, 1, hdc);

				wsprintf(text, L"(%d, %d)", i, j);
				::TextOut(hdc, pt.x , pt.y , text, 6);
			}
		}

		x = _pick.x*_tileWidth;
		y = _pick.y*_tileHeight;
		pt = twoDtoISO({ x, y });

		drawTile(pt.x, pt.y, 0, hdc);
	}

	// 직선의 방정식을 이용한 타일 확인
	BOOL isInISOTile(POINT cur, POINT tilepos){
		int x = tilepos.y * _tileWidth;
		int y = tilepos.x * _tileHeight;
		POINT pt = twoDtoISO({ x, y });
		float m = 0.5f;

		RECT tileArea = {
			pt.x - _tileWidth,
			pt.y - (_tileHeight / 2),
			pt.x + _tileWidth,
			pt.y + (_tileHeight/2) };

		POINT left = { tileArea.left, (tileArea.top + ((tileArea.bottom - tileArea.top) / 2)) };
		POINT top = { (tileArea.left + ((tileArea.right - tileArea.left) / 2)), tileArea.top };
		POINT right = { tileArea.right, (tileArea.top + ((tileArea.bottom - tileArea.top) / 2)) };
		POINT bottom = { (tileArea.left + ((tileArea.right - tileArea.left) / 2)), tileArea.bottom };
		
		float l1 = left.y + (m*left.x); // 왼쪽 위 구별용
		float l2 = top.y + (-m*top.x); // 오른쪽 위 구별용
		float l3 = right.y + (m*right.x); // 왼쪽 아래 구별용
		float l4 = bottom.y + (-m*bottom.x); // 오른쪽 아래 구별용

		float r1 = -m * cur.x - cur.y + l1;
		float r2 = m * cur.x - cur.y + l2;
		float r3 = -m * cur.x - cur.y + l3;
		float r4 = m * cur.x - cur.y + l4;

		if (r1 <= 0.0f && r2 <= 0.0f && r3 >= 0.0f && r4 >= 0.0f){
				return true;
		}
		else {
			return false;
		}
	}

	POINT twoDtoISO(POINT in){
		POINT ret = {};
		ret.x = in.x - in.y + moveX;
		ret.y = (in.x + in.y) / 2 + moveY;
		return ret;
	}

}GAMEMAP, *LPGAMEMAP;