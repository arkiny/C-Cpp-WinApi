/*
	�ݺ��� - for

	for ( ���۰� ; �������� ; ������ )
	{
		�۾� ...
	}
*/

#include <stdio.h>
void main(){
	// for���� Ȱ�� �Ͽ� 20���� 1���� -2�� ���� ���
	// for (������ ���� ; ����; ������){ ���� }
	for (int i = 20; i > 0; i -= 2){
		printf("%d\n", i);
	} //end for

	for (;;){
		//���ѷ���
		break;
	} // end for

	// while loopó�� for loop ����
	int n = 0;
	for (; n <= 10;){
		printf("1111\n");
		n++;
	} // end for

	while (1){
		//���ѷ���
		break;
	}	// end for


}