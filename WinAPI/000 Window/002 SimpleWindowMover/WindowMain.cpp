#include "SimpleWindow.h"

// Window API�� WinMain���� �����
// while loop������ return 0�� ���������� ��� ����
// wm_quit�� ���� ������� 0�� �ƴ� ��
// wm_quit�� ������� 0�� �ް� ��
// ���� ���� ����� -1
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	char * cmdParam, int cmdShow){

	wchar_t className[] = L"MyfirstWindow";

	// Winclass Ŭ������ ������ �ý��ۿ� ���
	WinClass winClass(WinMaker::WindowProc, className, hInst);
	winClass.Register();

	// ���� �����ְ�
	WinMaker win(L"�̰� ���� ù ����â�̴�! �ȳ� ����!", className, hInst);
	win.Show(cmdShow);

	// �ܺ� �̺�Ʈ�� �޾ƿͼ� ó��
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

	return msg.wParam;
}