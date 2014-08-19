/*
	연습 ] 무한 문자 입력

	for 문 활용 ] 무한 루프 도리기

	'$' 가 입력되면 루프 종료
	아니면, 무한 루프 돌면서 ...
	입력한 문자를 출력

	]]

	입력 : ____

	입력한 값은 = ____

	입력 :: ____

	...

	입력 : $

	종료...........
*/

#include <stdio.h>
int main(){
	// printout input char during infinite loop
	// 문자를 받는 것은 루프문 내에서 있어야 할득
	// scanf should be in the loop expr
	// Variable Initialization
	char input = 0;
	for (int i = 0 ; i < 1; i){
		printf("\n입력 : ");

		// flush. , stdin 키보드 입력 버퍼 날려버림
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		//scanf(" %c", &input);
		// 삼항 연산자 내에서는 무조건 식이 들어가야 하므로 break 사용 불가
		// we cannot use 'break' command in the condition operator
		(input == '$') ? i++ : printf("입력한 값은 = %c\n", input);
	} //end for

	// 선생님이 쓰신 방식
	// $키 아니면, 루프 돌고
	// $키가 입력되면 루프 종료
	for (; input!= '$';){
		printf("\n입력 : ");

		// flush. , stdin 키보드 입력 버퍼 날려버림
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		printf("입력한 값은 = %c\n", input);
	} //end for

	// while 문 이용
	while (input != '$'){
		printf("\n입력 : ");

		// flush. , stdin 키보드 입력 버퍼 날려버림
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		printf("입력한 값은 = %c\n", input);
	} //end while
}
