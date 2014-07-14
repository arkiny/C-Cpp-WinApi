/*
@author		Heedong Arkiny Lee
@date		07142014
@git		https://github.com/arkiny/SGA-Learning-Heedong

// °úÁ¦¿¡¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä¤Ä

¿ùµåÄÅ ¿ì½Â.... ÀÎÁ¤ÇÒ ¼ö ¾ø´Ù..

º»ÀÎÀÇ ¸®±×¸¦ ´Ù½ÃÇÑ¹ø ¸¸µé±â
char *pstr[4] = {};

ÆÀ 16°³, ·£´ý ¹èÁ¤

1¶ó¿îµå [] [] [] [] [] [] [] []			char* pQuarterFinal[8]
2¶ó¿îµå   []    []   []    []				char* SemiFinal[4]
3¶ó¿îµå       []       []					char* Final[2]
°á½Â              []						char* pWinner
*/

/*
Design
main(){
	mainÀº ÃÖ¼ÒÈ­
	ÃÖÃÊ Ãâ·Â°ú
	µ¥ÀÌÅ¸ ÀÌµ¿¸¸ ½Ç½Ã
	????Â÷ÈÄ¿¡ µ¥ÀÌÅ¸ ÀÌµ¿¸¸À» À§ÇÑ ÇÔ¼ö¸¦ Á¤ÀÇÇÒ¼ö ÀÖÀ»±î????
}

Controller(){
	¸¸¾à ½ÇÁúÀûÀ¸·Î r¸¦ ÅëÇØ¼­ ¹Ýº¹ÇÒ °æ¿ì ¸ÞÀÎ¿¡¼­ °ÔÀÓºÎºÐÀ»
	»©¿Í¼­ ³ÖÀ»¼ö ÀÖ°ÚÁö¸¸... ¿À´ÃÀº ¿©±â¼­ »ý·«
}

Model(¹®ÀÚ¿­, ¹®ÀÚ¿­){
	¹®ÀÚ¿­À» ¹Þ¾Æ¼­, ÇØ´ç ¹®ÀÚ¿­ÀÇ ±æÀÌÀÇ Àý¹Ý¸¸Å­ 
	µÎÆÀ³¢¸® ¹­¾î¼­ ·£´ýÀ¸·Î »Ì¾Æ µ¹·ÁÁÜ
}

view(Çà·Ä, Ãâ·Â°¹¼ö){
	ÀÎÅÍÆäÀÌ½º Ãâ·Â
	ÀÎÅÍÆäÀÌ½º´Â Çà·Ä°ú ±× °¹¼ö¸¦ ¹Þ¾Æ¼­ ¼øÂ÷´ë·Î Ãâ·ÂÇÑ´Ù
	???? »ê¼ú°è»êÀ¸·Î \t °³¼ö¸¦ Ã³¸®ÇÒ¼ö ÀÖÀ»±î ????
	ex) 8°­¿¡¼± \t 1¹ø, 4°­¿¡¼± \t 2¹ø, °á½Â¿¡¼± \t 4¹ø
		¿ì½ÂÀÚ´Â\t 8¹ø Ã³¸®ÇØ¾ßÇÏ·Á³ª?
	(ÀÏ´Ü ÇØ´çºÎºÐ »ý·«)
}
*/


#include <stdio.h> // printf()
#include <stdlib.h> // srand(), rand(), system()
#include <time.h> // time()

// Prototype
// Engine
void quarterFinalGame(char** inputArray, char** outputArray);
void semifinalGame(char** inputArray, char** outputArray);
void finalGame(char** inputArray, char** outputString);
void randomize(char* input[], char* output[], int size);

// View
void toString(char** input, int size);
void print_signature();

// Main Function
void main(){
	// º¯¼ö ÃÊ±âÈ­
	// Initialize the Country names
	// Initial DataBase
	char* pQuarterFinal[8] = { "Brazil", "Germany", 
								"France", "Spain",
								"Korea", "U.S.A", 
								"Ghana", "Argentina" };
	char* pSemiFinal[4] = {};
	char* pFinal[2] = {};
	char* pWinner[1] = {};
	
	// ·£´ý ½Ãµå ÃÊ±âÈ­
	// Seeding the random function
	srand(time(NULL));

	// Interface Initialization
	print_signature();
	toString(pQuarterFinal, 8);

	// Game Engine :D
	// °ÔÀÓ ½ÇÇà ºÎºÐÀÌ ½ÇÁúÀûÀÎ Ãâ·Â±îÁö ´ã´ç
	quarterFinalGame(pQuarterFinal, pSemiFinal);
	semifinalGame(pSemiFinal, pFinal);
	finalGame(pFinal, pWinner);

	system("pause");
} // main()

// 8°­ °æ±â ½Ç½Ã
// ´ÙÀ½ °æ±â·Î °ªÀ» ³Ñ°ÜÁÖ±â À§ÇØ output parameter¿ª½Ã °¡Áö°í ÀÖ¾î¾ß ÇÑ´Ù.
// @param char** inputArray		ÀÔ·Â¹ÞÀº ±¹°¡ ¹®ÀÚ¿­(8°³)
// @param char** outputArray	µ¹·ÁÁÙ ±¹°¡ ¹®ÀÚ¿­(4°³)
void quarterFinalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 4);	
	toString(outputArray, 4);
} // quarterFinalGame()

