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
void MouseMove(int x, int y);

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
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// 커서 바꾸기
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

	//MessageBox(NULL, L"dd", L"dd", MB_OK);

	return 0;
}

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

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	// 콜되면 지역변수는 초기화 된다.
	// 아예 전역변수를 짜던지 static을 이용하도록 한다.
	int mouseX=0, mouseY=0;
	TCHAR str[128] = L"";
	static RECT winRect = { 0, };
	POINT pt;

	switch (uMsg)
	{	
	case WM_CREATE:
		// 창이 처음 생성될때
		::GetClientRect(hWnd, &winRect);
		wsprintf(str, L"Window Created w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hWnd, str);
		return 0;

	case WM_SIZE:
		::GetClientRect(hWnd, &winRect);
		wsprintf(str, L"Window Created w: %d, h : %d", winRect.right, winRect.bottom);
		::SetWindowText(hWnd, str);
		break;



	case WM_KEYDOWN:
		// get current pos
		GetCursorPos(&pt);

		// convert screen coordinate to client
		ScreenToClient(hWnd, &pt);

		switch (wParam){ // wparam의 경우
		//case VK_SPACE:
		case VK_LEFT:			
			pt.x -= 1;
			break;
		case VK_RIGHT:
			pt.x += 1;
			break;
		case VK_UP:
			pt.y -= 1;
			break;
		case VK_DOWN:
			pt.y += 1;
			break;
		default:
			MessageBox(hWnd, L"Default", L"Default", MB_OK);
			return 0;
		}		

		ClientToScreen(hWnd, &pt);
		SetCursorPos(pt.x, pt.y);
		return 0;

	case WM_KEYUP:
		//MessageBox(hWnd, L"WM_KEYUP", L"WM_KEYUP_Alert", MB_OK);
		return 0;
	
	case WM_LBUTTONDOWN:
		// 평면상에서 마우스는 위치를 가지고 있고, 그 위치 정보를 표현하기 위해
		// X좌표와 Y좌표가 필요하다. 화면에서는 데카르트 좌표를 이용한다.
		// 2바이트씩 이용하기 때문에 비트연산을 이용해서 뺄수가 있다.
		// 하라고 하면 할수 있지만 매크로를 만들어 놓음 ㅋ
		
		/*
			실습 : 
			마우스를 클릭하면 화면의 왼쪽인지 오른쪽인지 구분해서
			MessageBox or SetWindowText로 뿌릴것
			정확하게 가운데를 클릭한 경우
		*/

		// 메세지당 처리는 한번
		// 집에가서 과제하면서 OOP로 정리하고....

		mouseX = LOWORD(lParam);
		mouseY = LOWORD(lParam);

		::GetClientRect(hWnd, &winRect);

		if (mouseX == (winRect.right / 2)){
			wsprintf(str, L"잭팟! %d, %d", mouseX, mouseY);
					}
		else if (mouseX < (winRect.right / 2)){
			wsprintf(str, L"왼쪽! %d, %d", mouseX, mouseY);
		}
		else {
			wsprintf(str, L"오른쪽! %d, %d", mouseX, mouseY);
		}

		::SetWindowText(hWnd, str);
		//MessageBox(hWnd, L"WM_LBUTTONCLICK", L"WM_LBUTTONCLICK_Alert", MB_OK);
		return 0;

	case WM_MOUSEMOVE:
		return 0;
	
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//void MouseMove(int x, int y)
//{
//	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
//	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
//	double fx = x*(65535.0f / fScreenWidth);
//	double fy = y*(65535.0f / fScreenHeight);
//	INPUT  Input = { 0 };
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
//	Input.mi.dx = fx;
//	Input.mi.dy = fy;
//	::SendInput(1, &Input, sizeof(INPUT));
//}