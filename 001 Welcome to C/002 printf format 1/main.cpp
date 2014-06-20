#include <stdio.h>

// comment : some explanation which will not be compiled
// Just for an line

/*
The area of comment
From the start and end
- For commenting several lines
*/

/*
Look around function of printf
print in the console
*/

void main(){
	int i;
	for (i = 0; i < 9; i++){ 
		printf("Alert Sound \a \n"); 
	}	
	printf("BackSpace\b\n"); //delete last one.. (acutually before the cursor)
	printf("\fform feed\n"); // form feed
	printf("force return\n"); // force return
	printf("carrage return \r\n"); // carrage return
	printf("reverse slash \\\n"); // reverse slash
	printf("quote \"\n"); // how to print out quotation mark
	printf("single quote \'\n"); // how to print out single quotation mark
}