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
#include "003-2 TileMapDrawerFinal.h"
#include "ScreenHandler.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
bool playerAct = false;							// is player activated?
RECT winRect = { 0, };							// windowRectangle
PLAYER player;									// player object

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
	LoadString(hInstance, IDC_MY0032TILEMAPDRAWERFINAL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0032TILEMAPDRAWERFINAL));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0032TILEMAPDRAWERFINAL));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY0032TILEMAPDRAWERFINAL);
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
	int mX, mY;	// mouse cursor postion
	PAINTSTRUCT ps;
	HDC hdc;

	::GetClientRect(hWnd, &winRect); // windowRectangle check
	WorldRenderer worldHandle(hWnd, hdc, winRect, player); // world handler class

	/*
	*/
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
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

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		worldHandle.update(playerAct);
		EndPaint(hWnd, &ps);
		break;
	/*
		여기부터 추가
	*/
	case WM_MOUSEMOVE:
		// 부드럽게 보이기 위해서는 잔상처리를 그대로 하는 게 더 부드럽게 보임
		// 잔상처리를 안할경우 화면이 번쩍거리는 현상이 보이게 됨
		mX = LOWORD(lParam); // x coordinate
		mY = HIWORD(lParam); // y coordinate
		/*
		*/
		switch (wParam){
		case MK_LBUTTON:
			// moveFlag는 플레이어를 클릭했는지 확인하여 돌려준다.
			if (player.moveFlag == true){
				player.pos = worldHandle.getPlayerCoordinate(mX, mY);
				player.curpos = { mX, mY };

				if (worldHandle.isCurInside(player)){
					player.obj = worldHandle.getTileCoordnate(mX, mY);
					hdc = ::GetDC(hWnd);
					::Ellipse(hdc, player.obj.left, player.obj.top, player.obj.right, player.obj.bottom);
					::ReleaseDC(hWnd, hdc);
					playerAct = true;
				}
				else if (playerAct){
					hdc = ::GetDC(hWnd);
					::Ellipse(hdc, player.obj.left, player.obj.top, player.obj.right, player.obj.bottom);
					::ReleaseDC(hWnd, hdc);
				}
				else{
					//
				}
			}
			break;
		}
		/*
		*/
		break;

	case WM_LBUTTONUP:
		// 이동후 잔상삭제
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_LBUTTONDOWN:
		mX = LOWORD(lParam); // x coordinate
		mY = HIWORD(lParam); // y coordinate

		// 클릭시 현재 커서가 플레이어 오프젝트를 눌렀을시에
		// 움직이기 위한 플래그를 세운다(WM_MOUSEMOVE)와 연계
		if (player.pos.x == worldHandle.getPlayerCoordinate(mX, mY).x &&
			player.pos.y == worldHandle.getPlayerCoordinate(mX, mY).y){
			player.moveFlag = true;
		}
		else { // 아니면 그냥 단일형 이벤트 실행
			player.moveFlag = false;
		}
		//

		player.pos = worldHandle.getPlayerCoordinate(mX, mY);
		player.curpos = { mX, mY };

		if (worldHandle.isCurInside(player)){
			player.obj = worldHandle.getTileCoordnate(mX, mY);
			InvalidateRect(hWnd, NULL, true);
			playerAct = true;
		}
		else if (playerAct){
			InvalidateRect(hWnd, NULL, true);
		}
		else{
			//playerAct = false;
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
