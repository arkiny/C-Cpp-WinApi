/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
	@reference : http://www.relisoft.com/win32/winnie.html

	�⺻������ WinAPI���� ���̴� ��Ʈ�� Parameter�� 
	��κ� LPCWSTR(Long Pointer to Constant Wide String)
	2byte char�� ����Ǵ� str������ Parameter

	unsigned short�� ������ �Ѱ͵�
	ifndef���� multitype�� UNICODE ���� Ȯ��

	WCHAR
	wchar_t
	TCHAR

	���� ����ÿ��� UNICODE�� ���� ����
	���� �����ð����� WCHAR�� �� ����
	���ξ� ������� Ȯ�� �Ұ�

	h handle ������ ��Ʈ�� ���ϵ� �ڵ�
	sz ���� ���ڿ�

	lp -> long pointer(4����Ʈ ������)

	��κ� �����Ǹ� ���ϱ⶧���� LP�� ������ ������ �����Ͷ�� ������ �Ѵ�.
	��κ� ����� ������ ���������� ������ �پ��ִ�.(�빮�ڷ�)
	char�� wchar�� �߰� Ÿ���� TCHAR

	�����ڵ� �����ռ��� �Լ� �տ� �ҹ��� l �� �ٿ�����Ѵ�.
	lstrlen
	lstrcpy
	lstrcat
	lstrcmp
	wsprintf
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
		// F12�ؼ� ���� WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
		// ���߿� ������ ���鶧 �ִ�ȭ ��ư�� ���ų� �Ҷ� ���⼭ �����ϸ� �ȴٰ� �մϴ�.
		CW_USEDEFAULT,				// x position
		CW_USEDEFAULT,				// y position
		800,						// width
		600,						// height
		NULL,						// handle to parent
		NULL,						// handle to menu
		hInstance,					// applcation instance
		NULL);						// window creation data	
}

// Window Procedure called by Windows
// �ݹ�Ǵ� ���ν��� �Լ�
// wmquit = 0 �ϰ��, ���� �޼�����, ����
// �ƴҽ� DefWindwsProc�� ���Ͽ� ����
// ���⼭ Ű���̳� �� ���� ����
// �ǽ� :
// 1. ������ ������ msgbox �Ѹ���
// 2. Ű ������
// 3. Ű ����
// 4. ���콺 ��Ŭ��
// ��κ� �Է�����
// ���̽�ƽ�� ���� Ű�� �ؼ� keydown���� �����Ѵ�.
// �� �����Ӹ��� ��� �ݺ��ϸ鼭 ȭ���� �����ϸ� �ִϸ��̼� ó���� �Ѵ�.
// ���� Ű���带 �����ų� ���콺�� Ŭ�������� (Ư�� �̺�Ʈ) ó���� �˾ƾ� �ش� �ڵ带 �̿��Ҽ�
// �ִ�. �� ���õ� �ǽ��� �غ��Ž�
// switch ���� �Ⱦִ� ���ο� ������ �����Ҽ� ����. �׷� ��쿡�� ����� �����������
// ���� ������ ����� �ִ�. (���� ����� �δ���, ������ �δ���)
//
// ������ ����� �궧 Rectangle�� �̿��ؼ� 
// lefttop, rightbottom�� ������ �ͼ� ȭ���� �߾������� ������ �ü��� �ִ�.
// wparam lparam �Ѵ� 4����Ʈ
LRESULT CALLBACK WinMaker::WindowProc
(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
	// �ݵǸ� ���������� �ʱ�ȭ �ȴ�.
	// �ƿ� ���������� ¥���� static�� �̿��ϵ��� �Ѵ�.
	int mouseX = 0, mouseY = 0;
	TCHAR str[128] = L"";
	KeyController key_Ctl(hwnd, wParam);
	static RECT winRect = { 0, };
	
	switch (message)
	{
	case WM_CREATE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Created w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		return 0;

	case WM_SIZE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Resized w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		break;

	// ���Ŀ� KeyControl Class�� ���� ó�� ��Ű�� �� ����� ���� �մϴ�.
	// ������ �ϴ� �ڵ尡 ��������� ���� Ű��Ʈ�� �Ŵ����� �̿��Ҽ� ������
	// ������ �׸�ŭ �޸𸮸� �� ��Ƹ԰� ���μ���Ÿ���� ��������� �ִٴ°�?
	// ���� �׷��� ��������
	case WM_KEYDOWN:		
		key_Ctl.execute();
		return 0;

	case WM_KEYUP:
		//MessageBox(hWnd, L"WM_KEYUP", L"WM_KEYUP_Alert", MB_OK);
		return 0;

	case WM_LBUTTONDOWN:
		// ���󿡼� ���콺�� ��ġ�� ������ �ְ�, �� ��ġ ������ ǥ���ϱ� ����
		// X��ǥ�� Y��ǥ�� �ʿ��ϴ�. ȭ�鿡���� ��ī��Ʈ ��ǥ�� �̿��Ѵ�.
		// 2����Ʈ�� �̿��ϱ� ������ ��Ʈ������ �̿��ؼ� ������ �ִ�.
		// �϶�� �ϸ� �Ҽ� ������ ��ũ�θ� ����� ���� ��
		
		mouseX = LOWORD(lParam);
		mouseY = HIWORD(lParam);

		wsprintf(str, L"%d, %d", mouseX, mouseY);
		::SetWindowText(hwnd, str);
		//MessageBox(hWnd, L"WM_LBUTTONCLICK", L"WM_LBUTTONCLICK_Alert", MB_OK);
		return 0;

	case WM_MOUSEMOVE:
		return 0;

	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hwnd, message, wParam, lParam);
}




// ����� ������ �ڵ� 
// (string�� wstr���� �ٲٰų� char�� wchar_t �� �ٲٰų�..)

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