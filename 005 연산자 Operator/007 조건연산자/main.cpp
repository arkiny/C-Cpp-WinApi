/*
	���� ������ ( ���� ������ )
	���� ? (��) ��1 : (����) ��2
*/

#include <stdio.h>
int main(){
	int A = 7, B = 3;
	int nResult = 0;
	
	nResult = A < B ? A : B; // ���� ����į ��������������
	printf("result = %d\n", nResult);

	/*
		scanf�� Ȱ���Ͽ�
		"�� ���� �Է� : __ __"
		�� ���� ū ���� ã�Ƴ���
	*/

	// input variables init
	int nA = 0, nB = 0;
	// result variables
	int nResult_Max = 0;

	// Scanning part
	printf("�� ���� �Է� : \n");
	scanf("%d %d", &nA, &nB); // ��巹���� �޴°� ���� ���� ����

	// Compute and return part
	nResult_Max = nA > nB ? nA : nB;
	printf("�� ū���� =  %d\n", nResult_Max);
	return 0;
}