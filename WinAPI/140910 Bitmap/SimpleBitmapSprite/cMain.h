#pragma once

class cPlayer;
class cMonster;

class cMain{
public:
	cMain();
	~cMain();
	void update(float delta);
	void render(HDC hdc, HDC frontDC);

	// event control
	void OnCreate(HINSTANCE hInst, HWND hWnd);
	void OnDestroy();

	// key control
	void OnKeyDown(WPARAM wParam);
	void OnKeyUp(WPARAM wParam);
	void OnLbuttonDown(int mouseX,
		int mouseY);

private:
	bool m_bKeyCodeArray[256];
	//-> °úÁ¦
	cPlayer* m_player;
	cMonster* m_pMonster[2];
	//cMonster* m_pMonster;
	//bacground
	MYSPRITE m_background;
	//---------player----	
	//float m_fAccumTime;
	//int m_nAniFrame;
	//MYSPRITE m_playerSprites[16];
	//int m_nPlayerX;
	//int m_nPlayerY;

	//------------------
	//float m_fMonAniAccumTime;
	//int m_nMonAniFrame;
	//MYSPRITE m_monsterSprites[4];
	//int m_nMonsterX;
	//int m_nMonsterY;

	HBITMAP hBitBack;

	RECT m_winRect;
};