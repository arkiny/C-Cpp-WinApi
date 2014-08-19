/*
	for 활용 ]

	적금 ( 예치금 : 한번에 다 맡김 )

	연 이율 3.1%

	얼마 넣을지 ? __
	몇년간 맡길지 ? __

	1년째 : 이자 __, 총금액 __
	2년째 ..
	n년째 : 이자 __, 초금액__

	공식 ]
	이자 = 원금 * 0.031;
	총금액 = 이자 + 이전 총금액;
*/

#include<stdio.h>
int main(){
	// Variable Initialization
	// 변수 초기화
	// 총저축액, 저축년수, 이자 출력용 변수
	int deposit = -1, years = -1, benefit = -1;
	
	// Scanning
	// 입력단계
	printf("얼마나 넣으시겠습니까?\n");
	scanf("%d", &deposit);
	printf("몇년 넣으시겠습니까?\n");
	scanf("%d", &years);
	benefit = deposit * 0.031f;

	// Loop, calculation and printing
	// 반복, 계산, 출력단계
	for (int i = 1; i <= years; i++){
		deposit = deposit + benefit;			// 총금액 = 이자 + 이전 총금액
		printf("%d년째 : 이자 %d, 총금액 %d\n", i, benefit, deposit);
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	printf(" 복리 계산법 ㅡㅡ\n");
	// Variable Initialization
	// 변수 초기화
	// 총저축액, 저축년수, 이자 출력용 변수
	//int deposit = -1, years = -1, benefit = -1;

	// Scanning
	// 입력단계
	printf("얼마나 넣으시겠습니까?\n");
	scanf("%d", &deposit);
	printf("몇년 넣으시겠습니까?\n");
	scanf("%d", &years);

	// Loop, calculation and printing
	// 반복, 계산, 출력단계
	for (int i = 1; i <= years; i++){
		benefit = deposit * 0.031;				// 이자 = 원금 * 0.031
		deposit = deposit + benefit;			// 총금액 = 이자 + 이전 총금액
		printf("%d년째 : 이자 %d, 총금액 %d\n", i, benefit, deposit);
	}


	/////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	
	////////////////// 선생님 답안
	int nMoney = 0;	// 맡긴 금액
	int nYear = 0;	// 맡긴 기간
	const float fInterestRate = 0.031f;	// 연이율 (상수)
	int nInterest = 0; // 이자

	printf("금액은 : ");
	scanf("%d", &nMoney);
	printf("몇 년간: ");
	scanf("%d", &nYear);

	for (int i = 0; i <= nYear; i++){
		nInterest = nMoney * fInterestRate;
		nMoney = nMoney + nInterest;
		printf("%d 년 : 이자 = %d, 총금액 = %d\n", i, nInterest, nMoney);
	}
}