// Rotation.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Rotation.h"
#include <math.h>

#define MAX_LOADSTRING 100
#define PI 3.14159265359

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.
int degree = 30;
int bulletdegree = 30;
POINT tank = { 200, 200 };
POINT bullet;
BOOL shotfired = false;

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
	LoadString(hInstance, IDC_ROTATION, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROTATION));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROTATION));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_ROTATION);
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

	switch (message)
	{
	case WM_CREATE:
		::SetTimer(hWnd, 101, 50, NULL);
		break;

	case WM_TIMER:
		if (shotfired == true){
			float speed = 10.0f; 
			float radian = bulletdegree * (PI / 180);
			bullet = { bullet.x + cosf(radian) * speed, bullet.y + sinf(radian) * speed };
			InvalidateRect(hWnd, NULL, true);
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
	case WM_KEYDOWN:
		
		if( wParam == VK_LEFT)
			degree -= 10;
			
		if (wParam == VK_RIGHT)
			degree += 10;			

			
		if (wParam == VK_UP)
		{
			float radian = degree * (PI / 180);
			float speed = 10.0f;
			tank = { cosf(radian) * speed + tank.x, sinf(radian) * speed + tank.y };			
		}

		if (wParam == VK_DOWN)
		{
			float radian = degree * (PI / 180);
			float speed = 10.0f;
			tank = { tank.x - cosf(radian) * speed, tank.y - sinf(radian) * speed };
			break;
		}

		if (wParam == VK_SPACE){
			//
			shotfired = true;			
			bulletdegree = degree;
			bullet = { tank.x, tank.y };
			
			//
		}		

		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);		

		// 매프레임마다 계산 할 필요가 없다.
		// 만약 계산이 부담스러우면 미리 글로벌에 저장해놓고
		// 필요할때마다 호출하도록 한다.
		//POINT sin[360];
		//for (int i = 1; i <= 360; i++){
		//	float radian = degree * (PI / 180);
		//	sin[i].x = cosf(radian);
		//	sin[i].y = sinf(radian);
		//}

		float radian = degree * (PI / 180);
		float length = 50.0f;		
		float x = cosf(radian);// * length + tank.x;
		float y = sinf(radian);// * length + tank.y;
		x = x*length + tank.x;
		y = y*length + tank.y;

		/*::Rectangle(hdc, 0, 0, tank.x, 300);*/
		// tank
		::Rectangle(hdc, tank.x - 25, tank.y - 25, tank.x + 25, tank.y + 25);
		::Ellipse(hdc, tank.x - 22, tank.y - 22, tank.x + 22, tank.y + 22);
		::MoveToEx(hdc, tank.x, tank.y, NULL);
		::LineTo(hdc, x, y);

		::Ellipse(hdc, bullet.x - 3, bullet.y - 3, bullet.x + 3, bullet.y + 3);

		EndPaint(hWnd, &ps);
		break;
	}

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
