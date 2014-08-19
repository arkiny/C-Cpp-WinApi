/*
	상수의 데이터 크기 (size of constant)
	- sizeof : 데이터의 크기를 byte로 반환 (return the size of data as byte)
	- 1byte = 8bit
*/

#include <stdio.h> // it is a library!!

int main(){
	//1. 정수의 크기 알아보기
	printf("정수 %d의 크기 = %d\n",51, sizeof(51));

	//2. 실수의 크기 알아보기 (3.14)
	printf("실수 %f의 크기 = %d\n", 3.14, sizeof(3.14));  // double
	printf("실수 %f의 크기 = %d\n", 3.14f, sizeof(3.14f)); // float

	//3. 단일 문자의 크기 ('i')
	printf("단일문자 %c의 크기 = %d\n", 'i', sizeof('i'));

	//4. 문자열의 크기 ("ai")
	//문자열의 끝에는 '\0'이 들어있고 이것은 Null문자를 뜻함
	//비어있는 문자로 문자열의 끝이라는 걸 표시한다칸다.
	printf("문자열 %s의 크기 = %d\n", "ai", sizeof("ai")); 

	return 0;
}