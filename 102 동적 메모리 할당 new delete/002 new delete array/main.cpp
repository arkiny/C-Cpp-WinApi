/*
	동적 배열을 만들고,
	pointer로 제어
*/

#include <iostream>
using namespace std;

void init(int *ptr);
void show(int *iptr);

void main(){
	/*int array[5] = {};
	int *ptr = array;*/

	// ptr에다가 1~5 대입
	// 포인터를 배열처럼 이용
	int *ptr = new int[5];


	init(ptr);
	show(ptr);

	delete(ptr);
	ptr = nullptr;

	/*
	2. cin 입력 __
		몇개의 적을 만들까요 ? __
		입력한 개수만큼 Enemy를 1부터 순차적으로 증가 초기화 생성
	*/

	/*void* pptr = nullptr;
	int *input2 = nullptr;

	CreateData(&pptr, input2, 5);
	cout << *(int*)(pptr+1) << end;*/
	// 동적으로 값을 만들어서 이용
	void* pt = nullptr; {
		int size = 0;
		cout << "얼마나 많은 적을 만들까요?" << endl;
		cin >> size;
		void *pt = new int[size];
		for (int i = 0; i < size; i++){
			// ((int*)pt)[i] = i + 1; 혹은 
			*((int*)pt+i) = i + 1;
		}
	}

	delete[](pt);
	pt = nullptr;
}


// 실험
void CreateData(void **ipptr, int *input, int size){
	*ipptr = new int[size];
	for (int i = 0; i < size; i++){
		*(int*)*(ipptr+i) = i+1;
	}
}

void init(int *iptr){
	for (int i = 0; i < 5; i++){
		*(iptr + i) = i + 1;
	}
}

void show(int *iptr){
	for (int i = 0; i < 5; i++){
		cout << *(iptr + i) << " ";
	}
	cout << endl;
}