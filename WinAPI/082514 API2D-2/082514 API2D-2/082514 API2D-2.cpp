// 082514 API2D-2.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

/*
	�簢��
	1. ó�� ��ġ ��� ��� ����
	2. ��ȥ��, �ε巴�� ���������� �̵��ϴٰ�, ���� ������ ������ �ٲ㼭 �ݴ�� (�Դٸ� ���ٸ�)

	���� �÷��̾ �����̰�
*/

#include "stdafx.h"
#include "082514 API2D-2.h"

#define MAX_LOADSTRING 100
#define TIMER_ID 5
#define TIMER_ID2 4

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.
int mX, mY;
//static RECT _circle;
POINT _circle;

// �ʹ� ��ư� �����ߴ� �Ф�
static bool isRightKeyDown = false,
isLeftKeyDown = false,
isUpKeyDown = false,
isDownKeyDown = false;


// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void Update(float delta);
void Render(HDC hdc);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY082514API2D2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY082514API2D2));

	// �⺻ �޽��� �����Դϴ�.
	// �޽��������� ���ȭ���� ���� ���� ��� ���ư��� �����.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY082514API2D2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY082514API2D2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	/*
		1. ���콺 Ŭ���� �������κ��� ���η� 300pixel
		������ ������ �׷���.
		2. �����츦 �ּ�ȭ ���� �����ص�, ������ �����Ǿ����
	*/
	/*
		�ǽ�
		1. Ű���� Ŀ��(ȭ��ǥ) ������
		���� 5pixel�� �̵���Ų��
		WM_KEYDWON, w Param = VK_RIGHT,
		Ellipse() �Լ�
		2. �ε巴��~
	*/

	/* 
		���������� �޽����� �߻���ų�� ������,
		���� ��ĥ�� �ִ�. -> setTimer�� �̿��Ѵ�.
	*/

	switch (message)
	{		
	case WM_CREATE:
		// handler, IDEVENT, ����(1000 = 1��) �������ϸ� �ٲ㵵 �ǹ̰� ����,
		// callback �Լ��� ������! �ϸ� �Լ� �����ͷ� ������ �ִ�. Ÿ�̸� �߻��� �ݹ��Լ� ����
		::SetTimer(hWnd, TIMER_ID, 50, NULL); // timer��� msg�� �߻���Ű�� �߻����̴�.
		_circle = { 100, 100 };
		break;

	case WM_TIMER:
		if (wParam == TIMER_ID)
		{
			Update(50 / 1000.0f);
		}
		::InvalidateRect(hWnd, NULL, true);
		break;

	case WM_KEYDOWN:
		switch (wParam){
		case VK_RIGHT:
			isRightKeyDown = true;
			break;
		case VK_LEFT:
			isLeftKeyDown = true;
			break;
		case VK_UP:
			isUpKeyDown = true;
			break;
		case VK_DOWN:
			isDownKeyDown = true;
			break;
		}
		::InvalidateRect(hWnd, NULL, true);		
		break;	
	
	case WM_KEYUP:
		switch (wParam){
		case VK_RIGHT:
			isRightKeyDown = false;
			break;
		case VK_LEFT:
			isLeftKeyDown = false;
			break;
		case VK_UP:
			isUpKeyDown = false;
			break;
		case VK_DOWN:
			isDownKeyDown = false;
			break;
		}

		break;

	case WM_LBUTTONDOWN:
		mX = LOWORD(lParam);
		mY = HIWORD(lParam);

		// ��ȿȭ�� �ϸ� �Ͼ�� ����
		// �ι��� Rect�� ��ȿȭ �ϴ� ����
		// �𸣰ų� ��ü ������ �ٽ� �׸��� �ʹٰ� �Ҷ� NULL�� �ִ´�.
		// ������ ��� �κи� �ٽ� �׸��� �� ���� �Ұ����ϴ�
		// ��ȿȭ �� ��� WM_PAINT�޼����� �߻��Ѵ�.
		// ����° ���ڰ��� ��쿡�� ����� �߻��Ұ��ΰ� ������� �߻��Ұ��ΰ�. (���)
		::InvalidateRect(hWnd, NULL, true);		
		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hdc = ::GetDC(hWnd);
		Render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_DESTROY:
		//::KillTimer(hWnd, TIMER_ID);
		::KillTimer(hWnd, TIMER_ID);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// �ٽ� �����ӟp
void Update(float delta){	
	if (isRightKeyDown){
		_circle.x += 5;
	}
	if (isLeftKeyDown){
		_circle.x -= 5;
	}
	if (isUpKeyDown){
		_circle.y -= 5;
	}
	if (isDownKeyDown){
		_circle.y += 5;
	}	
}

void Render(HDC hdc){	
	::MoveToEx(hdc, mX, mY, NULL);
	// ù ���� ���������� ���� ��� �̾ �׸��� �ȴ�.		
	::LineTo(hdc, mX + 300, mY);
	::Ellipse(hdc, _circle.x - 25, _circle.y - 25, _circle.x + 25, _circle.y + 25);
}