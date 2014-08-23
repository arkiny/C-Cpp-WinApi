/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
	@reference : http://www.relisoft.com/win32/winnie.html

	DO DC
	device context (DC)
	using ::GetDC and ::ReleaseDC

	if you use DC in the WM_PAINT,

	begin DC
	end DC
*/

#include "SimpleWindow.h"
#include "KeyController.h"

WinClass::WinClass(WNDPROC winProc, wchar_t const * className, HINSTANCE hInst){
	_class.style = CS_VREDRAW | CS_HREDRAW;
	_class.lpfnWndProc = winProc;				// windows procedure
	_class.cbClsExtra = 0;
	_class.cbWndExtra = 0;
	_class.hInstance = hInst;					// owner of the class
	_class.hIcon = 0;
	_class.hCursor = ::LoadCursor(NULL, IDC_ARROW);			// optional
	_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// also optional
	_class.lpszMenuName = 0;
	_class.lpszClassName = className; // mendatory
}

WinMaker::WinMaker(wchar_t const * caption, wchar_t const * className, 
					HINSTANCE hInstance){
	_hwnd = ::CreateWindow(
		className,	// name of the window class
		caption,					// window caption
		WS_OVERLAPPEDWINDOW,		// style
		// F12해서 보면 WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
		// 나중에 윈도우 만들때 최대화 버튼을 빼거나 할때 여기서 수정하면 된다고 합니다.
		CW_USEDEFAULT,				// x position
		CW_USEDEFAULT,				// y position
		800,						// width
		600,						// height
		NULL,						// handle to parent
		NULL,						// handle to menu
		hInstance,					// applcation instance
		NULL);						// window creation data	
}

LRESULT CALLBACK WinMaker::WindowProc
(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
	int mouseX = 0, mouseY = 0;
	TCHAR str[128] = L"";
	KeyController key_Ctl(hwnd, wParam);
	static RECT winRect = { 0, };
	
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rect = { 0, 0, 100, 100 };
	const int rctWidth = 300, rctHeight = 100;
	const int diameter = 100;

	static int playerX = 100, playerY = 100;
	static int playerRad = 100;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		::Ellipse(hdc, rect.left,
			rect.top,
			rect.right,
			rect.bottom);		
		EndPaint(hwnd, &ps);
		break;

	case WM_MOUSEMOVE:
		/*
			마우스 좌표를 중앙으로 원점삼고
			마우스를 따라다니는 반지름 100의 원을 그리시오
		*/
		//mouseX = LOWORD(lParam); // x coordinate
		//mouseY = HIWORD(lParam); // y coordinate
		//
		//rect.left = mouseX - diameter;
		//rect.top = mouseY - diameter;
		//rect.right = mouseX + diameter;
		//rect.bottom = mouseY + diameter;

		//hdc = ::GetDC(hwnd);
		//::Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
		//::ReleaseDC(hwnd, hdc);
		break;		

	case WM_CREATE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Created w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		break;

	case WM_SIZE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Resized w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		break;

	case WM_KEYDOWN:		
		//key_Ctl.execute();
		switch (wParam){
		case VK_LEFT:			
			playerX -= 10;			
			rect.left = playerX - playerRad;
			rect.right = playerX + playerRad;
			rect.top = playerY - playerRad;
			rect.bottom = playerY + playerRad;

			//hdc = ::GetDC(hwnd);
			//::Ellipse(hdc, playerX - playerRad, 
			//	playerY - playerRad, 
			//	playerX + playerRad, 
			//	playerY + playerRad);
			//::ReleaseDC(hwnd, hdc);

			::InvalidateRect(hwnd, NULL, TRUE);
			break;
		}

		break;

	case WM_KEYUP:
		//MessageBox(hWnd, L"WM_KEYUP", L"WM_KEYUP_Alert", MB_OK);
		break;

	case WM_LBUTTONDOWN:		
		mouseX = LOWORD(lParam); // x coordinate
		mouseY = HIWORD(lParam); // y coordinate

		// get DC를 이용한 움직임
		// 그럼 gif파일이나 애니메이션을 화면상에 올리려면 어떻게?
		// **bitblt** function을 이용하면 올릴수 있음
		//hdc = ::GetDC(hwnd);
		//::Rectangle(hdc, mouseX-150, mouseY-50, mouseX+150, mouseY+50);		
		//::ReleaseDC(hwnd, hdc);		
		
		rect.left = mouseX - (rctWidth / 2);
		rect.top = mouseY - (rctHeight / 2);
		rect.right = mouseX + (rctWidth / 2);
		rect.bottom = mouseY + (rctHeight / 2);

		hdc = ::GetDC(hwnd);
		::Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		::ReleaseDC(hwnd, hdc);

		break;


	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	}

	return ::DefWindowProc(hwnd, message, wParam, lParam);
}

