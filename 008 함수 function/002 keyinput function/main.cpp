/*
	keyinput function
*/

// library declaration
#include <stdio.h>

// function declaration
char keyinput();		
void keyshow(char input);

// main
void main(){
	char ch = keyinput();
	keyshow(ch);
}

// defining function
/**
	keyinput();
	using when input a key using scanf
	@return char user input character
*/
char keyinput(){
	char input_ch = 0;
	scanf("%c", &input_ch);
	return input_ch;
}

/**
	keyshow
	printing out input character
	@param character input
*/
void keyshow(char input){
	printf("------------------------\n");
	printf("input key = %c\n", input);
}