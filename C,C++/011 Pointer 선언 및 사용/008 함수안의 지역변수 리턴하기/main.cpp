/*
	�Լ� ������ ������ ������ ��ȯ

*/

#include <stdio.h> // printf(), scanf()
#include <conio.h> // _getch()

// main variable
// �ܺ� ����
//static char ch = 0;

// prototype

// Control
char keyInput();
int* LocalArray();

// main
void main(){
	char chkey = keyInput();
	printf("%c\n", chkey);

	// �� ó�� ���� �߳�����, ���� ���� ������ ���� ���´�
	int* parr = LocalArray();
	for (int i = 0; i < 5; i++){
		printf("%d\n", parr[i]);
	}

} // main()

// ���� ������ ���⶧���� ������ ������ �ִ�
// ������ ���縦 �ؼ� �� ���� ���� �ٺ����� ������ �ذ� �� ���� �ƴϴ�.
char keyInput(){
	char ch = 0;
	fflush(stdin);
	scanf("%c", &ch);
	return ch;
} // keyInput()

int* LocalArray(){
	// ���κ����� �ֹ߼� �����̱⶧���� ���� �������.
	// ���� static�� ���� �Լ��� ������ ���� �޸𸮰� �����ȴ�.
	// ���α׷��� �����Ҷ����� �޸𸮸� �����ϰ� �ȴ�.
	// ���� static�� �������� ����, ���Ŀ� �޸� ������ �Ҽ� �ִ� �Լ���
	// �ʿ��ϰ� �ȴ�.
	static int nums[] = { 11, 12, 13, 14, 15 };
	return nums;
} // LocalArray()

//// Ű�� ������ �� Ű�� ���� ����;
//// @return char ret pushed key
//char keyInput(){
//	char ret = 0;
//
//	// key���� �䰪(ȭ��ǥŰ ���)�� ������� return�� ����
//	ret = _getch();
//	if (ret == 0){
//		ret = _getch();
//	}
//	
//	return ret;
//} // keyInput()