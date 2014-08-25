/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Ư������:

	[1]
	-������ ������(Ŭ���̾�Ʈ ����)�� �°� ������ ��ü�� ä��� ����18 ĭ ���� 18ĭ�� �ٵ����� �׷���
	-�ٵ����� �����¿쿡 ������ �����ؾ� �ϰ�, �� ������ ���� �ٵ��� 1ĭ�� ���ݿ�
	�ش��Ѵ�.
	(���� ��� �ٵ��� ��ĭ�� ũ�Ⱑ ���� 10, ���� 12�̶��,
	��ܿ���� �ϴܿ����� ���� ���η� 6�� ũ��,
	�¿쿩���� ���� 5�� ũ�⸦ ���´�.
	- ������ ����� ����ɶ� ���� ���� ������� �׷��� �Ѵ�.

	[2]
	- Ŭ���ϸ� Ŭ���� ĭ ������ �� ä��� ���� �׸���.

	[3]
	- ���� Ŭ���ϰ� �巡�� �ϸ� ���콺�� ���� �̵��ϴٰ� ���콺�� ����
	�ش� ĭ�� ��ġ�Ѵ�.


	* [3]������ �ѻ�� �ڼ��� �Բ� ����� ����!
	* ��ũ���� ������ ��ȿ~ ��ũ���� ���� �ʼ�!
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
POINT from, to;	// Todo : World class�� Object Structure �� ������

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

		worldrenderer.moveAnimation(mx, my); // Ŭ�� ��� ���̱� ���� �ִϸ��̼� �߰�
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_MOUSEMOVE:
		// �ε巴�� ���̱� ���ؼ��� �ܻ�ó���� �״�� �ϴ� �� �� �ε巴�� ����
		// �ܻ�ó���� ���Ұ�� ȭ���� ��½�Ÿ��� ������ ���̰� ��
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
