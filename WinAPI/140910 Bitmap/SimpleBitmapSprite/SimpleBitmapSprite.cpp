// SimpleBitmapSprite.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SimpleBitmapSprite.h"
#include "cMain.h"

#define MAX_LOADSTRING 100
#define TIMER_ID 1
#define TIMER_INTERVAL 50

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
cMain* g_pMain;
HWND g_hWnd;

//HBITMAP hbit;	// 캐릭터
//HBITMAP bg;		// 배경
//HBITMAP hMonster;
//RECT Sprites[16] = { 
//		{ 180 * 1, 180 * 0, 140, 180 }, // 그림자
//		{ 180 * 2, 180 * 0, 140, 180 },
//		{ 180 * 3, 180 * 0, 140, 180 },
//		{ 180 * 4, 180 * 0, 140, 180 }, // 여기가지 대기
//		{ 180 * 0, 180 * 1, 140, 180 },
//		{ 180 * 1, 180 * 1, 140, 180 },
//		{ 180 * 2, 180 * 1, 140, 180 },
//		{ 180 * 3, 180 * 1, 140, 180 },
//		{ 180 * 4, 180 * 1, 140, 180 },
//		{ 180 * 5, 180 * 1, 140, 180 }, // 여기까지 오른쪽이동
//		{ 180 * 0, 180 * 2, 140, 180 },
//		{ 180 * 1 - 20, 180 * 2, 140, 180 }, // 칼 짤려서 수정
//		{ 180 * 2 - 20, 180 * 2, 140, 180 },
//		{ 180 * 3 - 20, 180 * 2, 140, 180 },
//		{ 180 * 4 - 20, 180 * 2, 140, 180 },
//		{ 180 * 5 - 20, 180 * 2, 140, 180 }
//		 };
//RECT PoringSprites[4] = {
//		{ 60 * 0, 60 * 0, 60, 60 },
//		{ 60 * 1, 60 * 0, 60, 60 },
//		{ 60 * 2, 60 * 0, 60, 60 },
//		{ 60 * 3, 60 * 0, 60, 60 }
//};
//RECT BackGround = { 0, 0, 1028, 768 };
//RECT rct;
//
//int aniFrame = 0;
//int monFrame = 0;
//
//bool right = false;
//bool left = false;
//int x = 0, y = 560; // 캐릭터 위치
//float CumulativeTime = 0.0f;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

//void DrawBitmap(HDC hdc, int destX, int destY, int destWidth, int destHeight, HBITMAP hBit,
//	int srcX, int srcY, int srcWidth, int srcHeight, );
//RGB());

//void Update(float delta);
//void UpdateMonster(float delta);
//
//void OnKeyDown(WPARAM wParam);
//void OnkeyUp(WPARAM wParam);
//void Render(HDC hdc);
//void DrawBitmap(
//	HDC hdc,
//	HDC FrontMemDC,
//	int destX, int destY, int destWidth, int destHeight,
//	HBITMAP hBit,
//	int srcX, int srcY, int srcWidth, int srcHeight,
//	DWORD colorKey,
//	bool bTransparent);

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
	LoadString(hInstance, IDC_SIMPLEBITMAPSPRITE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	g_pMain = new cMain;
	g_pMain->OnCreate(hInstance, g_hWnd);

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SIMPLEBITMAPSPRITE));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	if (g_pMain != NULL){
		delete g_pMain;
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLEBITMAPSPRITE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SIMPLEBITMAPSPRITE);
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
	static RECT winRect;

	switch (message)
	{
	case WM_CREATE:
		::SetTimer(hWnd, TIMER_ID, TIMER_INTERVAL, NULL);
		::GetClientRect(hWnd, &winRect);
		/*hbit = (HBITMAP)LoadImage(
			hInst,
			L"images/swordsman.bmp",
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);
		bg = (HBITMAP)LoadImage(
			hInst,
			L"images/background.bmp",
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);
		hMonster = (HBITMAP)LoadImage(
			hInst,
			L"images/Poring.bmp",
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);*/
		break;
	case WM_TIMER:
		//Update(TIMER_INTERVAL / 1000.0f);
		//UpdateMonster(TIMER_INTERVAL / 1000.0f);
		g_pMain->update(TIMER_INTERVAL / 1000.0f);
		::InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		g_pMain->OnKeyDown(wParam);
		//OnKeyDown(wParam);
		break;
	case WM_KEYUP:
		g_pMain->OnKeyUp(wParam);
		//OnkeyUp(wParam);
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
		if (g_pMain == nullptr) break;

		hdc = BeginPaint(hWnd, &ps);

		HDC FrontMemDC = ::CreateCompatibleDC(hdc);
		HBITMAP hCanvasBit = ::CreateCompatibleBitmap(hdc, winRect.right, winRect.bottom);
		HBITMAP hOldCanvas = (HBITMAP)::SelectObject(FrontMemDC, hCanvasBit);

		g_pMain->render(hdc, FrontMemDC);

		BitBlt(hdc, 0, 0, winRect.right, winRect.bottom, FrontMemDC, 0, 0, SRCCOPY);

		::SelectObject(FrontMemDC, hOldCanvas);
		::DeleteObject(hCanvasBit);
		::DeleteObject(FrontMemDC);
		//DrawBitmap(
		//hdc,
		//destX, destY, destWidth, destHeight
		//hBit,
		//srcX, srcY, srcWidth,srcHeight,
		//RGB());
		//GetClientRect(hWnd, &rect);
		//width = rect.right;
		//height = rect.bottom;
		//backbuffDC = CreateCompatibleDC(hdc);
		//backbuffer = CreateCompatibleBitmap(hdc, width, height);
		//savedDC = SaveDC(backbuffDC);
		//SelectObject(backbuffDC, backbuffer);
		//hBrush = CreateSolidBrush(RGB(255, 255, 255));
		//FillRect(backbuffDC, &rect, hBrush);
		//DeleteObject(hBrush);
		//
		//g_world->render(backbuffDC);
		//Render(hdc);
		//
		//BitBlt(hdc, 0, 0, width, height, backbuffDC, 0, 0, SRCCOPY);
		//RestoreDC(backbuffDC, savedDC);
		////Render(hdc);
		//DeleteObject(backbuffer);
		//DeleteDC(backbuffDC);

		// TODO: 여기에 그리기 코드를 추가합니다.

		EndPaint(hWnd, &ps);
	}
		break;

	case WM_DESTROY:
		::KillTimer(hWnd, TIMER_ID);
		g_pMain->OnDestroy();
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


