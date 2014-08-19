/*
	결과창 ]]

	국어 점수 입력 : __
	영어 점수 입력 : __
	수학 점수 입력 : __

	or

	국, 영, 수 입력 : __ __ __

	<<< 총점 및 평균 출력 >>>

	총점 = ???
	평균 = ??? ( 소수점 2자리 까지 출력)
*/

#include <stdio.h>
int main(){
	// variable initialization
	int korean = -1;
	int english = -1;
	int math = -1;
	int total = -1;
	float average = -1.0f;

	// input part
	printf("결과창 ]] \n");
	printf("국어 점수 입력 : \n");
	scanf("%d", &korean);
	printf("영어 점수 입력 : \n");
	scanf("%d", &english); 
	printf("수학 점수 입력 : \n");
	scanf("%d", &math);

	// error handling
	if (korean == -1 || english == -1 || math == -1){
		printf("국어, 영어, 수학중 한가지를 입력안하셨습니다.\n");
		return -1;
	}

	// result part
	printf("\n <<< 총점 및 평균 출력 >>>\n\n");
	total = korean + english + math;
	printf("총점 = %d\n", korean + english + math);
	average = (float) total / 3.0f ;
	printf("평균 =  %.2f\n", average);

	return 0;
}