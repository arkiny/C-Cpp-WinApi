/*
	조건 연산자 ( 삼항 연산자 )
	조건 ? (참) 식1 : (거짓) 식2
*/

#include <stdio.h>
int main(){
	int A = 7, B = 3;
	int nResult = 0;
	
	nResult = A < B ? A : B; // 종종 쓴다캄 ㅎㅎㅎㅎㅎㅎㅎ
	printf("result = %d\n", nResult);

	/*
		scanf를 활용하여
		"두 수를 입력 : __ __"
		두 수중 큰 수를 찾아내기
	*/

	// input variables init
	int nA = 0, nB = 0;
	// result variables
	int nResult_Max = 0;

	// Scanning part
	printf("두 수를 입력 : \n");
	scanf("%d %d", &nA, &nB); // 어드레스로 받는걸 잊지 말자 끄앙

	// Compute and return part
	nResult_Max = nA > nB ? nA : nB;
	printf("더 큰수는 =  %d\n", nResult_Max);
	return 0;
}