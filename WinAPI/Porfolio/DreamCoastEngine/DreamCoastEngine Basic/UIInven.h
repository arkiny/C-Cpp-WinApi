#pragma once
#include <Windows.h>

enum BTN_STATUS { NONE, ON, LDOWN };

class UIInven{
public:
	UIInven(){}
	~UIInven(){}

	void setpos(int x, int y){
		_pos.x = x;
		_pos.y = y;
		setRect();
		_uiclick = false;
	}

	void setRect(){
		_background.left = _ui.left = _pos.x;
		_background.top = _ui.top = _pos.y;
		_background.right = _ui.right = _pos.x + 200;
		_ui.bottom = _pos.y + 20;
		_background.bottom = _pos.y + 150;
		_uiclick = false;
		

		_button.right = _ui.right - 2;
		_button.left = _ui.right - 20;
		_button.top = _ui.top + 2;
		_button.bottom = _ui.bottom - 2;
	}
	
	void saveMBoldpos(int x, int y){
		_mb_cache_old = { x, y };
		_mb_cache_gap = { x - _pos.x , y - _pos.y };
	}

	void moveTo(int x, int y){
		_pos.x = x - _mb_cache_gap.x;
		_pos.y = y - _mb_cache_gap.y;
		setRect();
	}

	void Render(HDC& hdc){
		::Rectangle(hdc, _background.left,
			_background.top,
			_background.right,
			_background.bottom);

		::Rectangle(hdc, _ui.left,
			_ui.top,
			_ui.right,
			_ui.bottom);


		HBRUSH myBrush, oldBrush;
		switch (_st)
		{
		case NONE:
			myBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
			oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
			break;
		case ON:
			myBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
			oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
			break;
		case LDOWN:
			myBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
			oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
			break;
		default:
			break;
		}

		::Rectangle(hdc, _button.left,
			_button.top,
			_button.right,
			_button.bottom);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

		if (_uiclick)
		{
			::TextOut(hdc, _ui.left + 10, _ui.top+1, L"click", 5);
		}
	}

	// 마우스 커서체킹
	BOOL isInside(int x, int y){
		if (_ui.left <= x && _ui.right >= x
			&& _ui.top <= y && _ui.bottom >= y){
			if (_button.left <= x && _button.right >= x
				&& _button.top <= y && _button.bottom >= y){
				return false;
			}
			else
				return true;
		}
		else {
			return false;
		}

	}

	void setUImoving(BOOL in){
		_uiclick = in;
	}

	BOOL getUImoving(){
		return _uiclick;
	}

	void setBtnStatus(int in){
		_st = (BTN_STATUS)in;
	}

	BOOL isInsideBtn(int x, int y){
		return (_button.left <= x && _button.right >= x
			&& _button.top <= y && _button.bottom >= y);
	}

	int getBtnStatus(){
		return _st;
	}

	POINT getOldMBCurpos(){
		return _mb_cache_old;
	}

	POINT getNewMBCurpos(){
		return _mb_cache_new;
	}

private:
	// UI 
	BOOL _uiclick;
	RECT _background;
	RECT _ui;
	POINT _pos;
	POINT _mb_cache_old;
	POINT _mb_cache_new;

	POINT _mb_cache_gap;

	RECT _button;
	BTN_STATUS _st = NONE;
	
};