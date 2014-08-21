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
	wc.hCursor = LoadCursor(NULL, IDC_WAIT);				// Ŀ�� �ٲٱ�
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

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);	// msg�� �ؼ����ִ� �Լ�
		DispatchMessage(&msg);
	}

	//MessageBox(NULL, L"dd", L"dd", MB_OK);

	return 0;
}

// ���⼭ Ű���̳� �� ���� ����
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