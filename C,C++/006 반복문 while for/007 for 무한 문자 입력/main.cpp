/*
	���� ] ���� ���� �Է�

	for �� Ȱ�� ] ���� ���� ������

	'$' �� �ԷµǸ� ���� ����
	�ƴϸ�, ���� ���� ���鼭 ...
	�Է��� ���ڸ� ���

	]]

	�Է� : ____

	�Է��� ���� = ____

	�Է� :: ____

	...

	�Է� : $

	����...........
*/

#include <stdio.h>
int main(){
	// printout input char during infinite loop
	// ���ڸ� �޴� ���� ������ ������ �־�� �ҵ�
	// scanf should be in the loop expr
	// Variable Initialization
	char input = 0;
	for (int i = 0 ; i < 1; i){
		printf("\n�Է� : ");

		// flush. , stdin Ű���� �Է� ���� ��������
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		//scanf(" %c", &input);
		// ���� ������ �������� ������ ���� ���� �ϹǷ� break ��� �Ұ�
		// we cannot use 'break' command in the condition operator
		(input == '$') ? i++ : printf("�Է��� ���� = %c\n", input);
	} //end for

	// �������� ���� ���
	// $Ű �ƴϸ�, ���� ����
	// $Ű�� �ԷµǸ� ���� ����
	for (; input!= '$';){
		printf("\n�Է� : ");

		// flush. , stdin Ű���� �Է� ���� ��������
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		printf("�Է��� ���� = %c\n", input);
	} //end for

	// while �� �̿�
	while (input != '$'){
		printf("\n�Է� : ");

		// flush. , stdin Ű���� �Է� ���� ��������
		// flush the standard in keyboard input buffer
		fflush(stdin);
		scanf("%c", &input);

		printf("�Է��� ���� = %c\n", input);
	} //end while
}
