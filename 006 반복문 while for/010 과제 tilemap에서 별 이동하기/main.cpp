// There may be some way, but I could not find the way to get arrow key
// from the scanf function.
// ����� ���� ���ְ�����, ���� ����Ű�� scanf �Լ��� �̿��� �޴� ���� ã�Ƴ��� ���߽��ϴ�.
// Therefore, I googled some, and decide to use the getch() function which is in conio.h
// �׷���, ���۸��� �߰�, Dos�ܼ� ��ɾ� ���̺귯�� conio.h �� ���Ե� getch() 
// �Լ��� �̿��ϱ�� �����Ͽ����ϴ�.
// About getch() function, please refer the link below
// getch() �Լ��� ���ؼ��� �Ʒ��� ���۷����� ���� �ٶ��ϴ�.
// Ref) http://msdn.microsoft.com/en-us/library/078sfkak.aspx

#include<stdio.h>	// standard input/output library ǥ�� ����� ���̺귯��
#include<stdlib.h>	// For clear screen and pause screen, ȭ�� ���� �� ������ ���� ���̺귯��
#include<conio.h>	// library for DOS console ���� �ܼ�â�� ���� ���̺귯��

int main(){
	// ���� �ʱ�ȭ
	// Variable Initialization
	int cur_ver = 0, cur_hor = 0; // Variable for Current coordinator of the tile
	char input_key = 0; // To store input_key from user

	while (input_key != 27){	// While input_key is not 27 (Escape key)
		////////////////////////////////////////////////////////////////////////
		// Signature, �̸� ǥ��
		printf("Heedong Lee\n");
		printf("SGA 51A\n");
		printf("tileMap Coordination moving Home Assignment\n\n");
		printf("�׸� �η��� escŰ�� 2�� �����ּ���\n");
		// ���� �׸���
		for (int i = 0; i <= 8; i++){
			// ���� �׸���
			for (int j = 0; j <= 9; j++){
				if (i == cur_ver && j == cur_hor) {
					// �� �κ��� ����
					// Did some studpid stuff
					if (input_key == 72){
						printf("��");
					}
					if (input_key == 80){
						printf("��");
					}
					if (input_key == 75){
						printf("��");
					}
					if (input_key == 77){
						printf("��");
					}
					if (input_key != 72 && input_key != 80 && input_key != 75 && input_key != 77){
						printf("��");
					}
				}
				if (i != cur_ver || j != cur_hor) {
					printf("��");
				}
			} // end inner for
			printf("\n"); // ����
		} // end outer for
		////////////////////////////////////////////////////////////////////////


		// get key from the user
		_getch();
		input_key = _getch();	// �ѹ� ������ ���� ���� �ּ� ����
		// because arrow key has two byte address
		// we have to get rid of the front address using one more getch


		// ���� "else if"�� "else"�� �ȹ�����Ƿ�,
		// if���� �̿��� ��� ����� ���� ó����
		// we haven't yet learned "else if" or "else"
		// therefore we have to count all possibility in the condition			

		if (input_key == 72){ // �� ����Ű, up 
			if (cur_ver == 0){	// ���� �����ڸ��ε� �̵��Ϸ��� �Ҷ��� ó�� (border handling)
				printf("out of ceiling \n");
				system("pause");
			}	// endif
			if (cur_ver > 0){	
				cur_ver--;				
			}	// endif		
		}// endif
		if (input_key == 80){ // �Ʒ� ����Ű, down arrow
			if (cur_ver == 8){ // ���� �����ڸ��ε� �̵��Ϸ��� �Ҷ��� ó�� (border handling)
				printf("out of bottom\n");
				system("pause");
			}
			if (cur_ver < 8){	
				cur_ver++;
			}
		}

		// ���ó���� �ϴ� �ٸ� ���
		// Different way
		// �ϴ� �̵��� �ϰ�, �װ��� ��� ������ Ȯ���ϴ� ���
		// move first, and check border
		if (input_key == 75) {// left
			cur_hor--; // mover first
			if (cur_hor < 0){ // ���� �����ڸ��ε� �̵��Ϸ��� �Ҷ��� ó�� (border handling)
				cur_hor++; // reset the position
				printf("out of port border \n");
				system("pause");
			}
		}
		if (input_key == 77) {// right
			cur_hor++;
			if (cur_hor > 9){ // ���� �����ڸ��ε� �̵��Ϸ��� �Ҷ��� ó�� (border handling)
				cur_hor--;
				printf("out of starboard border \n");
				system("pause");
			}
		}
		//
		// Error handling part, usually do nothing
		// ������ else�� �̿���, error �ڵ鸵�� �ؾ��ϳ� ����
		//

		system("cls");		// ȭ�� ����
	}
}
