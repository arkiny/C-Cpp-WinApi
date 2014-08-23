/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
	직접 Key Control을 담당, 처리해주는 Class
*/

#pragma once

#include <windows.h>

class KeyController{
public:
	KeyController(){
		_hwnd = 0;
		_wParam = 0;
	}

	KeyController(HWND hwnd, unsigned int wParam){
		_hwnd = hwnd;
		_wParam = wParam;
	}

	// wParam 값에 따라 컨트롤을 실행한다.
	bool execute();
	
private:
	HWND _hwnd;
	unsigned int _wParam;
};

bool KeyController::execute(){
	// this var ends its lift in this method. I think it does not have to be static
	RECT winRect = { 0, }; 
	// point for mouse position
	POINT pt;
	RECT rect = { 100, 100, 200, 200 };
	HDC hdc;

	switch (_wParam)
	{
	case VK_LEFT:	// left arrow
		hdc = ::GetDC(_hwnd);
		::Ellipse(hdc, rect.left--, rect.top, rect.right--, rect.bottom);
		::ReleaseDC(_hwnd, hdc);
		break;
	case VK_RIGHT:	// right arrow
		
		break;
	case VK_UP:		 // up arrow
		
		break;
	case VK_DOWN:	 // down arrow
		
		break;

	case VK_SPACE:
		break;

	case VK_ESCAPE:
		::PostQuitMessage(0);
		break;

	default:
		// nothing happen right now
		break;
	}

	return true;
}