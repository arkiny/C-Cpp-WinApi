/*
	if ( ���� )
	{
		(��) ��1
	}
	else
	{
		(����) ��2
	}

	(����) ? (��) ��1 : (����) ��2
*/

/*
	���� �Է� : __

	�Է��� ���ڰ�		> 0 "���" ���
					< 0 "����" ���
					== 0  "0" ���
*/

#include<stdio.h>
int main(){
	// initialization
	int n_input = 0;

	// scan process
	printf("���� �Է� : ");
	scanf("%d", &n_input);
	
	// condition checking and printing
	if (n_input > 0){	// larger than 0
		printf("���\n");
	}	
	else {				// less than 0 or equal to 0
		if (n_input == 0){	// eqaul to 0
			printf("0\n");
		}
		else {				// less than 0
			printf("����\n");
		}
	} // end if
}