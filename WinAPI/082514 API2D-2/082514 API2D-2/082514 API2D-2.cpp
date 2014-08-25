// 082514 API2D-2.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

/*
	사각형
	1. 처음 위치 상단 가운데 대충
	2. 지혼자, 부드럽게 오른쪽으로 이동하다가, 끝이 닿으면 방향을 바꿔서 반대로 (왔다리 갔다리)

	원은 플레이어가 움직이고
*/

#include "stdafx.h"
#include "082514 API2D-2.h"

#define MAX_LOADSTRING 100
#define TIMER_ID 5
#define TIMER_ID2 4

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.
int mX, mY;
//static RECT _circle;
POINT _circle;

// 너무 어렵게 생각했다 ㅠㅠ
static bool isRightKeyDown = false,
isLeftKeyDown = false,
isUpKeyDown = false,
isDownKeyDown = false;


// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void Update(float delta);
void Render(HDC hdc);

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
	LoadString(hInstance, IDC_MY082514API2D2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY082514API2D2));

	// 기본 메시지 루프입니다.
	// 메시지루프를 상용화에선 손을 봐서 계속 돌아가게 만든다.
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY082514API2D2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY082514API2D2);
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

	/*
		1. 마우스 클릭한 지점으로부터 가로로 300pixel
		길이의 라인을 그려라.
		2. 윈도우를 최소화 한후 복귀해도, 라인이 유지되어야함
	*/
	/*
		실습
		1. 키보드 커서(화살표) 방향대로
		원을 5pixel씩 이동시킨다
		WM_KEYDWON, w Param = VK_RIGHT,
		Ellipse() 함수
		2. 부드럽게~
	*/

	/* 
		고정적으로 메시지를 발생시킬수 있으면,
		갭을 고칠수 있다. -> setTimer를 이용한다.
	*/

	switch (message)
	{		
	case WM_CREATE:
		// handler, IDEVENT, 간격(1000 = 1초) 일정이하면 바꿔도 의미가 없다,
		// callback 함수를 받을래! 하면 함수 포인터로 받을수 있다. 타이머 발생시 콜백함수 실행
		::SetTimer(hWnd, TIMER_ID, 50, NULL); // timer라는 msg를 발생시키는 발생기이다.
		_circle = { 100, 100 };
		break;

	case WM_TIMER:
		if (wParam == TIMER_ID)
		{
			Update(50 / 1000.0f);
		}
		::InvalidateRect(hWnd, NULL, true);
		break;

	case WM_KEYDOWN:
		switch (wParam){
		case VK_RIGHT:
			isRightKeyDown = true;
			break;
		case VK_LEFT:
			isLeftKeyDown = true;
			break;
		case VK_UP:
			isUpKeyDown = true;
			break;
		case VK_DOWN:
			isDownKeyDown = true;
			break;
		}
		::InvalidateRect(hWnd, NULL, true);		
		break;	
	
	case WM_KEYUP:
		switch (wParam){
		case VK_RIGHT:
			isRightKeyDown = false;
			break;
		case VK_LEFT:
			isLeftKeyDown = false;
			break;
		case VK_UP:
			isUpKeyDown = false;
			break;
		case VK_DOWN:
			isDownKeyDown = false;
			break;
		}

		break;

	case WM_LBUTTONDOWN:
		mX = LOWORD(lParam);
		mY = HIWORD(lParam);

		// 무효화를 하면 일어나면 동작
		// 두번쩨 Rect가 무효화 하는 범위
		// 모르거나 전체 영역을 다시 그리고 싶다고 할때 NULL을 넣는다.
		// 게임의 경우 부분만 다시 그리는 게 거의 불가능하다
		// 무효화 할 경우 WM_PAINT메세지가 발생한다.
		// 세번째 인자같은 경우에는 지우고 발생할것인가 안지우고 발생할것인가. (쟌상)
		::InvalidateRect(hWnd, NULL, true);		
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
		hdc = BeginPaint(hWnd, &ps);
		hdc = ::GetDC(hWnd);
		Render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_DESTROY:
		//::KillTimer(hWnd, TIMER_ID);
		::KillTimer(hWnd, TIMER_ID);
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

// 핵심 프레임웤
void Update(float delta){	
	if (isRightKeyDown){
		_circle.x += 5;
	}
	if (isLeftKeyDown){
		_circle.x -= 5;
	}
	if (isUpKeyDown){
		_circle.y -= 5;
	}
	if (isDownKeyDown){
		_circle.y += 5;
	}	
}

void Render(HDC hdc){	
	::MoveToEx(hdc, mX, mY, NULL);
	// 첫 시작 설정점에서 부터 계속 이어서 그리게 된다.		
	::LineTo(hdc, mX + 300, mY);
	::Ellipse(hdc, _circle.x - 25, _circle.y - 25, _circle.x + 25, _circle.y + 25);
}