/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	특별과제:

	[1]
	-윈도우 사이즈(클라이언트 영역)에 맞게 윈도우 전체를 채우는 가로18 칸 세로 18칸의 바둑판을 그려라
	-바둑판의 상하좌우에 여백이 존재해야 하고, 그 여백은 각각 바둑판 1칸의 절반에
	해당한다.
	(예를 들어 바둑판 한칸의 크기가 가로 10, 세로 12이라면,
	상단여백과 하단여백은 각각 세로로 6의 크기,
	좌우여백은 각각 5의 크기를 갖는다.
	- 윈도우 사이즈가 변경될때 마다 같은 방식으로 그려야 한다.

	[2]
	- 클릭하면 클릭한 칸 안쪽을 꽉 채우는 원을 그린다.

	[3]
	- 원을 클릭하고 드래그 하면 마우스를 따라 이동하다가 마우스을 떼면
	해당 칸에 위치한다.


	* [3]번까지 한사람 박수와 함께 음료수 증정!
	* 스크린샷 없으면 무효~ 스크린샷 제출 필수!
*/

#include "stdafx.h"
#include "RefactMiniWorld.h"
#include "World.h"
#include "WorldRenderer.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
static World world = World(18,18);
static WorldRenderer worldrenderer;
POINT from, to;	// Todo : World class나 Object Structure 에 넣을것

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

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_REFACTMINIWORLD, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REFACTMINIWORLD));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REFACTMINIWORLD));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_REFACTMINIWORLD);
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
	int mx, my;
	RECT winRect;
	RECT draw;

	::GetClientRect(hWnd, &winRect);	
	world.updateWorld(winRect);
	worldrenderer = WorldRenderer(hWnd, world);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
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

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);		

		from.x = mx;
		from.y = my;

		worldrenderer.moveAnimation(mx, my); // 클릭 즉시 보이기 위한 애니메이션 추가
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_MOUSEMOVE:
		// 부드럽게 보이기 위해서는 잔상처리를 그대로 하는 게 더 부드럽게 보임
		// 잔상처리를 안할경우 화면이 번쩍거리는 현상이 보이게 됨
		mx = LOWORD(lParam); // x coordinate
		my = HIWORD(lParam); // y coordinate
		/*
		*/
		switch (wParam){
		case MK_LBUTTON:
			//	if (!world.inList(world.getTileCoordinate(mx, my).x, 
			//		world.getTileCoordinate(mx, my).y)){
			//		world.addObject(mx, my);
			worldrenderer.moveAnimation(mx, my);
			break;
		}
		/*
		*/
		break;

	case WM_LBUTTONUP:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (!world.inList(world.getTileCoordinate(mx, my).x,
			world.getTileCoordinate(mx, my).y)){
			if (from.x != 0 && from.y != 0){
				to.x = mx;
				to.y = my;
				world.moveObject(from.x, from.y, to.x, to.y);
				from = {};
				to = {};
			}
			else {
				world.addObject(mx, my);
			}
		}
		else {			
			//
		}

		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_RBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (world.inList(world.getTileCoordinate(mx, my).x,
			world.getTileCoordinate(mx, my).y)){
			world.deleteObject(mx, my);
		}

		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		worldrenderer.update();
		EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
		worldrenderer.update();
		break;

	case WM_DESTROY:
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
