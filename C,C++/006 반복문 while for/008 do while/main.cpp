/*
	while (��������)
	{
		�۾�....
	}

---------------------------------------
	���ǰ� ������� �ϴ� �ѹ� ��������
	�׵ڿ� ���� �Ǵ�

	process one time before the condition check,
	and condition checking
	do
	{
		�۾�.....
	} while (��������) ;
*/

#include <stdio.h>
void main(){
	// 20 ���� 5���� -3�� ����
	int i = 20;
	do{
		printf("%d\n", i);		//���
		i -= 3;					//������
	} while (i>4);				//��������


}