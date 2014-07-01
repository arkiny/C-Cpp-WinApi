/*
	if ( 조건 ) { 조건 : 참, 거짓
		조건이 참이면 이곳을 실행
	}

	조건 ? (참) 식1 : (거짓) 식2
*/

#include <stdio.h>
void main(){
	// 1 ~ 15까지 8이상만 출력 
	for (int i = 1; i <= 15; i++){
		if (i >= 8){
			printf("i = %d\n", i);
		}
	}

	// 위에 상황에서, 8이상출력한 수 중에 짝수만 출력
	printf("\n\n");
	for (int i = 1; i <= 15; i++){
		if (i >= 8 && i % 2 == 0){
			printf("i = %d\n", i);
		}
	}
}