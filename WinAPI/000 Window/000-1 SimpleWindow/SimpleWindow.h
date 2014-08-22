/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong	
	@reference : http://www.relisoft.com/win32/winnie.html
*/

#pragma once
#include <windows.h>

/*
	윈도우 클래스, 윈도우 시스템에 창을 등록한다.
	마우스 커서 변경도 가능하고, 윈도우 창 색변경도 가능하며,
	클래스 이름 역시 등록이 가능하다.
*/
class WinClass{
public:
	WinClass(WNDPROC winProc, wchar_t const * className, HINSTANCE hInst);
	void Register(){
		::RegisterClass(&_class);
	}
private:
	WNDCLASS _class;
};

/*
	실제로 윈도우를 만드는 클래스
	caption은 제목에 뜨는 이름,
	윈도우 스타일, 위치, 크기, 어플리케이션 인스탄스 지정가능.
*/
class WinMaker{
public:
	WinMaker() : _hwnd(0){}
	WinMaker(wchar_t const * caption,
		wchar_t const * className,
		HINSTANCE hInstance);
	
	void Show(int cmdShow){
		::ShowWindow(_hwnd, cmdShow);
		::UpdateWindow(_hwnd);
	}	

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:	
	HWND _hwnd;
};
