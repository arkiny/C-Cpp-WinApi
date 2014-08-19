/*
	random 함수
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// function declaration
int RandomRange(int begin, int end);

// main function
void main(){
	
	// 1~6까지 랜덤 숫자 발생하도록 만들어보기
	int nr = 0;
	int i = 0;

	srand(time(NULL));
	
	while (i < 10){
		printf("Random = %d \n", RandomRange(1,10));
		i++;
	} // end while
	//RandomRange( 몇부터 몇까지 )

}

// Assume that seeding is already done
int RandomRange(int begin, int end){
	return rand() % (end-begin) + begin;
	// or (rand() % end) + begin
}

// 과제
/*
	조작 주사위 만들기
	1	-> 100c			60%
	2	-> 300 c		32
	3	->	5000 c		4
	4- >
*/