//void Update(float delta)
//{
//	CumulativeTime += delta;
//	if (rct.right < x) x = 0;
//	if (right)
//	{
//		x += 10;
//		if (aniFrame < 4)
//			aniFrame = 4;
//		if (CumulativeTime > 0.2f)
//		{
//			aniFrame++;
//			CumulativeTime = 0;
//		}
//		if (aniFrame > 9)
//			aniFrame = 4;
//	}
//	else if (left){
//		x -= 10;
//		if (aniFrame < 11)
//			aniFrame = 11;
//		if (CumulativeTime > 0.2f)
//		{
//			aniFrame++;
//			CumulativeTime = 0;
//		}
//		if (aniFrame > 15)
//			aniFrame = 11;
//	}
//	else
//	{
//		if (aniFrame > 3)
//			aniFrame = 0;
//		if (CumulativeTime > 0.2f)
//		{
//			aniFrame++;
//			CumulativeTime = 0;
//		}
//		if (aniFrame > 3)
//			aniFrame = 0;
//	}
//}

//void Render(HDC hdc)
//{
//	HDC frontMemDC = ::CreateCompatibleDC(hdc);
//	HBITMAP hCanvasBit = ::CreateCompatibleBitmap(hdc, 1024, 768);
//	HBITMAP holdCanvas = (HBITMAP)::SelectObject(frontMemDC, hCanvasBit);
//
//	DrawBitmap(
//		hdc, frontMemDC,
//		0, 0, 1024, 768,
//		bg,
//		0, 50, 1024, 768,
//		0, false);
//
//
//	DrawBitmap(
//		hdc, frontMemDC,
//		200, 640, 
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom,
//		hMonster,
//		PoringSprites[monFrame].left, 
//		PoringSprites[monFrame].top, 
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom, 
//		RGB(0, 128, 255), true);
//
//	DrawBitmap(
//		hdc, frontMemDC,
//		300, 640,
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom,
//		hMonster,
//		PoringSprites[monFrame].left,
//		PoringSprites[monFrame].top,
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom,
//		RGB(0, 128, 255), true);
//
//	DrawBitmap(
//		hdc, frontMemDC,
//		600, 640,
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom,
//		hMonster,
//		PoringSprites[monFrame].left,
//		PoringSprites[monFrame].top,
//		PoringSprites[monFrame].right,
//		PoringSprites[monFrame].bottom,
//		RGB(0, 128, 255), true);
//
//
//	DrawBitmap(
//		hdc, frontMemDC,
//		x, y,
//		180,
//		180,
//		hbit,
//		0,
//		0,
//		180,
//		180,
//		RGB(50, 150, 200), true);
//	DrawBitmap(
//		hdc, frontMemDC,
//		x, y,
//		Sprites[aniFrame].right,
//		Sprites[aniFrame].bottom,
//		hbit,
//		Sprites[aniFrame].left,
//		Sprites[aniFrame].top,
//		Sprites[aniFrame].right,
//		Sprites[aniFrame].bottom,
//		RGB(50, 150, 200), true);
//
//	::BitBlt(hdc, 0, 0, 1028, 768, frontMemDC, 0, 0, SRCCOPY);
//
//	::SelectObject(frontMemDC, holdCanvas);
//	::DeleteObject(hCanvasBit);
//
//	::DeleteObject(frontMemDC);
//
//	//DrawBitmap(hdc,
//	//destX, destY, destWidth, destHeight
//	//srcX, srcY, srcWidth,srcHeight,
//	//RGB());
//	//HBITMAP oldBit = (HBITMAP)::SelectObject(MemDC, bg);
//	//::BitBlt(hdc, 0, 0, 1024, 768, MemDC, 0, 50, SRCCOPY);
//	////::SelectObject(MemDC, oldBit);
//	////::DeleteDC(MemDC);
//	////MemDC = ::CreateCompatibleDC(hdc);	
//	//oldBit = (HBITMAP)::SelectObject(MemDC, hbit);
//
//	////::Rectangle(hdc, 0, 580, 1024, 768);
//	//// shadow
//	//::TransparentBlt(hdc, x, y, 180, 180, MemDC, 0, 0, 180, 180, RGB(50, 150, 200));
//	//// moving
//
//	////::BitBlt(hdc, x, y, Sprites[aniFrame].right, Sprites[aniFrame].bottom, MemDC, 0,0, SRCCOPY);
//	//
//	//// 좌우 반전시켜서 반대방향움직이는 것도 추가하려다가 포기...
//	//::TransparentBlt(hdc, x, y,
//	//	Sprites[aniFrame].right,
//	//	Sprites[aniFrame].bottom,
//	//	MemDC,
//	//	Sprites[aniFrame].left,
//	//	Sprites[aniFrame].top,
//	//	Sprites[aniFrame].right,
//	//	Sprites[aniFrame].bottom,
//	//	RGB(50, 150, 200));
//
//	//::SelectObject(MemDC, oldBit);
//	//::DeleteDC(MemDC);
//}
//
//void OnKeyDown(WPARAM wParam)
//{
//	if (wParam == VK_RIGHT){ right = true; }
//	if (wParam == VK_LEFT){ left = true; }
//}
//void OnkeyUp(WPARAM wParam)
//{
//	if (wParam == VK_RIGHT){ right = false; }
//	if (wParam == VK_LEFT){ left = false; }
//}
//
//void UpdateMonster(float delta){
//	CumulativeTime += delta;
//	if (monFrame > 3) monFrame = 0;
//	if (CumulativeTime > 0.2f){
//		monFrame++;
//		CumulativeTime = 0;
//	}
//	if (monFrame > 3)
//		monFrame = 0;
//}
//
//void DrawBitmap(
//	HDC hdc,
//	HDC FrontMemDC,
//	int destX, int destY, int destWidth, int destHeight,
//	HBITMAP hBit,
//	int srcX, int srcY, int srcWidth, int srcHeight,
//	DWORD colorKey,
//	bool bTransparent){
//	//2. 호환되는 메모리 DC 생성
//	HDC BackMemDC = ::CreateCompatibleDC(hdc);
//	//--------- 배경 ------------------
//	HBITMAP oldBit = (HBITMAP)::SelectObject(BackMemDC, hBit);
//	//4. BitBlt ( 메모리 DC => 화면DC )	
//	if (bTransparent)
//	{
//		::TransparentBlt(FrontMemDC,
//			destX, destY, destWidth, destHeight, //화면 DC 영역
//			BackMemDC,
//			srcX,
//			srcY,
//			srcWidth,
//			srcHeight, //소스 Bitmap 영역
//			colorKey);
//	}
//	else
//	{
//		::StretchBlt(FrontMemDC,
//			destX, destY, destWidth, destHeight, //화면 DC 영역
//			BackMemDC,
//			srcX,
//			srcY,
//			srcWidth,
//			srcHeight, //소스 Bitmap 영역
//			SRCCOPY);
//	}
//
//	//5. 메모리정리( 비트맵핸들 돌려놓기, 메모리DC 해제)
//	::SelectObject(BackMemDC, oldBit);
//	::DeleteDC(BackMemDC);
//}