/*

*/

#include <stdio.h>
// prototype
void show1(int* input, int size);
void show2(int ArrayM[3][4]);
void show3(int(*ArrayM)[4]);

// main
void main(){
	const int size = 4;
	int ArrayS[] = { 7, 5, 4, 2 };

	// printout
	show1(ArrayS, size);

	//2차 수열의 경우 열부분은 확정을 지어줘야 한다
	// like this
	// ArrayM[][4] = { .. }
	int ArrayM[3][4] = {  11, 12, 13, 14,
						 21, 22, 23, 24,
						 31, 32, 33, 34  };
	show2(ArrayM);
	show3(ArrayM);
}

// print out input array to console
void show1(int* input, int size){
	for (int i = 0; i < size; i++){
		printf("%3d", *(input + i));
	}
	printf("\n");
}

// print out 2 dimensional array to console
void show2(int ArrayM[][4]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("%3d", ArrayM[i][j]);
		}
		printf("\n");
	}
}

// print out 2 dimensional array to console
void show3(int (*ArrayM)[4]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("%3d", ArrayM[i][j]);
		}
		printf("\n");
	}
}