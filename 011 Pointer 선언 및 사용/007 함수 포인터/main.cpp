/*
	함수 포인터 ( Pointer Function )
	함수 안에 또다른 함수를 넣을수 있다!

	void func()				써왔던 함수의 모습 // 메모리를 할당, 주소가 있음

	void (*pfunc)()			괄호가 중요, 우선순위를 잘 먹여야함
							함수 포인터이므로 다른 함수를 받아줄수 있음

	코드가 커지고 관리하기 힘들어지면 매니저를 만들어야함
	매니지 구조를 만들어주려면 함수 포인터를 알아야 한다.
*/

#include <stdio.h> // printf()

// prototype
void show();
void show1(int a);
int sum(int a, int b, void(*pf)(int));

// main
void main(){
	int k = 0;
	void (*pf)();								// 함수 포인터 선언

	// callback에서도 쓰일수 있는 함수 리콜
	int(*pf2)(int, int, void(*pf)(int));		// A pointer to contain a function which return int
	
	// 변수타입 지정 불가, 함수의 주소를 내놩
	// pf = &k; 

	// pf라는 함수 포인터는 show의 주소를 가지고 있다.
	pf = show; 
	pf(); // printout "hello world" -> show함수 콜
	pf2 = sum;

	int c = pf2(4, 5, show1); // sum of two numbers

	// test print out
	printf("%d\n", c);
} // main()

// show
// printout hello world
void show()
{
	printf("Hello, World?\n");
} //show()

void show1(int a){
	printf("%d\n", a);
}

// sum of two numbers
// @param int a 
// @param int b
// @return int sum of a and b
int sum(int a, int b, void(*pf)(int)){
	pf(a + b);
	return a + b;
}// sum()