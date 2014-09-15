#pragma once

class cObject{
public:
	virtual ~cObject(){}

protected:
	int _posX;
	int _posY;
};

class cPlayer : public cObject{
public:
	cPlayer();
	~cPlayer();

	void setControl(bool* array){
		_control = array;
	}

	void update(float delta);
	void render(HDC hdc, HDC FrontMemDC);
	void onCreate(HINSTANCE hInst, HWND hWnd);
	void onDestroy();

private:
	bool* _control;
	float m_fAccumTime;
	int m_nAniFrame;
	MYSPRITE m_playerSprites[16];

	HBITMAP hBit;
};

class cMonster : public cObject{
public :
	cMonster(); 
	cMonster(int x, int y);
	~cMonster();

	void update(float delta);
	void render(HDC hdc, HDC FrontMemDC);
	void onCreate(HINSTANCE hInst, HWND hWnd);
	void onDestroy();

private:
	float m_fMonAniAccumTime;
	int m_nMonAniFrame;
	MYSPRITE m_monsterSprites[4];

	HBITMAP hMonster;
};