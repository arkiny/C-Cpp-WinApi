/*
	printf % function
	2	: Binary
	5	: Penta
	6	: Hexa
	8	: Octal
	10	: Decimal
	16	: Hexa-Decimal

	In Decimal :		7 8 9 10 11 12 13 14 15 16
	In hexa-Decimal :	7 8 9 A  B  C  D  E	 F	10
*/

#include <stdio.h>
void main()
{
	// Number Formats
	printf("Decimal = %d\n", 2014);
	printf("Octal = %o\n", 2014);
	printf("Hexa-Decimal = %x\n", 2014);

	// Real Number
	printf("number = %.4f\n", 3.141592); // 

	// Character Printing
	printf("Character Printing = %c \n", 'Z');
	printf("Character Array(or serize) Printing = %s\n", "Brazil Worldcup");
}