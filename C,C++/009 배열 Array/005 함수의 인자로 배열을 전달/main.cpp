/*
	@author		Heedong Arkiny Lee
	@date		07082014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	함수 ( 인자 - Parameter )

	- 값으로 전달
	- 주소로 전달
*/

#include <stdio.h> // printf()
#include <stdlib.h> // malloc(), free()
//#include <list>
//using namespace std;

// Prototypes
void show1(int nums[], int length);
void add1(int nums[], int length);
int* add2(int nums[], int length);

void main(){

	// Variable Initialization
	// Array for solution 1-*
	int nums[] = {7,5,8,4,6};
	int nums_length = sizeof(nums) / sizeof(int);
	// 2-2번 솔루션을 위한 초기화하지 않은 포인터
	int *dynamicarr; // uninitialized pointer for solution 2-1;

	// list container for solution 1-2
	//std::list<int> lNums(nums, nums + sizeof(nums) / sizeof(int));

	// Solutions
	// 1-1. nCount를 parameter에 적용한 방법
	// 장점 : 쉽고 직관적
	// 단점 : 쉽지만 안전하지 않은 방법 -> 배열의 사이즈가 매우 커지면 문제 발생
	// 문제는 지금까지 리서치에서 본 결과 C에서는 이 이상의 결과를 보기 힘들다는거..
	printf("Solution 1-1 : \n");
	show1(nums, nums_length);

	// 이하 Comment 리퍼런스
	// Reference	: Passing arrays to and from functions safely and securely
	// 참조			: 함수에서 배열을 무사하고 안전하게 옮기기
	// Link : http://www.cplusplus.com/forum/articles/20881/
	//
	// 1-2. C++ STL중 list의 Iterator를 적용한 방법
	// 는 현재 배우지 않았으므로 주석처리
	// 장점 : 무슨 타입의 데이타가 들어와도 안전하게 처리,
	// 단점 : Iterator가 인증되지 않은 형태이므로 널포인터나, 잘못된 포인터를
	//		사용할수 있음
	//show2(lNums.begin, lNums.end);

	// 1-3 C++ STL중 컨테이너를 먼저 연뒤에 펑션 안에서 Iterator를 이용하는 방법
	// 장점 : 어떤 타입이던간에 타입에 상관없이 처리 가능
	// 단점 : 컨테이너를 어떤 상황이든간에 모두 서치하므로 부분 검색 설정 불가
	// 1-2 보다는 안전하지만 제약이 많음
	//show3(lNums);

	// 2-1. 일반 For loop으로 계산한 방법
	// 일반적인 배열을 받아서 for문을 통해 더하는 방법
	// 직관적이어서 쓰기 편함...
	printf("Solution 2-1: \n");
	add1(nums, nums_length);

	// 2-2 Dynamic Array(포인터)를 이용해서 계산한 방법
	// Reference	: C and C++ Pass-By-Pointer
	// 참조			: C 와 C++ 포인터를 이용하여 넘기기
	// Link : http://www.dreamincode.net/forums/topic/206698-functions-in-c-and-c-part-ii-argument-passing-and-arrays/
	// 포인터를 이용하여 다이나믹 배열을 생성하여
	// For LOOP에서 계산하여 배열을 리턴...
	// 딱히 장점은 보이지 않으나(차후 배열 사이즈 조정에 유리하다함, 포인터 연습겸 해봄
	printf("Solution 2-2: \n");
	// 포인터는 add2에서 리턴된 포인터를 받음
	dynamicarr = add2(nums, nums_length);
	show1(nums, nums_length);

	// 메모리 얼로케이션 (직접 메모리 할당)을 통해 배열을 만들었으므로
	// 사용된 필요없는 메모리는 free 처리 (메모리 누수방지)
	free(dynamicarr);

	system("pause");
}

// 2. 함수 디자인 (정의)

// Solution 1-1
void show1(int nums[], int length){ // nums는 주소의 형태로 입력됨
	printf("nums = ");
	for (int i = 0; i < length; i++){
		printf("%d ", nums[i]);
	}
	printf("\n");
}

// Solution 1-2
//template<class ForwardIteratorType>
//void show2(ForwardIteratorType begin, ForwardIteratorType end){
//	printf("Solution 1-2 : \n");
//	while (begin != end){
//		printf("nums = %d\n", *begin);
//		++begin;
//	}
//}

// Solution 1-3
//template<class ContainerType>
//void show3(const ContainerType &container){
//	ContainerType::const_iterator current(container.begin()), end(container.end());
//	for (; current != end; ++current){
//		printf("nums = %d\n", *current);
//	}
//}

// Solution 2-1
void add1(int nums[], int length){
	printf("nums = ");
	for (int i = 0; i < length; i++){
		nums[i] += 3;
		printf("%d ", nums[i]);
	}
	printf("\n");
}

// Solution 2-2
int* add2(int nums[], int length){
	// 빈 포인터를 만들어서, 파라미터로 받은 인티져 어레이만큼의
	// 메모리를 할당
	int *ret_arr = (int *)malloc(sizeof(int)*length);

	// 더한 값을 위의 포인터 어레이에 저장
	for (int i = 0; i < length; ++i){
		ret_arr[i] = nums[i] + 3;
	}

	// 리턴, 여기서 리턴되는 건 포인터값
	return ret_arr;
}