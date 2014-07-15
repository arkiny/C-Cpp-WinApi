/*
	�Լ� ������ ( Pointer Function )
	�Լ� �ȿ� �Ǵٸ� �Լ��� ������ �ִ�!

	void func()				��Դ� �Լ��� ��� // �޸𸮸� �Ҵ�, �ּҰ� ����

	void (*pfunc)()			��ȣ�� �߿�, �켱������ �� �Կ�����
							�Լ� �������̹Ƿ� �ٸ� �Լ��� �޾��ټ� ����

	�ڵ尡 Ŀ���� �����ϱ� ��������� �Ŵ����� ��������
	�Ŵ��� ������ ������ַ��� �Լ� �����͸� �˾ƾ� �Ѵ�.
*/

#include <stdio.h> // printf()

// prototype
void show();
void show1(int a);
int sum(int a, int b, void(*pf)(int));

// main
void main(){
	int k = 0;
	void (*pf)();								// �Լ� ������ ����

	// callback������ ���ϼ� �ִ� �Լ� ����
	int(*pf2)(int, int, void(*pf)(int));		// A pointer to contain a function which return int
	
	// ����Ÿ�� ���� �Ұ�, �Լ��� �ּҸ� ���K
	// pf = &k; 

	// pf��� �Լ� �����ʹ� show�� �ּҸ� ������ �ִ�.
	pf = show; 
	pf(); // printout "hello world" -> show�Լ� ��
	pf2 = sum;

	int c = pf2(4, 5, show1); // sum of two numbers

	// test print out
	printf("%d\n", c);
} // main()

// show
// printout hello world
void show()
{
	printf("Hello, World?\n");
} //show()

void show1(int a){
	printf("%d\n", a);
}

// sum of two numbers
// @param int a 
// @param int b
// @return int sum of a and b
int sum(int a, int b, void(*pf)(int)){
	pf(a + b);
	return a + b;
}// sum()