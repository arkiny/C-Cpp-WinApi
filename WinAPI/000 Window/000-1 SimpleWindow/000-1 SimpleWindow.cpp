/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
	@reference : http://www.relisoft.com/win32/winnie.html

	기본적으로 WinAPI에서 쓰이는 스트링 Parameter는 
	대부분 LPCWSTR(Long Pointer to Constant Wide String)
	2byte char로 저장되는 str형식의 Parameter
*/

#include "000-1 SimpleWindw.h"

LRESULT CALLBACK WindowsProcedure(HWND hwnd, unsigned int message, 
									WPARAM wParam, LPARAM lParam);

WinClass::WinClass(WNDPROC winProc, wchar_t const * className, HINSTANCE hInst){
	_class.style = 0;
	_class.lpfnWndProc = winProc; // windows procedure
	_class.cbClsExtra = 0;
	_class.cbWndExtra = 0;
	_class.hInstance = hInst;  // owner of the class
	_class.hIcon = 0;
	_class.hCursor = ::LoadCursor(0, IDC_ARROW); // optional
	_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);// also optional
	_class.lpszMenuName = 0;
	_class.lpszClassName = (LPCWSTR)className; // mendatory
}

WinMaker::WinMaker(wchar_t const * caption, wchar_t const * className, 
					HINSTANCE hInstance){
	_hwnd = ::CreateWindow(
		(LPCWSTR) className,	// name of the window class
		caption,				// window caption
		WS_OVERLAPPEDWINDOW,	// style
		CW_USEDEFAULT,			// x position
		CW_USEDEFAULT,			// y position
		CW_USEDEFAULT,			// width
		CW_USEDEFAULT,			// height
		0,						// handle to parent
		0,						// handle to menu
		hInstance,				// applcation instance
		0);						// window creation data	
}

// Window Procedure called by Windows
// 콜백되는 프로시져 함수
// wmquit = 0 일경우, 종료 메세지후, 종료
// 아닐시 DefWindwsProc을 콜하여 리턴
LRESULT CALLBACK WindowProcedure
(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;

	}
	// defWindowProc은 기타 메세지를 무시하기위해 삽입
	return ::DefWindowProc(hwnd, message, wParam, lParam);
}

// Window API는 WinMain에서 실행됨
// while loop위에서 return 0을 받을때까지 계속 진행
// wm_quit을 받지 않을경우 0이 아닌 수
// wm_quit을 받을경우 0을 받게 됨
// 만약 에러 진행시 -1
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	char * cmdParam, int cmdShow){

	wchar_t className[] = L"MyfirstWindow";

	// Winclass 클래스를 윈도우 시스템에 등록
	WinClass winClass(WindowProcedure, className, hInst);
	winClass.Register();

	// 만들어서 보여주고
	WinMaker win(L"이게 나의 첫 윈도창이다! 안녕 세상!", className, hInst);
	win.Show(cmdShow);

	// 외부 이벤트를 받아와서 처리
	MSG  msg;
	int status;
	while ((status = ::GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if (status == -1)
			return -1;
		::DispatchMessage(&msg);
	}

	return msg.wParam;
}


// 참고용 쓰레기 코드 
// (string을 wstr으로 바꾸거나 char를 wchar_t 로 바꾸거나..)

/*WCHAR strtemp[50];
MultiByteToWideChar(0, 0, className, 50, strtemp, 50);
LPCWSTR cstrtemp = strtemp;*/
// string to wide string(UNICODE)
/*std::wstring strtemp(className.begin(), className.end());
LPCWSTR classNamet = strtemp.c_str();*/

/*std::wstring strtemp = std::wstring(className.begin(), className.end());
LPCWSTR LWclassName = strtemp.c_str();
strtemp = std::wstring(caption.begin(), caption.end());
LPCWSTR LWcaptiont = strtemp.c_str();*/

// string to wide string(UNICODE)