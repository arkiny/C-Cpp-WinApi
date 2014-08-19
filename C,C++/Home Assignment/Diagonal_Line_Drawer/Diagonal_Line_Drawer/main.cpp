/*
@author : Heedong Lee (arkinylee@gmail.com)
@date : 06292014

	while �� Ȱ��
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

#include <stdio.h>
int main(){

	printf("SGA 51 - ����\n");
	printf("while���� �̿��Ͽ� �밢�� �׸���\n");
	printf("���� �ӵ� ���̿� ���� �ΰ��� ���\n");
	printf("�������� �ڵ忡 �޷��ִ� �ּ��� �������ֽñ� �ٶ��ϴ�.\n");


	// 1. ���۰�
	// 1. variable initialization
	// ������ 1�� �ƴ� 0���� �����մϴ�. (�� �κ��� �����̹Ƿ� 1���� �����ϼŵ� �����մϴ�.)
	// zero based index

	int i = 0;
	int j = 0;
	printf("\nUsing Solution 1 : Absolute O(n^2)\n");
	printf("1�� ��� : ������ n^2���� ó���� �ϴ� �ڵ�\n");

	// O(n^2)
	// ���� �ڵ�� ���� ������ �̿��� �ڵ��, ���� �ڵ庸�ٴ� �ణ �� ���μ���Ÿ���� ��ƸԴ� ����Դϴ�.
	// �ַ� ó���Ͻô� �е��� ���ǹ��� �ݺ����� ����� ���, �Ʒ��� ���� �ڵ带 �̿��մϴ�.
	while (i < 8){								// �ܰ��ݺ� ����(��)		Begin Outer loop (Row)

		j = 0;									// �� ��ݺ������� �� �ε��� �ʱ�ȭ
		// Re-initialization column index J for Every outer Loop

		while (j < 8){							// ���� �ݺ� ����(��)	Begin Inner loop (Column)
			// ���� �ڵ�� �ٸ����� ������ 8��° ������ �ݺ����� ����ȴٴ�
			// ���Դϴ�.
			i == j ? printf("*") : printf(" "); // ���� ����� ������ ���� ��� *�� ���, �ٸ� ��� ��ĭ ���
			j++;								// 3. �� ����			Column increment
		} // End inner while 

		printf("\n");							// ��ǥ ��� �� ����		Print Asterisk and move to newline
		i++;									// 3. �� ����			Row increment
	} // End outer while

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	// 1. ���۰�
	// 1. variable initialization
	// �̹� ������ ���� �������̹Ƿ�, �ٽ� �ʱ�ȭ�Ͽ� ����մϴ�.
	i = 0;
	j = 0;

	// 2. �������� (i�� 8�� ���ų� Ŀ���� �ݺ� ����)
	// 2. Looping and Printing
	// I think this will take O(nlogn) (... maybe)
	// If we learned array, I think we can decrease process time shorter, in my opinion.
	// However, in this time, we have not yet learned array and data structure, I just using two loops.
	// ���� �츮�� ����(Array)�� ����ٸ�,  ���μ��� Ÿ���� �� �� ���̴� ���(O(n))�� �����Ŷ�� �����մϴ�.
	// ������ �̹��� ���� �츮�� ������, ����Ÿ ������ ����� �ʾ����Ƿ�, 2���� �ݺ����� �̿��� �������
	// ���α׷��� ®���ϴ�.
	printf("Using Solution 2 : Faster than Previous Solution\n");
	printf("2�� ��� : �� �亸�� ���� ó���ӵ��� �ڵ�\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// �� �ڵ�� �ٸ����� �� ���� ��ȯ�������� ���̿��� �̷������,											//
	// �� �ڵ�� ������ ���� 8���� ���ڸ� ó���Ͽ� ��������� ( 8*8 = ��64��)								//
	// �� �ڵ�� 1+2+3+4+5+6+7+8 = 36 ���� ���ڸ��� ó���Ͽ�												//
	// ����մϴ�. �ڵ���� �������� ���� �ڵ��� ������ �����Ͻñ� �ٶ��ϴ�.									//
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	while (i < 8){								// �ܰ��ݺ� ����(��)		Begin Outer loop (Row)
											
		j = 0;									// �� ��ݺ������� �� �ε��� �ʱ�ȭ
												// Re-initialization column index J for Every outer Loop

		while (j < i){							// ���� �ݺ� ����(��)	Begin Inner loop (Column)
			printf(" ");						// �پ�� �߰�			Space added
			j++;								// 3. �� ����			Column increment
		} // End inner while 

		printf("*\n");							// ��ǥ ��� �� ����		Print Asterisk and move to newline
		i++;									// 3. �� ����			Row increment
	} // End outer while

		
	getchar();
	return 0;
}
