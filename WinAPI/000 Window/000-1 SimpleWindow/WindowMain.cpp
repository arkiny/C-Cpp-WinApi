#include "SimpleWindow.h"

// Window API는 WinMain에서 실행됨
// while loop위에서 return 0을 받을때까지 계속 진행
// wm_quit을 받지 않을경우 0이 아닌 수
// wm_quit을 받을경우 0을 받게 됨
// 만약 에러 진행시 -1
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	char * cmdParam, int cmdShow){

	wchar_t className[] = L"MyfirstWindow";

	// Winclass 클래스를 윈도우 시스템에 등록
	WinClass winClass(WinMaker::WindowProc, className, hInst);
	winClass.Register();

	// 만들어서 보여주고
	WinMaker win(L"이게 나의 첫 윈도창이다! 안녕 세상!", className, hInst);
	win.Show(cmdShow);

	// 외부 이벤트를 받아와서 처리
	// msg Loop
	// msg를 꺼내가는 것은 실행이 아니다.
	MSG msg = {};

	// 여기서 우리는 질문이 있었지?
	// 만약 메시지가 없이 그대로 대기상태에 있을 경우 Loop은 계속 도는 것일까?
	// 아니면 중간에 홀딩되어 있을것인가?
	while (GetMessage(&msg, NULL, 0, 0)){	// 메시지를 꺼냄, getMessage는 메시지가 있을 때까지 홀딩함
		// 렌더링이 필요한 3D같은 경우에는 계속 Loop을 돌도록 수정
		TranslateMessage(&msg);		// msg를 해석해주는 함수 WM_CHAR 메시지를 만들어내고 msg queue에
		// enqueue 한다.
		// 가장 먼저 전달 하는 것은 가장 처음에 들어온 것 FIFO Queue
		// 키와 관련된 정보들을 통짜로 enqueue (KEYDOWN) 일시에 KEYDOWN
		// 문자가 아닐경우에는 바로 dispatchMessage로 진행한다.
		// msg event reference : http://www.functionx.com/win32/Lesson05.htm
		DispatchMessage(&msg);		// 전역변수와 API를 구별하기 위해서 scope 연산자 :: 를 이용한다.
	}

	return msg.wParam;
}