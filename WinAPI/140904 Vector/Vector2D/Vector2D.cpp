// Vector2D.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//


#include "stdafx.h"
#include "Vector2D.h"
#include <cmath>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.

POINT player = { 100, 120 };
POINT target = { 500, 250 };

typedef struct Vector2D{
	float x;
	float y;
}VECTOR2D;

/*
	player는 사각형
	target은 원으로 그리시오
*/

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
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

 	// TODO: 여기에 코드를 입력합니다.
	MSG msg;
	HACCEL hAccelTable;

	// 전역 문자열을 초기화합니다.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_VECTOR2D, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VECTOR2D));

	// 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND	- 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT	- 주 창을 그립니다.
//  WM_DESTROY	- 종료 메시지를 게시하고 반환합니다.
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
		// 메뉴 선택을 구문 분석합니다.
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
		// TODO: 여기에 그리기 코드를 추가합니다.
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

		//player 위치 정보를 가지고 벡터를 만든다.
		
		
		float v1X = player.x;
		float v1Y = player.y;
		// 벡터를 그릴땐 시작점을 원점으로 잡는다.
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

		// 단위 벡터를 만드는 방법
		// a가로, b세로, 대각 r, 
		// r을 1로 만드는 방법이?! 
		// 다 r로 나눠버리면 1....

		// vDir의 r(벡터의 length)
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

// 정보 대화 상자의 메시지 처리기입니다.
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
