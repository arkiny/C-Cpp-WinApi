// Vector2D.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//


#include "stdafx.h"
#include "Vector2D.h"
#include <cmath>

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.

POINT player = { 100, 120 };
POINT target = { 500, 250 };

typedef struct Vector2D{
	float x;
	float y;
}VECTOR2D;

/*
	player�� �簢��
	target�� ������ �׸��ÿ�
*/

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

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
	LoadString(hInstance, IDC_VECTOR2D, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VECTOR2D));

	// �⺻ �޽��� �����Դϴ�.
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VECTOR2D));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_VECTOR2D);
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
	TCHAR str[128];

	switch (message)
	{
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
	{
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		::Ellipse(hdc,
			player.x - 10,
			player.y - 10,
			player.x + 10,
			player.y + 10);
		::Rectangle(hdc,
			target.x - 10,
			target.y - 10,
			target.x + 10,
			target.y + 10);

		//player ��ġ ������ ������ ���͸� �����.
		
		
		float v1X = player.x;
		float v1Y = player.y;
		// ���͸� �׸��� �������� �������� ��´�.
		::MoveToEx(hdc, 0, 0, NULL); 
		::LineTo(hdc, v1X, v1Y);
		wsprintf(str, L"vector1");
		::TextOut(hdc, v1X, v1Y, str, lstrlen(str));

		// target
		float v2X = target.x;
		float v2Y = target.y;
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, v2X, v2Y);
		wsprintf(str, L"vector2");
		::TextOut(hdc, v2X, v2Y, str, lstrlen(str));

		// target - player // vdir
		float v3X = v2X - v1X;
		float v3Y = v2Y - v1Y;
		::Rectangle(hdc,
			v3X - 5,
			v3Y - 5,
			v3X + 5,
			v3Y + 5);
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, v3X, v3Y);
		wsprintf(str, L"vector2 - vector1");
		::TextOut(hdc, v3X, v3Y, str, lstrlen(str));

		// final = (target-player) + player
		float v4X = v1X + v3X;
		float v4Y = v1Y + v3Y;
		::Rectangle(hdc,
			v4X - 5,
			v4Y - 5,
			v4X + 5,
			v4Y + 5);
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, v4X, v4Y);
		wsprintf(str, L"vector1 + (vector2 - vector1)");
		::TextOut(hdc, v4X, v4Y+20, str, lstrlen(str));

		// ���� ���͸� ����� ���
		// a����, b����, �밢 r, 
		// r�� 1�� ����� �����?! 
		// �� r�� ���������� 1....

		// vDir�� r(������ length)
		// normalize
		float r = std::sqrtf((v3X * v3X) + (v3Y*v3Y)); 
		float vDirNormalizedX = v3X / r;
		float vDirNormalizedY = v3Y / r;


		::Rectangle(hdc,
			vDirNormalizedX*100.0f - 5,
			vDirNormalizedY*100.0f - 5,
			vDirNormalizedX*100.0f + 5,
			vDirNormalizedY*100.0f + 5);
		::MoveToEx(hdc, 0, 0, NULL);
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, vDirNormalizedX * 100.0f, vDirNormalizedY * 100.0f);
		wsprintf(str, L"Normalized");
		::TextOut(hdc, vDirNormalizedX * 100.0f, vDirNormalizedY * 100.0f, str, lstrlen(str));

		/*float vPlayerX = player.getX();
		float vPlayerY = player.getY();
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, vPlayerX, vPlayerY);

		float vTargetX = target.getX();
		float vTargetY = target.getY();
		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, vTargetX, vTargetY);*/


		EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
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
