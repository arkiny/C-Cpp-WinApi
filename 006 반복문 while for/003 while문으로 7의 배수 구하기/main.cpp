/*
	1���� 130���� �� �߿�
	7�� ����� ��ΰ�? ___

	while ���� Ȱ��]
*/

#include<stdio.h>
int main(){
	int i = 1;									// ���� ������ (0�� ����ó�� �ǹǷ� 1���� ����
	int check = 0;								// ����� ���� ó��
	int temp = -1;								// ������ ó��, -1�� �����ϴ� ������ ���� ����ó���� ����

	while (i <= 130){							// i�� 130���� ���� ���

		// ���⼭ ���������� ó���ϼ̰�, �̴� �ι��� ������μ��� ���
		//i % 7 == 0 ? check++ :
		//			printf("");							// do nothing

		temp = i % 7;							// ������ ����
		temp == 0 ?								// 7�� ����϶� ī��Ʈ ��
			check++ :							
			printf("");							// do nothing
		temp == 0 ?								// 7�� ����϶� ���
			printf("��� : %d\n", i) :
			printf("");							// do nothing
		i++;		
	}// end while

	printf("����� �� ���� : %d\n", check);
	getchar();
}