// ÁØ°á½Â °æ±â ½Ç½Ã
// ´ÙÀ½ °æ±â·Î °ªÀ» ³Ñ°ÜÁÖ±â À§ÇØ output parameter¿ª½Ã °¡Áö°í ÀÖ¾î¾ß ÇÑ´Ù.
// @param char** inputArray		ÀÔ·Â¹ÞÀº ±¹°¡ ¹®ÀÚ¿­(4°³)
// @param char** outputArray	µ¹·ÁÁÙ ±¹°¡ ¹®ÀÚ¿­(2°³)
void semifinalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 2);
	toString(outputArray, 2);
} // semifinalGame()

// °á½Â °æ±â ½Ç½Ã
// ´ÙÀ½ °æ±â·Î °ªÀ» ³Ñ°ÜÁÖ±â À§ÇØ output parameter¿ª½Ã °¡Áö°í ÀÖ¾î¾ß ÇÑ´Ù.
// ÀÏ¹Ý ¹®ÀÚ¿­·Î output°ªÀ» °¡Áú¼öµµ ÀÖÀ¸³ª, ÇÔ¼öÀÇ ÅëÀÏ¼ºÀ» À§ÇØ ¹è¿­ Çü½ÄÀ¸·Î
// µ¹·ÁÁÖ±â·Î °áÁ¤
// @param char** inputArray		ÀÔ·Â¹ÞÀº ±¹°¡ ¹®ÀÚ¿­(2°³)
// @param char** outputArray	µ¹·ÁÁÙ ±¹°¡ ¹®ÀÚ¿­(1°³)
void finalGame(char** inputArray, char** outputArray){
	randomize(inputArray, outputArray, 1);
	toString(outputArray, 1);
} // finalGame()

// Çö °ÔÀÓÀÇ ÇÙ½ÉºÎºÐ
// ¹è¿­°ú µ¹·ÁÁÙ »çÀÌÁî¸¦ ¹Þ¾Æ, ¾Æ¿ôÇ² ¹è¿­¿¡ ¸ÂÃß¾î µ¹·ÁÁØ´Ù.
// ¹«Á¶°Ç °æ±â´Â ¾Õ¿¡¼­ ºÎÅÍ ¼ø¼­´ë·Î 2ÆÀ¾¿ Àß¶ó¼­ ½Ç½ÃÇÏ¸ç,
// µû¶ó¼­ ¿ì¸®°¡ ¹ÞÀ» ¼ö ÀÖ´Â ¹è¿­ ÁÖ¼Ò°ªÀº
// µ¹·ÁÁÙ »çÀÌÁî´Â ¹«Á¶°Ç Àü ¹è¿­ÀÇ 1/2ÀÌ¹Ç·Î,
// ·£´ý°ª % 2 + (2 * i)°¡ µÈ´Ù. (2ÆÀÁß ÇÑÆÀ¸¸ ¿Ã¶ó°¡¹Ç·Î)
// @param char* input[] °æ±â¸¦ ½Ç½ÃÇÒ ¹®ÀÚ¿­
// @param char* output[] °æ±â °á°ú¸¦ ÀÔ·ÂÇÒ ¹®ÀÚ¿­
// @param int size °æ±â °á°ú°ªÀÌ ÀÔ·ÂµÉ outputÀÇ »çÀÌÁî
// @warning ouput.length()´Â input.length()ÀÇ 1/2»çÀÌÁî¿©¾ß ÇÑ´Ù.
void randomize(char* input[], char* output[], int size){
	int pick = 0;
	for (int i = 0; i < size; ++i){
		pick = rand() % 2 + (2 * i);
		output[i] = input[pick];
	}
}

// Ãâ·Â Ã³¸®´Â ÀÌ°÷¿¡¼­ ¸ðµÎ Ã³¸®ÇÑ´Ù.
// @param char*input[] Ãâ·ÂÇÒ ¹®ÀÚ¿­
// @param int size	Ãâ·ÂÇÒ ¹®ÀÚ¿­ÀÇ »çÀÌÁî
void toString(char* input[], int size){
	switch (size)
	{
	case 8:
		printf("== 8°­ °æ±â == \n", size);
		break;
	case 4:
		printf("== ÁØ°á½Â °æ±â == \n", size);
		break;
	case 2:
		printf("== °á½Â °æ±â == \n", size);
		break;
	case 1:
		printf("== °á½Â °æ±â °á°ú == \n", size);
		break;
	default:
		break;
	} // end switch

	for (int i = 0; i < size; i++){
		// 2ÆÀ¸¶´Ù vs¸¦ ºÙ¿©¾ß ÇÏ¹Ç·Î, ÁÖ¼Ò°ªÀÇ ³ª¸ÓÁö°¡ 1ÀÌ µÉ¶§, vs Ãâ·Â
		if (i % 2 == 1){ 
			printf(" vs ");
		}
		else{
			// ¾Æ´Ò¶© ±×³É Ä­ ³ª´©±â¿ë ºÎÈ£ Ãâ·Â
			printf("£ü");
		}
		printf("%s", input[i]);
	} // end for

	printf("£ü\n\n");
}

// ¼­¸í Ãâ·Â
void print_signature(){
	printf("ÀÌÈñµ¿\n");
	printf("SGA51A\n");
	printf("07142014 °úÁ¦\n");
	printf("============================================================\n");
	printf("2120³â ÇÑ±¹ ¿ùµåÄÅ °á°ú - (½ÇÇàÇÒ¶§¸¶´Ù °á°ú°¡ ¹Ù²ò´Ï´Ù)\n\n");
}