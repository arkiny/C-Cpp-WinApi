/*
	operators
	+ - * / %
*/

#include <stdio.h>

void main(){
	printf("tutorial for operators \n\n");
	
	int n1 = 111;
	int n2 = 32;

	// addition
	int n3 = n1 + n2;
	printf("%d + %d  =  %d\n", n1, n2, n3);
	
	// sub
	int n4 = n1 - n2;
	printf("%d - %d  =  %d\n", n1, n2, n4);

	// mult
	int n5 = n1 * n2;
	printf("%d * %d  =  %d\n", n1, n2, n5);

	// div
	// 형변환, Cast
	float n6 =   (float)n1 /  (float) n2;
	printf("%.2f / %.2f  =  %.2f\n", (float) n1, (float) n2, n6); // c 방식 casting
	printf("%.2f / %.2f  =  %.2f\n", float(n1), float(n2), n6);	// c++ 방식의 casting

	// mod
	// can only use int
	int n7 = n1 % n2;
	// two ways of express % symbol
	printf("%d %c %d  =  %d\n", n1, '%', n2, n7);
	printf("%d %% %d  =  %d\n", n1, n2, n7);	

	//int n8 = n1 % n2;
	//// two ways of express % symbol
	//printf("%d %% %d  =  %d\n",  n1,  n2,  n8);
}