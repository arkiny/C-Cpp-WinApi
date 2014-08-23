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
	
	switch (_wParam)
	{
	case VK_LEFT:	// left arrow
		// get positions
		::GetWindowRect(_hwnd, &winRect);
		::MoveWindow(_hwnd, (winRect.left -= 1), winRect.top,
			(winRect.right -= 1) - winRect.left, winRect.bottom - winRect.top, true);
		break;
	case VK_RIGHT:	// right arrow
		::GetWindowRect(_hwnd, &winRect);
		::MoveWindow(_hwnd, (winRect.left += 1), winRect.top,
			(winRect.right += 1) - winRect.left, winRect.bottom - winRect.top, true);
		break;
	case VK_UP:		 // up arrow
		::GetWindowRect(_hwnd, &winRect);
		::MoveWindow(_hwnd, winRect.left, (winRect.top -= 1),
			winRect.right - winRect.left, (winRect.bottom -= 1) - winRect.top, true);
		break;
	case VK_DOWN:	 // down arrow
		::GetWindowRect(_hwnd, &winRect);
		::MoveWindow(_hwnd, winRect.left, (winRect.top += 1),
			winRect.right - winRect.left, (winRect.bottom += 1) - winRect.top, true);
		break;
	case 65:	// a, left
	case 97:	// A
		::GetCursorPos(&pt);	
		SetCursorPos(pt.x -= 1, pt.y);
		break;

	case 68:	// d, right
	case 100:	// D
		::GetCursorPos(&pt);		
		SetCursorPos(pt.x += 1, pt.y);
		break;

	case 87:	// w, up
	case 119:	// W
		::GetCursorPos(&pt);
		SetCursorPos(pt.x, pt.y -= 1);
		break;

	case 83:	// s, down
	case 115:	// S
		::GetCursorPos(&pt);		
		SetCursorPos(pt.x, pt.y += 1);
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