/*
	if ( 조건1 )
	{
		조건1 참이면 이곳을 실행
	}
	else if ( 조건2 )
	{
		조건2 참이면 이곳을 실행
	}
	else if ( 조건 3 )
	{
		조건3 참이면 이곳을 실행
	}
	else
	{
		이도 저도 아니면 이곳을 실행
	}
*/

#include <stdio.h>
void main()
{
	/*
		숫자 입력 : __
		나머지 연산 ( %3 )
		0 이면 -> Human Alliance
		1 이면 -> Orc hordes
		2 이면 -> Night Elf Group
		3 이면 -> Undead Battalion

		You have joined _________________
	*/
	// Variable initialization
	int n_input = -1;

	// Scan phase
	printf("숫자 입력 : ");
	scanf("%d", &n_input);
	
	// Condition checking and printing phase
	printf("You have joined ");
	if (n_input % 4 == 0){	// modular 0
		printf("Human Alliance!\n");
	}
	else if (n_input % 4 == 1){ // modular 1
		printf("Orc hordes!\n");
	}
	else if (n_input % 4 == 2){ // modular 2
		printf("Night Elf Group!\n");
	}
	else if (n_input % 4 == 3){ // modular 3
		printf("Undead Battalion!\n");
	}
	else { // cannot be happened
		printf("Troll tribe because you put the weired number!\n");
	}
}