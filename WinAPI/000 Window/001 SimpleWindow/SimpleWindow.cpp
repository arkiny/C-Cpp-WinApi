/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	unsigned short를 재정의 한것들
	ifndef에서 multitype과 UNICODE 정의 확인

	WCHAR
	wchar_t
	TCHAR

	수업 진행시에는 UNICODE로 수업 진행
	따라서 수업시간에는 WCHAR를 쓸 예정
	접두어 어느정도 확인 할것

	h handle 윈도우 비트맵 파일등 핸들
	sz 종료 문자열

	lp -> long pointer(4바이트 포인터)

	대부분 재정의를 통하기때문에 LP가 나오면 무조건 포인터라고 생각을 한다.
	대부분 사용자 저으이 데이터형은 재정의 다어있다.(대문자로)
	char와 wchar의 중간 타입은 TCHAR

	유니코드 지원합수는 함수 앞에 소문자 l 을 붙여줘야한다.
	lstrlen
	lstrcpy
	lstrcat
	lstrcmp
	wsprintf
*/

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 원형은 정해져 있다

int	WINAPI WinMain(HINSTANCE hInst,				// 실행된 프로그램
				HINSTANCE preHIsntance,			// 16비트 시절에 썼던 코드가 남아있는 것
				LPSTR lpCmdline,				// shell command line parameter, 
												// 저장파일을 링크할때 사용한다. (이용 : tool)
				int nCmdShow)					// 프로그래밍이 실행될때 값, OS가 자동으로 설정해준다.
{
	WNDCLASS wc = {};							// 윈도우를 분류하는 구조체의 이름
	wc.hInstance = hInst;
	wc.lpszClassName = L"MyShittyWindow";
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	// 화면에 그리는 것을 할때 다시 배우게 될 예정
	wc.hCursor = LoadCursor(NULL, IDC_WAIT);				// 커서 바꾸기
	wc.style = CS_VREDRAW | CS_HREDRAW;						// 윈도우사이즈 중에 변경이 되면 다시 그려라
	wc.hIcon = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WindowProc;								// callback 내가 호출하는게 아니라 남에 의해서 호출되는 함수	
	wc.lpszMenuName = NULL;
	
	RegisterClass(&wc);										// 레지스터
	
	HWND hWnd = CreateWindowEx(
							0,
							L"MyShittyWindow",
							L"Hello My Window",							
							WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,
							// 나중에 윈도우 만들때 최대화 버튼을 빼거나 할때 여기서 수정하면 된다고 합니다.
							CW_USEDEFAULT,		
							CW_USEDEFAULT,
							800,
							600,
							NULL,
							NULL,
							hInst,
							NULL);

	ShowWindow(hWnd, nCmdShow); // 여기까지 보여주는 것

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);	// msg를 해석해주는 함수
		DispatchMessage(&msg);
	}

	//MessageBox(NULL, L"dd", L"dd", MB_OK);

	return 0;
}

// 여기서 키값이나 다 받을 예정
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch (uMsg)
	{
	case WM_KEYDOWN:
		MessageBox(NULL, L"dd", L"dd", MB_OK);
		return 0;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}