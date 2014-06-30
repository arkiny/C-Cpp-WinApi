/*
	반복문 - for

	for ( 시작값 ; 종료조건 ; 증감값 )
	{
		작업 ...
	}
*/

#include <stdio.h>
void main(){
	// for문을 활용 하여 20부터 1까지 -2씩 감소 출력
	// for (시작점 설정 ; 조건; 증감값){ 내용 }
	for (int i = 20; i > 0; i -= 2){
		printf("%d\n", i);
	} //end for

	for (;;){
		//무한루프
		break;
	} // end for

	// while loop처럼 for loop 쓰기
	int n = 0;
	for (; n <= 10;){
		printf("1111\n");
		n++;
	} // end for

	while (1){
		//무한루프
		break;
	}	// end for


}