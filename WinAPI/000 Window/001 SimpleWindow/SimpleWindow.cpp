/*
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

int	WINAPI WinMain(HINSTANCE hInst,				// 실행된 프로그램
				HINSTANCE preHIsntance,			// 16비트 시절에 썼던 코드가 남아있는 것
				LPSTR lpCmdline,				// shell command line parameter, 
												// 저장파일을 링크할때 사용한다. (이용 : tool)
				int nCmdShow)					// 프로그래밍이 실행될때 값, OS가 자동으로 설정해준다.
{
	MessageBox(NULL, L"dd", L"dd", MB_OK);
	return 0;
}