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
int size = 50;

// 너무 어렵게 생각했다 ㅠㅠ
bool isRightKeyDown = false,
isLeftKeyDown = false,
isUpKeyDown = false,
isDownKeyDown = false,
show_circle = true;
float time = 0;
float time2 = 0;


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
			Update(25 / 1000.0f);
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
// 반복되는건 update와 render 이 두개
// 이 정보들이 바뀌더라도 update와 render 두 개가 계속 실행이 되는 것
// 업데이트 부분에 들어갈때 delta가 들어가 있는 이유는?
// delta는 앞프레임과 현재 프레임과의 간격을 넣어주는 것
// 실무에서는 갱신된 타임을 읽어서 그 값의 차이를 delta 안에 넣어주게 된다.
// 학습중에서는 timer를 쓰지만, 상용 엔진이나 실무에선
// delta를 이용한다. (frame 간 갱신 타임)
void Update(float delta){	
	time = time + delta;
	time2 = time2 + delta;
	/*
		실습 :
		1. 원(50반지름)을 키보드 방향키(화살표) 대로 이동
		2. 10초후에 사라진다.

		B
		움직이지 않을 경우 숨쉬기(idle) 0.5초에 한번씩

		과제
		1. RECT 배열을 이용

		필요한 변수는 선언하자
	*/
	if (time >= 10){
		show_circle = false;
		time = 0.0f;
	} 		
	else {
		if (isRightKeyDown || isLeftKeyDown || isUpKeyDown || isDownKeyDown){
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

		// size = size * -1;

		else if (time2 >= 0.5f ){
			if (size == 50){
				size += 2;
			}
			else if (size > 50){
				size -= 4;
			}
			else if (size < 50){
				size += 4;
			}
			else {
			//	size += -10;
			}
			time2 = 0;
		}
	}
}


/*
	선을 그릴때 PEN이라는 요소는 GDI라이브러리라고 한다.
	Brush는 채우기
	GDI object를 select 한다.
*/
/*
	과제 회색 사각형 격자 무늬그리기
*/
void Render(HDC hdc){	
	// 줄종류
	// PS_SOLD, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT	
	HPEN myPen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, myPen);

	// stock -> white, blck, grey, dkgrey
	//HBRUSH myBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	// HS_BDIAGONAL 좌하향 줄무늬,  HS_CROSS 바둑판,
	// HS_DIAGCROSS : 좌하향 및 우하향, HS_FDIAGNAL : 우하향 줄무늬
	// HS_HORIZONTAL : 수평성, HS_VERTICAL 수직선
	HBRUSH myBrush = (HBRUSH)CreateHatchBrush(HS_HORIZONTAL, RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

	::MoveToEx(hdc, mX, mY, NULL);
	// 첫 시작 설정점에서 부터 계속 이어서 그리게 된다.		
	::LineTo(hdc, mX + 300, mY);
	if (show_circle){
		::Ellipse(hdc, _circle.x - size, _circle.y - size, _circle.x + size, _circle.y + size);
	}

	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	SelectObject(hdc, oldPen);
	DeleteObject(myPen);
}