/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong	
	@reference : http://www.relisoft.com/win32/winnie.html
*/

#pragma once
#include <windows.h>

/*
	������ Ŭ����, ������ �ý��ۿ� â�� ����Ѵ�.
	���콺 Ŀ�� ���浵 �����ϰ�, ������ â �����浵 �����ϸ�,
	Ŭ���� �̸� ���� ����� �����ϴ�.
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
	������ �����츦 ����� Ŭ����
	caption�� ���� �ߴ� �̸�,
	������ ��Ÿ��, ��ġ, ũ��, ���ø����̼� �ν�ź�� ��������.
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
