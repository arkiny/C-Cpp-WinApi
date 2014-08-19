/*
	1부터 130까지 수 중에
	7의 배수는 몇개인가? ___

	while 문을 활용]
*/

#include<stdio.h>
int main(){
	int i = 1;									// 숫자 시작점 (0은 에러처리 되므로 1부터 시작
	int check = 0;								// 배수의 개수 처리
	int temp = -1;								// 나머지 처리, -1로 시작하는 이유는 차후 에러처리를 위해

	while (i <= 130){							// i가 130보다 작을 경우

		// 여기서 선생님으로 처리하셨고, 이는 두번의 계산프로세스 사용
		//i % 7 == 0 ? check++ :
		//			printf("");							// do nothing

		temp = i % 7;							// 나머지 구함
		temp == 0 ?								// 7의 배수일때 카운트 업
			check++ :							
			printf("");							// do nothing
		temp == 0 ?								// 7의 배수일때 출력
			printf("배수 : %d\n", i) :
			printf("");							// do nothing
		i++;		
	}// end while

	printf("배수의 총 개수 : %d\n", check);
	getchar();
}