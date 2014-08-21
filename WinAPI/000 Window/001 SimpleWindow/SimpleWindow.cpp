/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	unsigned short�� ������ �Ѱ͵�
	ifndef���� multitype�� UNICODE ���� Ȯ��

	WCHAR
	wchar_t
	TCHAR

	���� ����ÿ��� UNICODE�� ���� ����
	���� �����ð����� WCHAR�� �� ����
	���ξ� ������� Ȯ�� �Ұ�

	h handle ������ ��Ʈ�� ���ϵ� �ڵ�
	sz ���� ���ڿ�

	lp -> long pointer(4����Ʈ ������)

	��κ� �����Ǹ� ���ϱ⶧���� LP�� ������ ������ �����Ͷ�� ������ �Ѵ�.
	��κ� ����� ������ ���������� ������ �پ��ִ�.(�빮�ڷ�)
	char�� wchar�� �߰� Ÿ���� TCHAR

	�����ڵ� �����ռ��� �Լ� �տ� �ҹ��� l �� �ٿ�����Ѵ�.
	lstrlen
	lstrcpy
	lstrcat
	lstrcmp
	wsprintf
*/

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ������ ������ �ִ�
void MouseMove(int x, int y);

int	WINAPI WinMain(HINSTANCE hInst,				// ����� ���α׷�
				HINSTANCE preHIsntance,			// 16��Ʈ ������ ��� �ڵ尡 �����ִ� ��
				LPSTR lpCmdline,				// shell command line parameter, 
												// ���������� ��ũ�Ҷ� ����Ѵ�. (�̿� : tool)
				int nCmdShow)					// ���α׷����� ����ɶ� ��, OS�� �ڵ����� �������ش�.
{
	WNDCLASS wc = {};							// �����츦 �з��ϴ� ����ü�� �̸�
	wc.hInstance = hInst;
	wc.lpszClassName = L"MyShittyWindow";
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	// ȭ�鿡 �׸��� ���� �Ҷ� �ٽ� ���� �� ����
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// Ŀ�� �ٲٱ�
	wc.style = CS_VREDRAW | CS_HREDRAW;						// ����������� �߿� ������ �Ǹ� �ٽ� �׷���
	wc.hIcon = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WindowProc;								// callback ���� ȣ���ϴ°� �ƴ϶� ���� ���ؼ� ȣ��Ǵ� �Լ�	
	wc.lpszMenuName = NULL;
	
	RegisterClass(&wc);										// ��������
	
	HWND hWnd = CreateWindowEx(
							0,
							L"MyShittyWindow",
							L"Hello My Window",							
							WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,
							// ���߿� ������ ���鶧 �ִ�ȭ ��ư�� ���ų� �Ҷ� ���⼭ �����ϸ� �ȴٰ� �մϴ�.
							CW_USEDEFAULT,		
							CW_USEDEFAULT,
							800,
							600,
							NULL,
							NULL,
							hInst,
							NULL);

	ShowWindow(hWnd, nCmdShow); // ������� �����ִ� ��

	// msg Loop
	// msg�� �������� ���� ������ �ƴϴ�.
	MSG msg = {};

	// ���⼭ �츮�� ������ �־���?
	// ���� �޽����� ���� �״�� �����¿� ���� ��� Loop�� ��� ���� ���ϱ�?
	// �ƴϸ� �߰��� Ȧ���Ǿ� �������ΰ�?
	while (GetMessage(&msg, NULL, 0, 0)){	// �޽����� ����, getMessage�� �޽����� ���� ������ Ȧ����
											// �������� �ʿ��� 3D���� ��쿡�� ��� Loop�� ������ ����
		TranslateMessage(&msg);		// msg�� �ؼ����ִ� �Լ� WM_CHAR �޽����� ������ msg queue��
									// enqueue �Ѵ�.
									// ���� ���� ���� �ϴ� ���� ���� ó���� ���� �� FIFO Queue
									// Ű�� ���õ� �������� ��¥�� enqueue (KEYDOWN) �Ͻÿ� KEYDOWN
									// ���ڰ� �ƴҰ�쿡�� �ٷ� dispatchMessage�� �����Ѵ�.
									// msg event reference : http://www.functionx.com/win32/Lesson05.htm
		DispatchMessage(&msg);		// ���������� API�� �����ϱ� ���ؼ� scope ������ :: �� �̿��Ѵ�.
	}

	//MessageBox(NULL, L"dd", L"dd", MB_OK);

	return 0;
}

// ���⼭ Ű���̳� �� ���� ����
// �ǽ� :
// 1. ������ ������ msgbox �Ѹ���
// 2. Ű ������
// 3. Ű ����
// 4. ���콺 ��Ŭ��
// ��κ� �Է�����
// ���̽�ƽ�� ���� Ű�� �ؼ� keydown���� �����Ѵ�.
// �� �����Ӹ��� ��� �ݺ��ϸ鼭 ȭ���� �����ϸ� �ִϸ��̼� ó���� �Ѵ�.
// ���� Ű���带 �����ų� ���콺�� Ŭ�������� (Ư�� �̺�Ʈ) ó���� �˾ƾ� �ش� �ڵ带 �̿��Ҽ�
// �ִ�. �� ���õ� �ǽ��� �غ��Ž�
// switch ���� �Ⱦִ� ���ο� ������ �����Ҽ� ����. �׷� ��쿡�� ����� �����������
// ���� ������ ����� �ִ�. (���� ����� �δ���, ������ �δ���)
//
// ������ ����� �궧 Rectangle�� �̿��ؼ� 
// lefttop, rightbottom�� ������ �ͼ� ȭ���� �߾������� ������ �ü��� �ִ�.
// wparam lparam �Ѵ� 4����Ʈ

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	// �ݵǸ� ���������� �ʱ�ȭ �ȴ�.
	// �ƿ� ���������� ¥���� static�� �̿��ϵ��� �Ѵ�.
	int mouseX=0, mouseY=0;
	TCHAR str[128] = L"";
	static RECT winRect = { 0, };
	POINT pt;

	switch (uMsg)
	{	
	case WM_CREATE:
		// â�� ó�� �����ɶ�
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

		switch (wParam){ // wparam�� ���
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
		// ���󿡼� ���콺�� ��ġ�� ������ �ְ�, �� ��ġ ������ ǥ���ϱ� ����
		// X��ǥ�� Y��ǥ�� �ʿ��ϴ�. ȭ�鿡���� ��ī��Ʈ ��ǥ�� �̿��Ѵ�.
		// 2����Ʈ�� �̿��ϱ� ������ ��Ʈ������ �̿��ؼ� ������ �ִ�.
		// �϶�� �ϸ� �Ҽ� ������ ��ũ�θ� ����� ���� ��
		
		/*
			�ǽ� : 
			���콺�� Ŭ���ϸ� ȭ���� �������� ���������� �����ؼ�
			MessageBox or SetWindowText�� �Ѹ���
			��Ȯ�ϰ� ����� Ŭ���� ���
		*/

		// �޼����� ó���� �ѹ�
		// �������� �����ϸ鼭 OOP�� �����ϰ�....

		mouseX = LOWORD(lParam);
		mouseY = LOWORD(lParam);

		::GetClientRect(hWnd, &winRect);

		if (mouseX == (winRect.right / 2)){
			wsprintf(str, L"����! %d, %d", mouseX, mouseY);
					}
		else if (mouseX < (winRect.right / 2)){
			wsprintf(str, L"����! %d, %d", mouseX, mouseY);
		}
		else {
			wsprintf(str, L"������! %d, %d", mouseX, mouseY);
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