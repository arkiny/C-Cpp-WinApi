/*
	���� �迭�� �����,
	pointer�� ����
*/

#include <iostream>
using namespace std;

void init(int *ptr);
void show(int *iptr);

void main(){
	/*int array[5] = {};
	int *ptr = array;*/

	// ptr���ٰ� 1~5 ����
	// �����͸� �迭ó�� �̿�
	int *ptr = new int[5];


	init(ptr);
	show(ptr);

	delete(ptr);
	ptr = nullptr;

	/*
	2. cin �Է� __
		��� ���� ������ ? __
		�Է��� ������ŭ Enemy�� 1���� ���������� ���� �ʱ�ȭ ����
	*/

	/*void* pptr = nullptr;
	int *input2 = nullptr;

	CreateData(&pptr, input2, 5);
	cout << *(int*)(pptr+1) << end;*/
	// �������� ���� ���� �̿�
	void* pt = nullptr; {
		int size = 0;
		cout << "�󸶳� ���� ���� ������?" << endl;
		cin >> size;
		void *pt = new int[size];
		for (int i = 0; i < size; i++){
			// ((int*)pt)[i] = i + 1; Ȥ�� 
			*((int*)pt+i) = i + 1;
		}
	}

	delete[](pt);
	pt = nullptr;
}


// ����
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