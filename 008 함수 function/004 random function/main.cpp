/*
	random �Լ�
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// function declaration
int RandomRange(int begin, int end);

// main function
void main(){
	
	// 1~6���� ���� ���� �߻��ϵ��� ������
	int nr = 0;
	int i = 0;

	srand(time(NULL));
	
	while (i < 10){
		printf("Random = %d \n", RandomRange(1,10));
		i++;
	} // end while
	//RandomRange( ����� ����� )

}

// Assume that seeding is already done
int RandomRange(int begin, int end){
	return rand() % (end-begin) + begin;
	// or (rand() % end) + begin
}

// ����
/*
	���� �ֻ��� �����
	1	-> 100c			60%
	2	-> 300 c		32
	3	->	5000 c		4
	4- >
*/