/*
	while (종료조건)
	{
		작업....
	}

---------------------------------------
	조건과 상관없이 일단 한번 돌려보고
	그뒤에 조건 판단

	process one time before the condition check,
	and condition checking
	do
	{
		작업.....
	} while (종료조건) ;
*/

#include <stdio.h>
void main(){
	// 20 부터 5까지 -3씩 감소
	int i = 20;
	do{
		printf("%d\n", i);		//출력
		i -= 3;					//증감값
	} while (i>4);				//종료조건


}