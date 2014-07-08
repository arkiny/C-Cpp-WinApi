/*
	int array[4];
	
	랜덤 범위 5~15까지 나오도록 .. 
	array에 채우기

	RandomArray(array);
	ShowArray(array);
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>

int* ReverseArray1(int* array, int length);
int* RandomArray(int length);

void showArray(int array[], int length);
void ReverseArray(int array[], int RevArray[]);
int getMax(int* array);
void AscendingArray(int* array, int* IncArray);

void main(){
	srand((int)time(NULL));
	const int size = 4;
	int* array1 = RandomArray(size);	
	
	showArray(array1, size);

	int* RevArray = ReverseArray1(array1, size);
	showArray(RevArray, size);

	int AscArray[4] = {};
	AscendingArray(array1, AscArray);
	showArray(AscArray, size);
}

// using selection algorithm O(n^2)
// 오름차순 으로 정렬 하여 AscArray에 넣기
void AscendingArray(int* array, int* AscArray){
	for (int i = 0; i < 4; i++){
		AscArray[i] = getMax(array);
	}
}

int getMax(int* array){
	int max = 65535;
	int temp = 65535;
	for (int i = 0; i < 4; i++){
		if (array[i] <= max){
			temp = max;
			max = array[i];
			array[i] = temp;
		}
	}
	return max;
}


int* ReverseArray1(int array[], int length){
	int *ret = (int*)malloc(sizeof(ret)*sizeof(length));
	
	for (int i = 0; i < 4 ; i++){
		ret[i] = array[3-i];
	}
	
	return ret;
}

void ReverseArray(int array[], int RevArray[]){
	for (int i = 0; i < 4; i++){
		RevArray[i] = array[4 - i];
	}
}

void showArray(int array[], int length){
	for (int i = 0; i < length; ++i){
		printf("%d번 인덱스 : %d\n", i, array[i]);
	}
}

int* RandomArray(int length){
	
	int *pointer = (int*)malloc(sizeof(pointer)*sizeof(length));
	for (int i = 0; i < length; ++i){
		pointer[i] = rand() % ((15 + 1) - 5) + 5;
	}

	return pointer;
}

