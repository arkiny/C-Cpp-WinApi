/*
	switch( 결과 )			if ( 조건1 )
	{						{
		case 경우1:
			실행..
			break;			}

		case 경우2:			else if ( 조건 2 )
			실행..			{
			break;			}

		default:			else {
			실행..
			break;			}
	}
*/

#include <stdio.h>

void main(){
	// variable initialization
	char nSelect = 0;

	// Interface
	printf("Race Choice : \n");
	printf("1.Terran 2.Protoss 3.Zerg x.Random\n");
	printf("No. ");
	
	// Scanning phase
	scanf("%c", &nSelect);

	// Switch Expression does not judge true or false
	// It takes process by case.
	// Switch Expression can process only one char or number
	switch (nSelect)
	{
	case '1':
		printf("No 1 : You have chosen Terran as your race\n");
		break;
	case '2':
		printf("No 2 : You have chosen Protoss as your race\n");
		break;
	case '3':
		printf("No 3 : You have chosen Zerg as your race\n");
		break;
	case '4':
	case 'x':
		printf("No x : You have chosen Random Race\n");
		break;
	default:
		printf("Wrong Choice\n");
		break;
	}
}