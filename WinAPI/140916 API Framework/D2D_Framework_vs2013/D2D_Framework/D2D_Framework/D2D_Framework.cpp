// D2D_Framework.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "D2D_Framework.h"
#include "cGameApplication.h"
#include "cMyGameManager.h"

cGameApplication* app;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	
	app = new cGameApplication(new cMyGameManager);
	app->Init(hInstance,L"MyD2DGame", L"MyD2DClass", nCmdShow);
	app->Run();
	delete app;
 	
	return 0;
}


