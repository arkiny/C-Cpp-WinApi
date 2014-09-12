// API2D-Bitmap.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "API2D-Bitmap.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.
HBITMAP hBit;
HBITMAP hBitBack;
// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


void DrawBitmap(
	HDC hdc, HDC frontMemDC,			
	int destX, int destY, int destWidth, int destHeight,
	HBITMAP hBit,	
	int srcX,int srcY,int srcWidth,int srcHeight,
	DWORD colorKey,
	bool bTransparent)
{
	//2. 호환되는 메모리 DC 생성
	HDC BackMemDC = ::CreateCompatibleDC(hdc);
	//--------- 배경 ------------------
	HBITMAP oldBit = (HBITMAP)::SelectObject(BackMemDC, hBit);
	//4. BitBlt ( 메모리 DC => 화면DC )	
	if (bTransparent)
	{
		::TransparentBlt(frontMemDC,
			destX, destY, destWidth, destHeight, //화면 DC 영역
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //소스 Bitmap 영역
			colorKey);
	}
	else
	{
		::StretchBlt(frontMemDC,
			destX, destY, destWidth, destHeight, //화면 DC 영역
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //소스 Bitmap 영역
			SRCCOPY);
	}

	//5. 메모리정리( 비트맵핸들 돌려놓기, 메모리DC 해제)
	::SelectObject(BackMemDC, oldBit);
	::DeleteDC(BackMemDC);
}

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
	LoadString(hInstance, IDC_API2DBITMAP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API2DBITMAP));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API2DBITMAP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_API2DBITMAP);
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
	static int x = 0, y = 100;
	RECT sprites[2] = { 
		{ 0, 0, 71, 112 },
		{ 71, 0, 71+71, 112 } };
	static int aniFrame = 0;
	static bool bRightKey = false;
	static float accumTime = 0.0f;
	switch (message)
	{	
	case WM_CREATE:
		
		::SetTimer(hWnd, 1, 80, NULL);

		hBitBack = (HBITMAP)LoadImage(
			hInst,
			L"Image/girl.bmp",
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);
		hBit = (HBITMAP)LoadImage(
			hInst,
			L"Image/sprites.bmp",
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);

		break;
	case WM_TIMER:
	{
		if (bRightKey)
		{
			x += 10;			
		}

		float delta = 80 / 1000.0f;
		accumTime += delta;
		if (accumTime > 0.3f)
		{
			aniFrame++;
			if (aniFrame > 1)
				aniFrame = 0;

			accumTime = 0.0f;
		}		
		::InvalidateRect(hWnd, NULL, TRUE);
	}
		break;
	case WM_KEYUP:
		if (wParam == VK_RIGHT)
		{
			bRightKey = false;

		}
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RIGHT)
		{
			bRightKey = true;
			
		}

		
		break;
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
		//1. 화면 DC 얻기
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 그리기 코드를 추가합니다.

		//2. 호환되는 메모리 DC (BackDC 비트맵을 모아두는 역할)
		HDC frontMemDC = ::CreateCompatibleDC(hdc);
		HBITMAP hCanvasBit = ::CreateCompatibleBitmap(hdc, 1024, 768);
		HBITMAP holdCanvas = (HBITMAP)::SelectObject(frontMemDC, hCanvasBit);

		DrawBitmap(
			hdc, frontMemDC,
			0, 0, 500, 400,
			hBitBack,
			0, 0, 500, 400,
			0, false);

		DrawBitmap(
			hdc, frontMemDC,
			x, y, 72, 113,
			hBit,
			sprites[aniFrame].left, sprites[aniFrame].top, 72, 113,
			RGB(104, 144,168), true);

		DrawBitmap(
			hdc, frontMemDC,
			100, 100, 72, 113,
			hBit,
			sprites[aniFrame].left, sprites[aniFrame].top, 72, 113,
			RGB(104, 144, 168), true);

		DrawBitmap(
			hdc, frontMemDC,
			200,200, 72, 113,
			hBit,
			sprites[aniFrame].left, sprites[aniFrame].top, 72, 113,
			RGB(104, 144, 168), true);

		
		//------------------------------------------------
		/*
		실습 :
		비트맵 로드를 반복하지 말고,
		로드된 비트맵 핸들만 써서  캐릭터가 좌표상에 다른곳에
		3번 뿌리기.		
		*/
		::BitBlt(hdc, 0, 0, 1027, 768, frontMemDC, 0, 0, SRCCOPY);

		::SelectObject(frontMemDC, holdCanvas);
		::DeleteObject(hCanvasBit);

		::DeleteObject(frontMemDC);			

		EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		::DeleteObject(hBit);
		::DeleteObject(hBitBack);
		::KillTimer(hWnd, 1);
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

/*

*/