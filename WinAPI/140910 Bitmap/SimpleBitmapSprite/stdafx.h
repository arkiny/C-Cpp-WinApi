// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#pragma comment(lib, "msimg32.lib")
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
struct MYSPRITE
{
	MYSPRITE();
	MYSPRITE(int _l, int _t, int _w, int _h);
	~MYSPRITE();
	int left;
	int top;
	int width;
	int height;
};