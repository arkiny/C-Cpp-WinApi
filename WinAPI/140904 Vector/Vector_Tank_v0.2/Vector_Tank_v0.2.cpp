// Vector_Tank_v0.2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Vector_Tank_v0.2.h"
#include "World.h"

#define MAX_LOADSTRING 100

#define PLAYER_MOVE 10001

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
World* g_world;

// Forward declarations of functions included in this code module:
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

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	//
	g_world = new World();
	//

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_VECTOR_TANK_V02, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VECTOR_TANK_V02));

	// Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VECTOR_TANK_V02));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_VECTOR_TANK_V02);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle,
	   WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
	   CW_USEDEFAULT, 0, 1028, 768, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT temp;
	BOOL gameOver = false, happyEnding = false;

	//
	RECT rect;
	HDC backbuffDC;
	HBITMAP backbuffer;
	HBRUSH hBrush;
	int width;
	int height;
	int savedDC;
	//

	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &temp);
		g_world->updateMap(temp);
		::SetTimer(hWnd, PLAYER_MOVE, 50, NULL);
		break;
	case WM_TIMER:{
		if (wParam = PLAYER_MOVE){
			g_world->update(50.0f / 1000.0f);
			gameOver = g_world->retGameover();
			happyEnding = g_world->happyEnding();
		}
		InvalidateRect(hWnd, NULL, true);
		if (gameOver){
			::KillTimer(hWnd, PLAYER_MOVE);
			int msg = ::MessageBox(hWnd, L"게임오버, 종료하시겠습니까?", L"EndGame", MB_YESNO);
			switch (msg)
			{
			case IDYES:				
				PostQuitMessage(0);
				break;
			case IDNO:
				g_world->continueGame();
				::SetTimer(hWnd, PLAYER_MOVE, 50, NULL);
				break;
			default:
				break;
			}
		}
		else if (happyEnding){
			::KillTimer(hWnd, PLAYER_MOVE);
			int msg = ::MessageBox(hWnd, L"승리! 계속하시겠습니까?", L"Victory", MB_YESNO);
			switch (msg)
			{
			case IDYES:
				g_world->continueGame();
				::SetTimer(hWnd, PLAYER_MOVE, 50, NULL);
				break;
			case IDNO:
				PostQuitMessage(0);				
				break;
			default:
				break;
			}
		}
		break;
	}
	case WM_LBUTTONDOWN:
		g_world->onKeyDown(LBUTTON);
		break;

	case WM_LBUTTONUP:
		g_world->onKeyUp(LBUTTON);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
		case 0x44:
			g_world->onKeyDown(RIGHT);
			break;
		case VK_LEFT:
		case 0x41:
			g_world->onKeyDown(LEFT);
			break;
		case VK_UP:
		case 0x57:
			g_world->onKeyDown(UP);
			break;
		case VK_DOWN:
		case 0x53:
			g_world->onKeyDown(DOWN);
			break;
		case VK_SPACE:
			g_world->onKeyDown(SPACE);
			break;
		default:
			break;
		}
	break;

	case WM_KEYUP:
		switch (wParam)
		{
		case VK_RIGHT:
		case 0x44:
			g_world->onKeyUp(RIGHT);
			break;
		case VK_LEFT:
		case 0x41:
			g_world->onKeyUp(LEFT);
			break;
		case VK_UP:
		case 0x57:
			g_world->onKeyUp(UP);
			break;
		case VK_DOWN:
		case 0x53:
			g_world->onKeyUp(DOWN);
			break;
		case VK_SPACE:
			g_world->onKeyUp(SPACE);
			break;
		default:
			break;
		}
	break;

	case WM_MOUSEMOVE:
	{
		int mouseX = LOWORD(lParam);
		int mouseY = HIWORD(lParam);
		g_world->onMouseMove(mouseX, mouseY);
	}
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
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

	case WM_ERASEBKGND:
		return 1;
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		//// TODO: 여기에 그리기 코드를 추가합니다.

		GetClientRect(hWnd, &rect);
		width = rect.right;
		height = rect.bottom;
		backbuffDC = CreateCompatibleDC(hdc);
		backbuffer = CreateCompatibleBitmap(hdc, width, height);
		savedDC = SaveDC(backbuffDC);
		SelectObject(backbuffDC, backbuffer);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		FillRect(backbuffDC, &rect, hBrush);
		DeleteObject(hBrush);
		//
		g_world->render(backbuffDC);
		//worldrenderer.render(backbuffDC);
		//worldrenderer.render(hdc);
		//
		BitBlt(hdc, 0, 0, width, height, backbuffDC, 0, 0, SRCCOPY);
		RestoreDC(backbuffDC, savedDC);

		DeleteObject(backbuffer);
		DeleteDC(backbuffDC);
		
		EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		::KillTimer(hWnd, PLAYER_MOVE);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
