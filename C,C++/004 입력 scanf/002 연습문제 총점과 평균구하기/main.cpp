/*
	���â ]]

	���� ���� �Է� : __
	���� ���� �Է� : __
	���� ���� �Է� : __

	or

	��, ��, �� �Է� : __ __ __

	<<< ���� �� ��� ��� >>>

	���� = ???
	��� = ??? ( �Ҽ��� 2�ڸ� ���� ���)
*/

#include <stdio.h>
int main(){
	// variable initialization
	int korean = -1;
	int english = -1;
	int math = -1;
	int total = -1;
	float average = -1.0f;

	// input part
	printf("���â ]] \n");
	printf("���� ���� �Է� : \n");
	scanf("%d", &korean);
	printf("���� ���� �Է� : \n");
	scanf("%d", &english); 
	printf("���� ���� �Է� : \n");
	scanf("%d", &math);

	// error handling
	if (korean == -1 || english == -1 || math == -1){
		printf("����, ����, ������ �Ѱ����� �Է¾��ϼ̽��ϴ�.\n");
		return -1;
	}

	// result part
	printf("\n <<< ���� �� ��� ��� >>>\n\n");
	total = korean + english + math;
	printf("���� = %d\n", korean + english + math);
	average = (float) total / 3.0f ;
	printf("��� =  %.2f\n", average);

	return 0;
}