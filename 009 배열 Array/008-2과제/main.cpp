/*
	@author		Heedong Arkiny Lee
	@date		07092014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	int array[4];

	랜덤 범위 5~15까지 나오도록 ..
	array에 채우기

	RandomArray(array);
	ShowArray(array);

	그리고 Sorting....
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


	// 결과 출력
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

	printf("\nsolution4--ㅡmergeSort, O(nlogn)------------\n\n");
	showArray(mergeSortArray, SIZE);
	mergeSort(mergeSortArray, mergeSortWorkingArray, SIZE);
	showArray(mergeSortArray, SIZE);

	printf("\nsolution4--ㅡQuickSort, O(nlogn)------------\n\n");
	showArray(quckSortArray, SIZE);
	quickSort(quckSortArray, 0, SIZE-1);
	showArray(quckSortArray, SIZE);
	
	//메모리 누수 방지 
	free(array1);
	system("pause");
}

////////////////////////////////////////////////////////// In-Class Working
// using selection algorithm O(n^2) Using Two Array
// 수열 2개를 이용한 Selection Sort의 일종
// 수열에서 가장 작은 수를 구해서 리턴한뒤, 그자리에 나올수 있는 가장 큰 수를 집어넣고
// 리턴된 값은 새로운 수열에 추가한다.
// 고정된 O(n^2)의 프로세스 타임을 가짐
// 이건 수업시간에 마무리함
// 
// 오름차순 으로 정렬 하여 AscArray에 넣기
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
// 수열 하나와 Selection Sort알고리즘을 통해 만든 소트
// Selection Sort, Using one Array
// 역시나 2개의 For룹을 이용한다.
// N^2/2번의 비교과정과 N번의 교환과정을 거친다.
void selectionSort(int* input, int length){
	// 변수 초기화
	int min_index = -1;
	// 임의의 최고값으로 변수를 초기화한다.
	int min_num = 65535;
	for (int i = 0; i < length; i++){
		// 매번 돌때마다 최소값을 받을 변수는 초기화 되어야한다.
		min_num = 65535;
		// 두번째 for룹은 첫번째 for룹의 인덱스를 받아 그곳부터 시작된다.
		// 이미 가장 작은 수는 앞쪽부터 채워져 있기 때문에
		// 앞쪽은 다시 체크할 필요가 없기 때문이다.
		for (int j = i; j < length; j++){
			// 최소값(비교용)과 최소값 위치 확인(스왑용)
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
// 수열 하나와 InsertionSort 알고리즘을 통해 만든 정렬
// 두개의 루프를 이용하며,
// 최악의 경우 N^2/2 번의 비교와 N^2/2번의 교환과정을 거치며
// 최선의 경우 N-1번의 비교와 0번의 교환과정을 거치게 된다.
// 평균적으로 N^2/4번의 비교와 N^2/4번의 교환과정으로 거치기에
// 몇몇 케이스의 경우 selectionSort보다 빠름
void insertionSort(int* input, int length){
	// 사이사이를 비교하므로 최초의 루프는 1부터 시작한다.
	for (int i = 1; i < length; i++){
		// 교환과 비교를 위해 i인덱스를 변수에 지정한다.
		int x = input[i];
		// 두번째 루프는 i의 위치부터 시작한다.
		int j = i;
		// 사이사이를 비교하므로 j가 0보다 크면서
		// J의 앞 인덱스(위치에)있는 수와 비교시에 앞에 있는 수가 클경우
		// 자기자리와 바꿔준다.
		while (j>0 && input[j - 1] > x){
			input[j] = input[j - 1];
			j--;
		}//end while
		// 마지막으로 나왔을시 input[j]의 위치에 x를 치환
		input[j] = x;
	}//end for
}

//////////////////////////////////////////////////////////// Merge Sort
// 수열 두개와 MergeSort 중 TopDown(위로부터 쪼개는 방법)방식으로,
// 수열을 쪼개어 내려가서 2개의 구성요소(2개의 수열)까지 쪼개어,
// 두개의 수열을 합치며 비교하여 최종적으로 하나의 수열로 만드는
// 알고리즘. Divide and Conquer계열의 대표적인 알고리즘이라고 한다.
// 평균적으로 O(nlogn)번의 프로세스 타임을 가지며,
// 위의 두 알고리즘보다 비약적으로 빠른 프로세스타임을 가지고 있다.
void mergeSort(int* input, int* working, int length){
	// 수열을 쪼개기 위한 재귀함수로부터 알고리즘은 시작한다.
	TopDownSplit(input, working, 0, length);
}

//재귀 함수 TopDownSplit
//두개의 수열과 시작과 끝주소를 받아서 재귀를 통해 최소 단위로 쪼갠뒤
//합치는 작업을 통해 정렬한다.
void TopDownSplit(int* input, int* working, int lo, int hi){
	// Base Case : 구성요소가 2개일 경우 리턴
	if (hi - lo < 2){
		return;
	}
	// 중간 주소 찾기
	int mid = (hi + lo) / 2;
	// 절반으로 쪼개기
	// 중간부터 앞쪽을 계속 쪼개어 나간다.
	TopDownSplit(input, working, lo, mid);
	// 중간부터 뒤쪽을 계속 쪼개어 나간다.
	TopDownSplit(input, working, mid, hi);
	// 다 쪼개어졌을 시, 앞 중간 뒷값을 받아 합친다.
	TopDownMerge(input, working, lo, mid, hi);
	// 원본에 작업한 부분(시작, 끝) 값을 붙여넣는다.
	CopyArray(working, lo, hi, input);	
}

// 쪼개져 있는 두개의 서브어레이를 합치면서 비교, 정렬하는 함수
void TopDownMerge(int* input, int* working, int lo, int mid, int hi){
	// 시작주소, 앞쪽 Subarray의 값을 옮긴뒤에 앞쪽 subarray의 index를 옮길때 쓴다.
	int j = lo;
	// 중간주소, 뒤쪽 Subarray의 값을 옮긴뒤 뒤쪽 subarray의 index를 옮길때 쓴다.
	int k = mid;
	// 루프의 시작은 lo, 시작값부터, hi 마지막 index까지 (받은 값에서)
	for (int i = lo; i < hi; i++){
		// 앞쪽 서브리스트가 존재하고,
		// 뒤쪽 서브리스트가 존재하지 않거나, 앞쪽 서브리스트의 값이 더 작을때
		// 앞쪽 서브리스트를 머징하고, 앞쪽 서브리스트의 주소 이동
		if (j < mid && (k >= hi || input[j] <= input[k])){
			working[i] = input[j];
			j++;
		}
		// 그밖에는 뒤쪽 서브리스트를 머징하고 뒤쪽 서브리스트 주소 이동
		else{
			working[i] = input[k];
			k++;
		}			
	}
}


//////////////////////////////////////////////////////////// Quick Sort
// 수열 하나와 Divde and Conquer를 이용한 또다른 정렬 알고리즘
// 값을 하나 잡아서, 
// (그값보다 작은 수만 있는 수열 | pivot | 그 값보다 큰 수만 있는 수열)
// 을 만들고, 자신의 위치를 찾는다.
// 또다시 그 수열에서 값을 하나 잡아 두개로 나눠서 정렬해 나가는 정렬 알고리즘
// 평균적으로 O(nlogn)의 연산 시간을 가진다.
// 여담으로 이거 도대체 처음 생각해낸 사람은 천재인득.... 도대체 어떻게?
// 정렬은 일단 재귀 함수로 시작하며, 최소 주소와 최대 주소를 받는다.
void quickSort(int* input, int lo, int hi){
	// 최대주소가 최소주소보다 작거나 같아지면 (서브어레이가 최소값이 되면) 리턴
	if (hi <= lo) return;
	// 파티션 함수를 이용해 피봇 주소값을 찾아낸다.
	int j = partition(input, lo, hi);
	// 파티셔닝이 완료되면 서브어레이들이 최소값이 될때까지 파티셔닝을 실시한다.
	quickSort(input, lo, j - 1);
	quickSort(input, j + 1, hi);
}

// partition 함수는 quicksort의 헬퍼 메소드로,
// @param int lo 주소 최소값
// @param int hi 주소 최대값
// 을 받아서
// @return int 파티션 피봇을 완료한뒤 그 주소값을 리턴한다.
int partition(int* input, int lo, int hi){
	// 주소를 받기 위한 변수 초기화
	int i = lo;
	int j = hi+1;
	// 피봇(기준이 될 값)을 받는다.
	int v = input[lo];
	while (true){
		// 제일 낮은 주소부터 기준값보다 모든 값이 높을때를 찾는다
		// 이때 최대주소값이상으로 넘어가게 되면 중지한다.
		while (input[++i] < v)
			if (i == hi) break;
		// 반대로 제일 높은 주소부터 기준값보다 모든 값이 낮을때를 찾는다.
		// 이때 최소주소값이하로 떨어지게 되면 중지한다.
		while (v < input[--j])
			if (j == lo) break;
		// 두 주소값이 만나면 정지
		if (i >= j) break;
		// Swapping //.//
		int swap = input[i];
		input[i] = input[j];
		input[j] = swap;
	} // end while

	// 파티션이 된 자리를 찾았으므로, 그자리에 기준값을 집어넣고,
	int swap = input[lo];
	input[lo] = input[j];
	input[j] = swap;

	// 그 주소값을 반납한다.
	return j;
}


//////////////////////////////////////////////////////////// Helper Methods
// Random Array 생성함수
// @param	int length 랜덤으로 생성하려는 수배열의 길이
// @return	int* 랜덤으로 생성된 수열
int* RandomArray(int length){
	// 동적 포인터를 이용해 메모리 할당을 통한 리턴수열 생성
	int *pointer = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; ++i){
		pointer[i] = rand() % ((100 + 1) - 1) + 1;
	}
	return pointer;
}

// type secure에 상관없이 일단 딥카피 하는 펑션
// 일반적으로 = 를 통하여 카피하는 경우는 포인터를 그대로 가져가므로
// 딥카피를 통해 카피해야 같은 배열로 계속 실험 가능
void deepCopy(int* from, int* to, int length){
	for (int i = 0; i < length; i++){
		to[i] = from[i];
	}
}

// Array를 카피하는 다른 함수
// 정확하게 같은 길이의 수열을 받아서
// 시작과 끝 주소를 받아 해당부분만 수열에 넣는다.
void CopyArray(int* fromArray, int Begin, int End, int* toArray)
{
	for (int k = Begin; k < End; k++)
		toArray[k] = fromArray[k];
}

// 수열 출력
void showArray(int array[], int length){
	for (int i = 0; i < length; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}