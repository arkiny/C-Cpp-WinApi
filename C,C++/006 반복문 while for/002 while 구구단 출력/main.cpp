/*
	while - 구구단 출력
	몇 단 출력(퇴장시 q) : __ (scanf)

	_  * 1 = ?
	*/

#include<stdio.h>
int main(){

	int q = -1;
	int n_input = -1;
	int i = 1;
	
	while (n_input != -2){
		n_input = -1;
		i = 1;
		printf("__ 단 출력 (퇴장시 -2)\n입력 : ");
		scanf("%d", &n_input);
		printf("\n");

		printf("%d 단이 출력됩니다.\n");
		while (i <= 9){ // i가 9보다 작을경우
			printf("%d * %d = %d\n", n_input, i, n_input*i);
			i++;
		}
		printf("\n");
	}

	return 0;
}

/*
while 문 활용]
* 8개 그리기
*
 *
  *
   *
    *
	 *
	  *
	   *
가로 : H
세로 : V
이중 while 문 활용.
*/