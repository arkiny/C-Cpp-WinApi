/*
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

int	WINAPI WinMain(HINSTANCE hInst,				// ����� ���α׷�
				HINSTANCE preHIsntance,			// 16��Ʈ ������ ��� �ڵ尡 �����ִ� ��
				LPSTR lpCmdline,				// shell command line parameter, 
												// ���������� ��ũ�Ҷ� ����Ѵ�. (�̿� : tool)
				int nCmdShow)					// ���α׷����� ����ɶ� ��, OS�� �ڵ����� �������ش�.
{
	MessageBox(NULL, L"dd", L"dd", MB_OK);
	return 0;
}