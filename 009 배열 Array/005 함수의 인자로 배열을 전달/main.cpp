/*
	@author		Heedong Arkiny Lee
	@date		07082014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	�Լ� ( ���� - Parameter )

	- ������ ����
	- �ּҷ� ����
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
	// 2-2�� �ַ���� ���� �ʱ�ȭ���� ���� ������
	int *dynamicarr; // uninitialized pointer for solution 2-1;

	// list container for solution 1-2
	//std::list<int> lNums(nums, nums + sizeof(nums) / sizeof(int));

	// Solutions
	// 1-1. nCount�� parameter�� ������ ���
	// ���� : ���� ������
	// ���� : ������ �������� ���� ��� -> �迭�� ����� �ſ� Ŀ���� ���� �߻�
	// ������ ���ݱ��� ����ġ���� �� ��� C������ �� �̻��� ����� ���� ����ٴ°�..
	printf("Solution 1-1 : \n");
	show1(nums, nums_length);

	// ���� Comment ���۷���
	// Reference	: Passing arrays to and from functions safely and securely
	// ����			: �Լ����� �迭�� �����ϰ� �����ϰ� �ű��
	// Link : http://www.cplusplus.com/forum/articles/20881/
	//
	// 1-2. C++ STL�� list�� Iterator�� ������ ���
	// �� ���� ����� �ʾ����Ƿ� �ּ�ó��
	// ���� : ���� Ÿ���� ����Ÿ�� ���͵� �����ϰ� ó��,
	// ���� : Iterator�� �������� ���� �����̹Ƿ� �������ͳ�, �߸��� �����͸�
	//		����Ҽ� ����
	//show2(lNums.begin, lNums.end);

	// 1-3 C++ STL�� �����̳ʸ� ���� ���ڿ� ��� �ȿ��� Iterator�� �̿��ϴ� ���
	// ���� : � Ÿ���̴����� Ÿ�Կ� ������� ó�� ����
	// ���� : �����̳ʸ� � ��Ȳ�̵簣�� ��� ��ġ�ϹǷ� �κ� �˻� ���� �Ұ�
	// 1-2 ���ٴ� ���������� ������ ����
	//show3(lNums);

	// 2-1. �Ϲ� For loop���� ����� ���
	// �Ϲ����� �迭�� �޾Ƽ� for���� ���� ���ϴ� ���
	// �������̾ ���� ����...
	printf("Solution 2-1: \n");
	add1(nums, nums_length);

	// 2-2 Dynamic Array(������)�� �̿��ؼ� ����� ���
	// Reference	: C and C++ Pass-By-Pointer
	// ����			: C �� C++ �����͸� �̿��Ͽ� �ѱ��
	// Link : http://www.dreamincode.net/forums/topic/206698-functions-in-c-and-c-part-ii-argument-passing-and-arrays/
	// �����͸� �̿��Ͽ� ���̳��� �迭�� �����Ͽ�
	// For LOOP���� ����Ͽ� �迭�� ����...
	// ���� ������ ������ ������(���� �迭 ������ ������ �����ϴ���, ������ ������ �غ�
	printf("Solution 2-2: \n");
	// �����ʹ� add2���� ���ϵ� �����͸� ����
	dynamicarr = add2(nums, nums_length);
	show1(nums, nums_length);

	// �޸� ������̼� (���� �޸� �Ҵ�)�� ���� �迭�� ��������Ƿ�
	// ���� �ʿ���� �޸𸮴� free ó�� (�޸� ��������)
	free(dynamicarr);

	system("pause");
}

// 2. �Լ� ������ (����)

// Solution 1-1
void show1(int nums[], int length){ // nums�� �ּ��� ���·� �Էµ�
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
	// �� �����͸� ����, �Ķ���ͷ� ���� ��Ƽ�� ��̸�ŭ��
	// �޸𸮸� �Ҵ�
	int *ret_arr = (int *)malloc(sizeof(int)*length);

	// ���� ���� ���� ������ ��̿� ����
	for (int i = 0; i < length; ++i){
		ret_arr[i] = nums[i] + 3;
	}

	// ����, ���⼭ ���ϵǴ� �� �����Ͱ�
	return ret_arr;
}