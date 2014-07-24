/*
	C plus plus
	C++

	:: scope resoultion operator
	( 영역 연산자 )
*/

#include <iostream>

using namespace std;

// 변수라는 말을 쓰는게 아니라 객체란 말을 쓴다.
// namespace
// class
int main(){
	std::cout << "CPP로 처음 출력하기" << std::endl;
	std::cout << "개행문자 확인 \n" << "\n";

	// using 이후에 cout 과 endl은 
	// 그냥 cout, endl로 사용하면 된다.
	using std::cout;
	using std::endl;

	enum week {Mo, Tu, We, Th, f};
	week::Mo;

	cout << "using 이후 cout" 
		<< endl;

	// cout 출력 담담 클래스
	// cin 입력 담당 클래스

	int ncarrot = 0;
	cout << "당근을 몇개 먹었습니까? ";
	
	//ncarrot 값
	cin >> ncarrot;
	cout << "당근을 " << ncarrot << " 개 먹었습니다." << endl;

	// 당근을 10진수로 몇개 먹었습니다.
	cout << "당근을 10진수로  " << dec << " 개 먹었습니다." << endl;

	// 당근을 16진수로 몇개 먹었습니다.
	cout << "당근을 16진수로 " << hex << ncarrot << endl; 
	
	// 당근을 8진수로 몇개 먹었습니다.
	cout << "당근을 8진수로 " << oct << ncarrot << endl;

	// prinf와는 다른점.... class이므로 내부에서 변수를 바꿨기 때문에
	// 계속 8진수로 출력이 된다.
	cout << dec << 10 << endl;

	// 나누기 연산
	cout << 14.78f << " / " << 9.61f << " = " << 14.78f / 9.61f << endl;

	// 정수로 나누면? printf와 달리 형 충돌이 나지 않는다...
	cout.precision(3);
	cout << 14.78f << " / " << 9 << " = " << 14.78f / 9 << endl;
}