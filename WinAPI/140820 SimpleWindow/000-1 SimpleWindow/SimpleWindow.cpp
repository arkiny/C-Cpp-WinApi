/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
	@reference : http://www.relisoft.com/win32/winnie.html

	기본적으로 WinAPI에서 쓰이는 스트링 Parameter는 
	대부분 LPCWSTR(Long Pointer to Constant Wide String)
	2byte char로 저장되는 str형식의 Parameter

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

#include "SimpleWindow.h"
#include "KeyController.h"

WinClass::WinClass(WNDPROC winProc, wchar_t const * className, HINSTANCE hInst){
	_class.style = CS_VREDRAW | CS_HREDRAW;
	_class.lpfnWndProc = winProc;				// windows procedure
	_class.cbClsExtra = 0;
	_class.cbWndExtra = 0;
	_class.hInstance = hInst;					// owner of the class
	_class.hIcon = 0;
	_class.hCursor = ::LoadCursor(NULL, IDC_ARROW);			// optional
	_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// also optional
	_class.lpszMenuName = 0;
	_class.lpszClassName = className; // mendatory
}

WinMaker::WinMaker(wchar_t const * caption, wchar_t const * className, 
					HINSTANCE hInstance){
	_hwnd = ::CreateWindow(
		className,	// name of the window class
		caption,					// window caption
		WS_OVERLAPPEDWINDOW,		// style
		// F12해서 보면 WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
		// 나중에 윈도우 만들때 최대화 버튼을 빼거나 할때 여기서 수정하면 된다고 합니다.
		CW_USEDEFAULT,				// x position
		CW_USEDEFAULT,				// y position
		800,						// width
		600,						// height
		NULL,						// handle to parent
		NULL,						// handle to menu
		hInstance,					// applcation instance
		NULL);						// window creation data	
}

// Window Procedure called by Windows
// 콜백되는 프로시져 함수
// wmquit = 0 일경우, 종료 메세지후, 종료
// 아닐시 DefWindwsProc을 콜하여 리턴
// 여기서 키값이나 다 받을 예정
// 실습 :
// 1. 윈도우 생성시 msgbox 뿌리기
// 2. 키 누를때
// 3. 키 뗄때
// 4. 마우스 좌클릭
// 대부분 입력정보
// 조이스틱은 가상 키로 해서 keydown에서 수정한다.
// 매 프레임마다 계속 반복하면서 화면을 갱신하며 애니메이션 처리를 한다.
// 내가 키보드를 눌렀거나 마우스를 클릭했을때 (특정 이벤트) 처리를 알아야 해당 코드를 이용할수
// 있다. 그 관련된 실습을 해볼거심
// switch 구문 안애는 새로운 변수를 생성할수 없다. 그럴 경우에는 블록을 설정해줘야지
// 내부 변수를 만들수 있다. (따라서 블록을 싸던가, 밖으로 싸던가)
//
// 윈도우 사이즈를 잴때 Rectangle을 이용해서 
// lefttop, rightbottom을 가지고 와서 화면의 중앙정보를 가지고 올수가 있다.
// wparam lparam 둘다 4바이트
LRESULT CALLBACK WinMaker::WindowProc
(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
	// 콜되면 지역변수는 초기화 된다.
	// 아예 전역변수를 짜던지 static을 이용하도록 한다.
	int mouseX = 0, mouseY = 0;
	TCHAR str[128] = L"";
	KeyController key_Ctl(hwnd, wParam);
	static RECT winRect = { 0, };
	
	switch (message)
	{
	case WM_CREATE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Created w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		return 0;

	case WM_SIZE:
		::GetClientRect(hwnd, &winRect);
		wsprintf(str, L"Window Resized w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hwnd, str);
		break;

	// 차후에 KeyControl Class를 만들어서 처리 시키면 더 깔끔해 질듯 합니다.
	// 장점은 일단 코드가 깔끔해지고 차후 키컨트롤 매니저를 이용할수 있지만
	// 단점은 그만큼 메모리를 더 잡아먹고 프로세스타임이 길어질수도 있다는거?
	// 따라서 그렇게 만들기로함
	case WM_KEYDOWN:		
		key_Ctl.execute();
		return 0;

	case WM_KEYUP:
		//MessageBox(hWnd, L"WM_KEYUP", L"WM_KEYUP_Alert", MB_OK);
		return 0;

	case WM_LBUTTONDOWN:
		// 평면상에서 마우스는 위치를 가지고 있고, 그 위치 정보를 표현하기 위해
		// X좌표와 Y좌표가 필요하다. 화면에서는 데카르트 좌표를 이용한다.
		// 2바이트씩 이용하기 때문에 비트연산을 이용해서 뺄수가 있다.
		// 하라고 하면 할수 있지만 매크로를 만들어 놓음 ㅋ
		
		mouseX = LOWORD(lParam);
		mouseY = HIWORD(lParam);

		wsprintf(str, L"%d, %d", mouseX, mouseY);
		::SetWindowText(hwnd, str);
		//MessageBox(hWnd, L"WM_LBUTTONCLICK", L"WM_LBUTTONCLICK_Alert", MB_OK);
		return 0;

	case WM_MOUSEMOVE:
		return 0;

	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hwnd, message, wParam, lParam);
}




// 참고용 쓰레기 코드 
// (string을 wstr으로 바꾸거나 char를 wchar_t 로 바꾸거나..)

/*WCHAR strtemp[50];
MultiByteToWideChar(0, 0, className, 50, strtemp, 50);
LPCWSTR cstrtemp = strtemp;*/
// string to wide string(UNICODE)
/*std::wstring strtemp(className.begin(), className.end());
LPCWSTR classNamet = strtemp.c_str();*/

/*std::wstring strtemp = std::wstring(className.begin(), className.end());
LPCWSTR LWclassName = strtemp.c_str();
strtemp = std::wstring(caption.begin(), caption.end());
LPCWSTR LWcaptiont = strtemp.c_str();*/

// string to wide string(UNICODE)