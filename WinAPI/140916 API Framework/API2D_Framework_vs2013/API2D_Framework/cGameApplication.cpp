#include "StdAfx.h"
#include "cGameApplication.h"
#include "cGameMgr.h"
#include <MMSystem.h>



cGameMgr* g_pGameMgr;

RECT cGameApplication::_wndRect = {0,0,1024,768};
cGameApplication::cGameApplication(cGameMgr* pGameMgr)
{
	g_pGameMgr = pGameMgr;
}


cGameApplication::~cGameApplication(void)
{
	delete g_pGameMgr;
}

bool cGameApplication::Init(HINSTANCE hInstance, WCHAR* title, WCHAR* className, int nCmdShow)
{
	_hInst = hInstance;
	// ���ڿ��� �ʱ�ȭ�մϴ�.
	wsprintf(_szTitle,title);
	wsprintf(_szWindowClass, className);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	return TRUE;

}

//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
//  ����:
//
//    Windows 95���� �߰��� 'RegisterClassEx' �Լ����� ����
//    �ش� �ڵ尡 Win32 �ý��۰� ȣȯ�ǵ���
//    �Ϸ��� ��쿡�� �� �Լ��� ����մϴ�. �� �Լ��� ȣ���ؾ�
//    �ش� ���� ���α׷��� �����
//    '�ùٸ� ������' ���� �������� ������ �� �ֽ��ϴ�.
//
ATOM cGameApplication::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc = {};
	wc.hInstance = hInstance;
	wc.lpszClassName = _szWindowClass;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.style = CS_VREDRAW | CS_HREDRAW ;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = &cGameApplication::WndProc;
	wc.lpszMenuName = NULL;

	return RegisterClass(&wc);
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
BOOL cGameApplication::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   _hInst = hInstance; // �ν��Ͻ� �ڵ��� ��� ������ �����մϴ�.
  

   hWnd = CreateWindow(_szWindowClass, _szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   _hwnd = hWnd;
    GetClientRect(_hwnd,&_wndRect);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}



//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK cGameApplication::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	g_pGameMgr->MsgProc(hWnd, message, wParam, lParam);

	PAINTSTRUCT ps;
	HDC hdc;
	
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		Paint(hdc, hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
	
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void cGameApplication::Run()
{
	DWORD prevTime = timeGetTime();
	DWORD curTime = prevTime;
	DWORD deltaTime = 0;
	DWORD accumTime = 0;
	int   accumFrame = 0;

	MSG msg;
	HDC hdc = GetDC(_hwnd);
	

	// �⺻ �޽��� �����Դϴ�.
	while (true)
	{
		

		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				break;

			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
		}
		else
		{
			curTime = timeGetTime();
			deltaTime = curTime - prevTime;
			prevTime = curTime;

			accumTime += deltaTime;
			accumFrame++;

			
			static WCHAR fpsString[20] = L"";



			if( accumTime >= 1000 )
			{
				_fps = (accumFrame*1000.0f)/accumTime;	// �־��� ��� 1 frame�� ������ ���� �� �ִ�

				accumTime -= 1000;
				accumFrame = 0;

		
				swprintf( fpsString, L"FPS : %2.2f", _fps );
				//SetWindowText(_hwnd,fpsString);
			}

		
			Update( deltaTime / 1000.0f);
			::InvalidateRect(_hwnd,NULL,FALSE);
			Render(hdc);
		
			
		}
	
		
	}

	

	ReleaseDC(_hwnd,hdc);

}

void cGameApplication::Render(HDC hdc1)
{	
	
	HDC hdc = GetDC(_hwnd);
	cGameApplication::Paint(hdc, _hwnd);
	ReleaseDC(_hwnd,hdc);


}

void cGameApplication::Update(float deltaTime)
{
	g_pGameMgr->Update(deltaTime);
}

void cGameApplication::Paint(HDC hdc, HWND hWnd)
{
	static int count=0;
	wchar_t str[128];
	wsprintf(str,L"%d",++count);
	SetWindowText(hWnd,str);
	

	HDC	MemDC = CreateCompatibleDC(hdc);

	HBITMAP	hBlankBitMap = CreateCompatibleBitmap(hdc,
			_wndRect.right,
			_wndRect.bottom);
	//�� ��Ʈ���� �޸� DC�� ���� (��ȭ��)
	HBITMAP	hOldBit = (HBITMAP)SelectObject(MemDC, hBlankBitMap);

	g_pGameMgr->Render(MemDC);

	BitBlt(hdc, 0, 0, _wndRect.right, _wndRect.bottom, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hOldBit);
	DeleteObject(hBlankBitMap);
	DeleteObject(MemDC);

	

}