/*
	함수 내부의 변수를 밖으로 반환

*/

#include <stdio.h> // printf(), scanf()
#include <conio.h> // _getch()

// main variable
// 외부 정의
//static char ch = 0;

// prototype

// Control
char keyInput();
int* LocalArray();

// main
void main(){
	char chkey = keyInput();
	printf("%c\n", chkey);

	// 맨 처음 값만 잘나오고, 다음 값은 쓰레기 값이 나온다
	int* parr = LocalArray();
	for (int i = 0; i < 5; i++){
		printf("%d\n", parr[i]);
	}

} // main()

// 내부 변수를 쓰기때문에 문제가 있을수 있다
// 값으로 복사를 해서 잘 맞은 거지 근본적인 문제가 해결 된 것은 아니다.
char keyInput(){
	char ch = 0;
	fflush(stdin);
	scanf("%c", &ch);
	return ch;
} // keyInput()

int* LocalArray(){
	// 내부변수는 휘발성 변수이기때문에 쓰면 사라진다.
	// 따라서 static을 쓰면 함수건 변수건 간에 메모리가 고정된다.
	// 프로그램이 종료할때까지 메모리를 차지하게 된다.
	// 따라서 static은 남용하지 말고, 차후에 메모리 정리를 할수 있는 함수도
	// 필요하게 된다.
	static int nums[] = { 11, 12, 13, 14, 15 };
	return nums;
} // LocalArray()

//// 키를 누르면 그 키의 값을 리턴;
//// @return char ret pushed key
//char keyInput(){
//	char ret = 0;
//
//	// key값이 긴값(화살표키 등등)을 가질경우 return값 수정
//	ret = _getch();
//	if (ret == 0){
//		ret = _getch();
//	}
//	
//	return ret;
//} // keyInput()