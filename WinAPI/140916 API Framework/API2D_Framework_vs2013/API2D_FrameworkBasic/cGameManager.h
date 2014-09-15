#pragma once


class cGameManager{
public:
	cGameManager();
	~cGameManager();
	void update(float fDelta);
	void render(HDC hdc);
	void msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	stPlayer _player;
};