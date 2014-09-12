// API2D-Bitmap.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "API2D-Bitmap.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.
HBITMAP hBit;
HBITMAP hBitBack;
// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
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
	//2. ȣȯ�Ǵ� �޸� DC ����
	HDC BackMemDC = ::CreateCompatibleDC(hdc);
	//--------- ��� ------------------
	HBITMAP oldBit = (HBITMAP)::SelectObject(BackMemDC, hBit);
	//4. BitBlt ( �޸� DC => ȭ��DC )	
	if (bTransparent)
	{
		::TransparentBlt(frontMemDC,
			destX, destY, destWidth, destHeight, //ȭ�� DC ����
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //�ҽ� Bitmap ����
			colorKey);
	}
	else
	{
		::StretchBlt(frontMemDC,
			destX, destY, destWidth, destHeight, //ȭ�� DC ����
			BackMemDC,
			srcX,
			srcY,
			srcWidth,
			srcHeight, //�ҽ� Bitmap ����
			SRCCOPY);
	}

	//5. �޸�����( ��Ʈ���ڵ� ��������, �޸�DC ����)
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

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_API2DBITMAP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API2DBITMAP));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API2DBITMAP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_API2DBITMAP);
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
		//1. ȭ�� DC ���
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.

		//2. ȣȯ�Ǵ� �޸� DC (BackDC ��Ʈ���� ��Ƶδ� ����)
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
		�ǽ� :
		��Ʈ�� �ε带 �ݺ����� ����,
		�ε�� ��Ʈ�� �ڵ鸸 �Ἥ  ĳ���Ͱ� ��ǥ�� �ٸ�����
		3�� �Ѹ���.		
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

/*

*/