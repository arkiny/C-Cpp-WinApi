// API2D_Framework.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "API2D_Framework.h"
#include "cGameApplication.h"
#include "cMyGameManager.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	cGameApplication* app = new cGameApplication(new cMyGameManager);
	app->Init(hInstance,L"MyGame", L"MyClass", nCmdShow);
	app->Run();
	delete app;
	return 0;
}


