/*
	@author		Heedong Arkiny Lee
	@date		07092014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	int array[4];

	���� ���� 5~15���� �������� ..
	array�� ä���

	RandomArray(array);
	ShowArray(array);

	�׸��� Sorting....
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>

// Sort Prototype
int getMin(int* array, int length);
void AscendingArray(int* array, int* IncArray, int length);
void selectionSort(int* input, int length);
void insertionSort(int* input, int length);
void mergeSort(int* input, int* working, int length);
void TopDownSplit(int* input, int* working, int lo, int hi);
void TopDownMerge(int* input, int* working, int lo, int mid, int hi);
void quickSort(int* input, int lo, int hi);
int partition(int* input, int lo, int hi);

// Utility Prototype
void deepCopy(int* from, int* to, int length);
void CopyArray(int* B, int Begin, int End, int* A);
int* RandomArray(int length);
void showArray(int array[], int length);

// Main Function
void main(){
	// Random seed initialization
	srand((int)time(NULL));
	const int SIZE = 20;

	// variable initialization
	int* array1 = RandomArray(SIZE);
	int AscArray[SIZE] = {};
	int selectionSortArray[SIZE] = {};
	int insertionSortArray[SIZE] = {};
	int mergeSortArray[SIZE] = {};
	int mergeSortWorkingArray[SIZE] = {};
	int quckSortArray[SIZE] = {};
	deepCopy(array1, AscArray, SIZE);
	deepCopy(array1, selectionSortArray, SIZE);
	deepCopy(array1, insertionSortArray, SIZE);
	deepCopy(array1, mergeSortArray, SIZE);
	deepCopy(array1, quckSortArray, SIZE);


	// ��� ���
	printf("origin---------------------\n\n");
	showArray(array1, SIZE);

	printf("\nsolution1--In-Class Working, O(n^2)---------\n\n");
	showArray(AscArray, SIZE);
	AscendingArray(array1, AscArray, SIZE);
	showArray(AscArray, SIZE);

	printf("\nsolution2--SelectionSort, O(n^2)------------\n\n");
	
	showArray(selectionSortArray, SIZE);
	selectionSort(selectionSortArray, SIZE);
	showArray(selectionSortArray, SIZE);

	printf("\nsolution3--insertionSort, O(n^2)------------\n\n");
	showArray(insertionSortArray, SIZE);
	insertionSort(insertionSortArray, SIZE);
	showArray(insertionSortArray, SIZE);

	printf("\nsolution4--��mergeSort, O(nlogn)------------\n\n");
	showArray(mergeSortArray, SIZE);
	mergeSort(mergeSortArray, mergeSortWorkingArray, SIZE);
	showArray(mergeSortArray, SIZE);

	printf("\nsolution4--��QuickSort, O(nlogn)------------\n\n");
	showArray(quckSortArray, SIZE);
	quickSort(quckSortArray, 0, SIZE-1);
	showArray(quckSortArray, SIZE);
	
	//�޸� ���� ���� 
	free(array1);
	system("pause");
}

////////////////////////////////////////////////////////// In-Class Working
// using selection algorithm O(n^2) Using Two Array
// ���� 2���� �̿��� Selection Sort�� ����
// �������� ���� ���� ���� ���ؼ� �����ѵ�, ���ڸ��� ���ü� �ִ� ���� ū ���� ����ְ�
// ���ϵ� ���� ���ο� ������ �߰��Ѵ�.
// ������ O(n^2)�� ���μ��� Ÿ���� ����
// �̰� �����ð��� ��������
// 
// �������� ���� ���� �Ͽ� AscArray�� �ֱ�
void AscendingArray(int* array, int* AscArray, int length){
	for (int i = 0; i < length; i++){
		AscArray[i] = getMin(array, length);
	}
}

int getMin(int* array, int length){
	int min = 65535;
	for (int i = 0; i < length; i++){
		if (array[i] <= min){
			// swap
			int temp = min;
			min = array[i];
			array[i] = temp;
		}
	}
	return min;
}

//////////////////////////////////////////////////////////// Selection Sort
// ���� �ϳ��� Selection Sort�˰����� ���� ���� ��Ʈ
// Selection Sort, Using one Array
// ���ó� 2���� For���� �̿��Ѵ�.
// N^2/2���� �񱳰����� N���� ��ȯ������ ��ģ��.
void selectionSort(int* input, int length){
	// ���� �ʱ�ȭ
	int min_index = -1;
	// ������ �ְ����� ������ �ʱ�ȭ�Ѵ�.
	int min_num = 65535;
	for (int i = 0; i < length; i++){
		// �Ź� �������� �ּҰ��� ���� ������ �ʱ�ȭ �Ǿ���Ѵ�.
		min_num = 65535;
		// �ι�° for���� ù��° for���� �ε����� �޾� �װ����� ���۵ȴ�.
		// �̹� ���� ���� ���� ���ʺ��� ä���� �ֱ� ������
		// ������ �ٽ� üũ�� �ʿ䰡 ���� �����̴�.
		for (int j = i; j < length; j++){
			// �ּҰ�(�񱳿�)�� �ּҰ� ��ġ Ȯ��(���ҿ�)
			if (input[j] < min_num){
				min_num = input[j];
				min_index = j;
			}// end if
		}//end inner for
		// Swapping //.//
		int temp = input[i];
		input[i] = input[min_index];
		input[min_index] = temp;		
	}//end outher for
}

//////////////////////////////////////////////////////////// Insertion Sort
// ���� �ϳ��� InsertionSort �˰����� ���� ���� ����
// �ΰ��� ������ �̿��ϸ�,
// �־��� ��� N^2/2 ���� �񱳿� N^2/2���� ��ȯ������ ��ġ��
// �ּ��� ��� N-1���� �񱳿� 0���� ��ȯ������ ��ġ�� �ȴ�.
// ��������� N^2/4���� �񱳿� N^2/4���� ��ȯ�������� ��ġ�⿡
// ��� ���̽��� ��� selectionSort���� ����
void insertionSort(int* input, int length){
	// ���̻��̸� ���ϹǷ� ������ ������ 1���� �����Ѵ�.
	for (int i = 1; i < length; i++){
		// ��ȯ�� �񱳸� ���� i�ε����� ������ �����Ѵ�.
		int x = input[i];
		// �ι�° ������ i�� ��ġ���� �����Ѵ�.
		int j = i;
		// ���̻��̸� ���ϹǷ� j�� 0���� ũ�鼭
		// J�� �� �ε���(��ġ��)�ִ� ���� �񱳽ÿ� �տ� �ִ� ���� Ŭ���
		// �ڱ��ڸ��� �ٲ��ش�.
		while (j>0 && input[j - 1] > x){
			input[j] = input[j - 1];
			j--;
		}//end while
		// ���������� �������� input[j]�� ��ġ�� x�� ġȯ
		input[j] = x;
	}//end for
}

//////////////////////////////////////////////////////////// Merge Sort
// ���� �ΰ��� MergeSort �� TopDown(���κ��� �ɰ��� ���)�������,
// ������ �ɰ��� �������� 2���� �������(2���� ����)���� �ɰ���,
// �ΰ��� ������ ��ġ�� ���Ͽ� ���������� �ϳ��� ������ �����
// �˰���. Divide and Conquer�迭�� ��ǥ���� �˰����̶�� �Ѵ�.
// ��������� O(nlogn)���� ���μ��� Ÿ���� ������,
// ���� �� �˰��򺸴� ��������� ���� ���μ���Ÿ���� ������ �ִ�.
void mergeSort(int* input, int* working, int length){
	// ������ �ɰ��� ���� ����Լ��κ��� �˰����� �����Ѵ�.
	TopDownSplit(input, working, 0, length);
}

//��� �Լ� TopDownSplit
//�ΰ��� ������ ���۰� ���ּҸ� �޾Ƽ� ��͸� ���� �ּ� ������ �ɰ���
//��ġ�� �۾��� ���� �����Ѵ�.
void TopDownSplit(int* input, int* working, int lo, int hi){
	// Base Case : ������Ұ� 2���� ��� ����
	if (hi - lo < 2){
		return;
	}
	// �߰� �ּ� ã��
	int mid = (hi + lo) / 2;
	// �������� �ɰ���
	// �߰����� ������ ��� �ɰ��� ������.
	TopDownSplit(input, working, lo, mid);
	// �߰����� ������ ��� �ɰ��� ������.
	TopDownSplit(input, working, mid, hi);
	// �� �ɰ������� ��, �� �߰� �ް��� �޾� ��ģ��.
	TopDownMerge(input, working, lo, mid, hi);
	// ������ �۾��� �κ�(����, ��) ���� �ٿ��ִ´�.
	CopyArray(working, lo, hi, input);	
}

// �ɰ��� �ִ� �ΰ��� �����̸� ��ġ�鼭 ��, �����ϴ� �Լ�
void TopDownMerge(int* input, int* working, int lo, int mid, int hi){
	// �����ּ�, ���� Subarray�� ���� �ű�ڿ� ���� subarray�� index�� �ű涧 ����.
	int j = lo;
	// �߰��ּ�, ���� Subarray�� ���� �ű�� ���� subarray�� index�� �ű涧 ����.
	int k = mid;
	// ������ ������ lo, ���۰�����, hi ������ index���� (���� ������)
	for (int i = lo; i < hi; i++){
		// ���� ���긮��Ʈ�� �����ϰ�,
		// ���� ���긮��Ʈ�� �������� �ʰų�, ���� ���긮��Ʈ�� ���� �� ������
		// ���� ���긮��Ʈ�� ��¡�ϰ�, ���� ���긮��Ʈ�� �ּ� �̵�
		if (j < mid && (k >= hi || input[j] <= input[k])){
			working[i] = input[j];
			j++;
		}
		// �׹ۿ��� ���� ���긮��Ʈ�� ��¡�ϰ� ���� ���긮��Ʈ �ּ� �̵�
		else{
			working[i] = input[k];
			k++;
		}			
	}
}


//////////////////////////////////////////////////////////// Quick Sort
// ���� �ϳ��� Divde and Conquer�� �̿��� �Ǵٸ� ���� �˰���
// ���� �ϳ� ��Ƽ�, 
// (�װ����� ���� ���� �ִ� ���� | pivot | �� ������ ū ���� �ִ� ����)
// �� �����, �ڽ��� ��ġ�� ã�´�.
// �Ǵٽ� �� �������� ���� �ϳ� ��� �ΰ��� ������ ������ ������ ���� �˰���
// ��������� O(nlogn)�� ���� �ð��� ������.
// �������� �̰� ����ü ó�� �����س� ����� õ���ε�.... ����ü ���?
// ������ �ϴ� ��� �Լ��� �����ϸ�, �ּ� �ּҿ� �ִ� �ּҸ� �޴´�.
void quickSort(int* input, int lo, int hi){
	// �ִ��ּҰ� �ּ��ּҺ��� �۰ų� �������� (�����̰� �ּҰ��� �Ǹ�) ����
	if (hi <= lo) return;
	// ��Ƽ�� �Լ��� �̿��� �Ǻ� �ּҰ��� ã�Ƴ���.
	int j = partition(input, lo, hi);
	// ��Ƽ�Ŵ��� �Ϸ�Ǹ� �����̵��� �ּҰ��� �ɶ����� ��Ƽ�Ŵ��� �ǽ��Ѵ�.
	quickSort(input, lo, j - 1);
	quickSort(input, j + 1, hi);
}

// partition �Լ��� quicksort�� ���� �޼ҵ��,
// @param int lo �ּ� �ּҰ�
// @param int hi �ּ� �ִ밪
// �� �޾Ƽ�
// @return int ��Ƽ�� �Ǻ��� �Ϸ��ѵ� �� �ּҰ��� �����Ѵ�.
int partition(int* input, int lo, int hi){
	// �ּҸ� �ޱ� ���� ���� �ʱ�ȭ
	int i = lo;
	int j = hi+1;
	// �Ǻ�(������ �� ��)�� �޴´�.
	int v = input[lo];
	while (true){
		// ���� ���� �ּҺ��� ���ذ����� ��� ���� �������� ã�´�
		// �̶� �ִ��ּҰ��̻����� �Ѿ�� �Ǹ� �����Ѵ�.
		while (input[++i] < v)
			if (i == hi) break;
		// �ݴ�� ���� ���� �ּҺ��� ���ذ����� ��� ���� �������� ã�´�.
		// �̶� �ּ��ּҰ����Ϸ� �������� �Ǹ� �����Ѵ�.
		while (v < input[--j])
			if (j == lo) break;
		// �� �ּҰ��� ������ ����
		if (i >= j) break;
		// Swapping //.//
		int swap = input[i];
		input[i] = input[j];
		input[j] = swap;
	} // end while

	// ��Ƽ���� �� �ڸ��� ã�����Ƿ�, ���ڸ��� ���ذ��� ����ְ�,
	int swap = input[lo];
	input[lo] = input[j];
	input[j] = swap;

	// �� �ּҰ��� �ݳ��Ѵ�.
	return j;
}


//////////////////////////////////////////////////////////// Helper Methods
// Random Array �����Լ�
// @param	int length �������� �����Ϸ��� ���迭�� ����
// @return	int* �������� ������ ����
int* RandomArray(int length){
	// ���� �����͸� �̿��� �޸� �Ҵ��� ���� ���ϼ��� ����
	int *pointer = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; ++i){
		pointer[i] = rand() % ((100 + 1) - 1) + 1;
	}
	return pointer;
}

// type secure�� ������� �ϴ� ��ī�� �ϴ� ���
// �Ϲ������� = �� ���Ͽ� ī���ϴ� ���� �����͸� �״�� �������Ƿ�
// ��ī�Ǹ� ���� ī���ؾ� ���� �迭�� ��� ���� ����
void deepCopy(int* from, int* to, int length){
	for (int i = 0; i < length; i++){
		to[i] = from[i];
	}
}

// Array�� ī���ϴ� �ٸ� �Լ�
// ��Ȯ�ϰ� ���� ������ ������ �޾Ƽ�
// ���۰� �� �ּҸ� �޾� �ش�κи� ������ �ִ´�.
void CopyArray(int* fromArray, int Begin, int End, int* toArray)
{
	for (int k = Begin; k < End; k++)
		toArray[k] = fromArray[k];
}

// ���� ���
void showArray(int array[], int length){
	for (int i = 0; i < length; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}