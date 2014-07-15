/*
	void�� ������
*/

#include <stdio.h>

void main(){
	char a = 3;
	int b = 7;
	float c = 7.89f;
	double d = -14.3;

	void* pa = &a;
	void* pb = &b;
	void* pd = &d;

	// �ֱٿ� �߰��� ����
	// �е� ���� ���� �߷��ؼ� ���ϴ� ������ ����ְ� ��
	// �ͽ��ؼ� ���⵵ �׷� �� (�߻�ȭ)
	// �츮�� �Ҷ��� �Ĺݺ� �������� ���� ������� ������ ��
	auto aa = &a;
	auto ab = &b;
	auto ac = &c;
	auto ad = &d;

	printf("%d\n", sizeof(pa)); // ����� 4�� ����
	printf("%d\n", sizeof(pd)); // ���� ����� 4�� ����

	printf("pa�� : %d\n", *((char*)pa)); // 3�� ����
	printf("pd�� : %f\n", *((double*)pd)); // -14.3�� ����

	
	printf("pd�� : %d\n", *aa); //3�� ����
	printf("pd�� : %d\n", *ab); //ab�� ����

}