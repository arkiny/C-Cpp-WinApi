/*
	while - ������ ���
	�� �� ���(����� q) : __ (scanf)

	_  * 1 = ?
	*/

#include<stdio.h>
int main(){

	int q = -1;
	int n_input = -1;
	int i = 1;
	
	while (n_input != -2){
		n_input = -1;
		i = 1;
		printf("__ �� ��� (����� -2)\n�Է� : ");
		scanf("%d", &n_input);
		printf("\n");

		printf("%d ���� ��µ˴ϴ�.\n");
		while (i <= 9){ // i�� 9���� �������
			printf("%d * %d = %d\n", n_input, i, n_input*i);
			i++;
		}
		printf("\n");
	}

	return 0;
}

/*
while �� Ȱ��]
* 8�� �׸���
*
 *
  *
   *
    *
	 *
	  *
	   *
���� : H
���� : V
���� while �� Ȱ��.
*/