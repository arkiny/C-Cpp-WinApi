/*
	2�� �迭 ������
*/

#include <stdio.h>
// prototype
void show(int(*input2)[4], int x, int y);
void show2(int(*input)[4]);

// main
void main(){
	int table[3][4] = { 2, 4, 6, 8,
						1, 3, 5, 7,
						9, 7, 5, 3 };
	
	// ù��° ���� ���� �ּ�
	int* pt = table[0]; // 1�� �迭����, 2���迭���� ��ǻ�ʹ� ���� ��
	printf("%d\n", *pt);
	// ù�� �ι�° ���� ���
	printf("%d\n", *(pt+(4*0)+1));
	printf("%d\n", pt[7]);


	// 2���迭 2�� ������ ���·� �ޱ�
	table; // ((table+0)+0);
	int (*pt2)[4] = table; 
	// 2, 1�� ��ǥ
	printf("%d, %d = %d\n", 2, 1, *(*(pt2 + 2) + 1));
	printf("%d, %d = %d\n", 2, 1, pt2[2][1]);

	// �Լ��� �����
	show(pt2, 2, 3);

	// for�� ��ü ���
	show2(pt2);
} // main()

void show(int(*input)[4], int x, int y){
	printf("%d, %d = %d\n", x, y, input[x][y]);
} // show()

void show2(int(*input)[4]){
	// ���� ���¶� ���� �ڵ带 §��.
	// I am shitty a nerd and geek.
	// therefore, I coded like hentai kkkkk
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			//show(input, i, j);
			printf("%3d", *(*(input + i) + j));
		} // end inner for
		printf("\n");
	} // end outer for
}// show()