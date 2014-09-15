// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#pragma comment( lib, "d2d1.lib" )
#pragma comment( lib, "WindowsCodecs.lib" )
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <cassert>
#include <commdlg.h>


#include <wincodec.h>

#include <d2d1.h>
#include <d2d1helper.h>
template <typename T>
inline void SafeRelease(T *&p)
{
	if (NULL != p)
	{
		p->Release();
		p = NULL;
	}
}