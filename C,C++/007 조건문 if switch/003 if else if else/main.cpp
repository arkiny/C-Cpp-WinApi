/*
	if ( ����1 )
	{
		����1 ���̸� �̰��� ����
	}
	else if ( ����2 )
	{
		����2 ���̸� �̰��� ����
	}
	else if ( ���� 3 )
	{
		����3 ���̸� �̰��� ����
	}
	else
	{
		�̵� ���� �ƴϸ� �̰��� ����
	}
*/

#include <stdio.h>
void main()
{
	/*
		���� �Է� : __
		������ ���� ( %3 )
		0 �̸� -> Human Alliance
		1 �̸� -> Orc hordes
		2 �̸� -> Night Elf Group
		3 �̸� -> Undead Battalion

		You have joined _________________
	*/
	// Variable initialization
	int n_input = -1;

	// Scan phase
	printf("���� �Է� : ");
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