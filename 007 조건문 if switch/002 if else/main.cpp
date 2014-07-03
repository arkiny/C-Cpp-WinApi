/*
	if ( 조건 )
	{
		(참) 식1
	}
	else
	{
		(거짓) 식2
	}

	(조건) ? (참) 식1 : (거짓) 식2
*/

/*
	숫자 입력 : __

	입력한 숫자가		> 0 "양수" 출력
					< 0 "음수" 출력
					== 0  "0" 출력
*/

#include<stdio.h>
int main(){
	// initialization
	int n_input = 0;

	// scan process
	printf("숫자 입력 : ");
	scanf("%d", &n_input);
	
	// condition checking and printing
	if (n_input > 0){	// larger than 0
		printf("양수\n");
	}	
	else {				// less than 0 or equal to 0
		if (n_input == 0){	// eqaul to 0
			printf("0\n");
		}
		else {				// less than 0
			printf("음수\n");
		}
	} // end if
}