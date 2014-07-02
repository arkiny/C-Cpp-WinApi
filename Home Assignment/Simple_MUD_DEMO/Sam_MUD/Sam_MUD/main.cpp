// @author	: Heedong Arkiny Lee
// @date	: 07032014
// @Git		: https://github.com/arkiny/SGA-Learning-Heedong

/*
	���� ]]

	#include <conio.h>
	kbhit() , getch()

	���ѷ���...
	{
	A, a �Է� -> "Attack~~~!"
	S, s �Է� -> "Stop~~~~!"

	Q, q �Է� -> ""
	1 �Է�


	x Ű �Է� -> ���α׷� ����
	��Ÿ �Է� -> �߸��� Ű �Է�
	}
*/

// I will make a MUD game which was my first online in my memory
// This game is a just concept, therefore I will skip the networking part
// ����� �� ���� MUD������ �ߴ� ģ���� ������ ���ƿͼ� ���� ���� ���� �迡 �ķ�� ����
// �� ù��° �¶��� �����̾��� �ﱹ������� �𸶷�(MUD)�� �߾��ϸ�....

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main(){
	// variable �ʱ�ȭ // Actually data table
	unsigned char input_key = 0;			// �÷��̾ �Է��� Ű ����
	int teemo_health = 460;					// Ƽ���� ���� ü��
	unsigned const int teemo_attack = 47;	// Ƽ���� ���ݷ�(���)
	int player_health = 200;				// �÷��̾� ü��
	unsigned int player_mana = 50;			// �÷��̾� ����
	unsigned const int a_skill = 100;		// �Ϲ� ���� ���ݷ�(���)
	unsigned const int q_skill = 150;		// q��ų ���ݷ� (���)
	unsigned const int w_skill = 130;		// w��ų ���ݷ� (���)
	unsigned const int e_skill = 120;		// e��ų ���ݷ� (���)
	unsigned const int r_skill = 300;		// r��ų ���ݷ� (���)
	unsigned const int one_item = 30;		// 1�� ������ ȿ�� (���)
	unsigned int one_item_num = 3;			// 1�� ������ ����
	unsigned const int two_item = 15;		// 2�� ������ ȿ�� (���)
	unsigned int two_item_num = 1;			// 2�� ������ ����


	// Give chance to skip intro
	printf("��Ʈ�� ��ŵ�� ���� sŰ�� �����ּ���\n");
	input_key = _getch();
	if (input_key == 0xE0 || input_key == 0) input_key = _getch();	// �ּҰ� check
	switch (input_key) {
	case 's':
		//skip
		break;
	default:
		// Intro Part, give motivation to player
		// Step and clear effect using pause and cls
		printf("\n\n\n\n\n����� ����Ͻʴϱ�?\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\nõ����, ������, ���촩�� ������ �ߴ�,\n");
		printf("MUD, multi user dugeon ���ӵ�����.,\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n���ʸ��� ¥�� �׷���ī�尡 �ƴ϶�,\n");
		printf("�ְ��� �׷���ī���� ����� ������ �̿��ߴ� �� ����,\n\n\n\n\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n��� ���Ͻðų� �𸣼ŵ� �˴ϴ�.\n");
		printf("���� ����� �� ������ �Ϻθ� �����ð� �˴ϴ�.\n\n\n\n\n");
		system("pause");
		system("cls");
		break;
	}
	



	while (input_key != 'x'){				// �÷��̾ �Է��� Ű�� x�� ��� ���� ����
		///////////////////////////////////////////////////////////////// Plaza
		printf("\n\n                              [ �� �� ]\n\n");
		printf("[ Player ] Lv 5, �߽�����\n\n");
		printf("������ ������� ���� ����� ������ ��ǰ �ŷ��� �ϴ� ���� ������ �����̴�.\n\n");
		printf("��(������ ����Ű)�ʿ��� �������� ���� ��� ���� ���� ���� ���δ�.\n");
		printf("��(���� ����Ű)�ʿ��� �������� ���δ�. ��� ��� �ȼ� �־�δ�.\n");
		printf("��(�Ʒ��� ����Ű)�ʿ��� �Ŵ��� ���� ���δ�. ���� ��� ������ ����.\n");
		printf("��(���� ����Ű)�ʿ��� ���� ���� ���δ�.\n");
		
		printf("\n ��[��] ��[��] ��[��] ��[��], ��ų �� ������ Ȯ��[i] ���� ����[x]\n");
		// �÷��̾� ��ɾ� �Է� 
		input_key = _getch();
		if (input_key == 0xE0 || input_key == 0 ) input_key = _getch();	// �ּҰ� check
		switch (input_key)
		{
		case 77 ://///////////////////////////////////////////////////// eastern forest
			system("cls");
			printf("\n\n �������� �̵��Ͽ���. \n");
			printf("\n\n                          [ ��ȯ���� ���� ]\n\n");
			printf("�� ���̾Ƹ��ó�� ���� �ǹ���� ��ž���� �þ �ִ�.\n");
			printf("������ ��� �񽺹Ǹ��� �͵��� ���� ���� ��򰡷� �̵��ϰ� �ִ�.\n");
			printf("\n�ֺ��� �ѷ����� �ִ� ��..\n\n �߻��� Ƽ�� ��Ÿ����!\n\n");
			
			system("pause");
			// battle phase
			if (teemo_health > 0){ // Ƽ�� ��������� ��������
				while (teemo_health > 0 && input_key!='x'){  
					// Ƽ�� ü���� ���ų�, �������� 'x' �Է½� Ż��	

					printf("\nƼ��(Lv 1) ���� ü�� : %d \n", teemo_health);
					printf("\nƼ�� : "" ^��^ �װ� �� ������ž�. ^��^ ""\n");
					printf("\nƼ�� �͵���ħ���� �����ؿɴϴ�.\n");

					// Ƽ��κ����� ����, �÷��̾� ����ü�� - Ƽ�� ���ݷ�
					player_health -= teemo_attack;
					if (player_health <= 0){ // �÷��̾� ü���� �ى�����
						printf("����� ü���� �ٴ��Ͽ� ���������ϴ�.\n");
						input_key = 'x';
						break; // �ݺ��� Ż��
					}
					else{// �÷��̾� ü���� �������� �ÿ� ���� ������ ���
						printf("����� ü���� %d ��ŭ �پ����ϴ�.\n", teemo_attack);
						printf("\n����� ���� ü�� : %d ", player_health);
						printf("����� ���� ���� : %d \n", player_mana);
						printf("\n����� �ൿ�� ���ϼ���. ����ĥ �� ���� �����ϴ�.\n");
						printf("�Ϲݰ���[a], �޽�[s], �转[q], �Ǿ[w], �����转[e], ���̳� ��Ʈ����ũ[r]\n");
						printf("ü�����ǻ��[1], �������ǻ��[2] ���� ����[x] \n");
						
						// �÷��̾� ��� �Է�
						input_key = _getch();
						if (input_key == 0xE0 || input_key == 0) input_key = _getch();
						switch (input_key)
						{
						case 97: // aŰ
							printf("\n����� ���� �ֵѷ� %d�� �������� Ƽ�� �����մϴ�.\n", a_skill);
							teemo_health -= a_skill;	// ���ݷ¿� ���� Ƽ�� ü�� ����
							break;
						case 115: // sŰ
							printf("\n����� �۶����� �ҷ��� ü��(%d)�� ȸ���մϴ�.\n", 10);
							player_health += 10;	// �÷��̾� ü��ȸ��
							printf("����� ���� ü�� : %d \n", player_health);
							break;
						case 113: // qŰ
							if (player_mana >= 20){	// ������ �̿��ϴ� ��ų�̹Ƿ� ���� üũ
								printf("\n�转!!!.\n");
								printf("����� ���� ������ �ֵѷ� %d�� �������� Ƽ�� �����մϴ�.\n", q_skill);
								printf("20�� ������ �Ҹ�Ǿ����ϴ�.\n");
								teemo_health -= q_skill;	// ���ݷ¿� ���� Ƽ�� ü�� ����
								player_mana -= 20;			// ���� ��뷮�� ���� ��������
							}
							else {	// ������ ������ 
								printf("\n������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 119: // wŰ
							if (player_mana >= 15){ // ������ �̿��ϴ� ��ų�̹Ƿ� ���� üũ
								printf("\n�Ǿ!!!.\n");
								printf("����� ���� ������ �� %d�� �������� Ƽ�� �����մϴ�.\n", w_skill);
								printf("15�� ������ �Ҹ�Ǿ����ϴ�.\n");
								teemo_health -= w_skill; // ���ݷ¿� ���� Ƽ�� ü�� ����
								player_mana -= 15;			// ���� ��뷮�� ���� ��������
							}
							else { // ���� ������
								printf("\n������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 101: // eŰ
							if (player_mana >= 30){ // ������ �̿��ϴ� ��ų�̹Ƿ� ���� üũ
								printf("\n���� �转!!!.\n");
								printf("����� ���� ������ �ֵѷ� �ֺ��� �繰�� �̿���\n %d�� �������� Ƽ�� �����մϴ�.\n", e_skill);
								printf("15�� ������ �Ҹ�Ǿ����ϴ�.\n");
								teemo_health -= e_skill; // ���ݷ¿� ���� Ƽ�� ü�� ����
								player_mana -= 30;			// ���� ��뷮�� ���� ��������
							}
							else {
								printf("\n������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 114: // rŰ
							if (player_mana >= 50){ // ������ �̿��ϴ� ��ų�̹Ƿ� ���� üũ
								printf("\n���̳� ��Ʈ����ũ!!!.\n");
								printf("����� �¸��� �⸦ �˿� ���\n %d�� �������� Ƽ�� �����մϴ�.\n", r_skill);
								printf("50�� ������ �Ҹ�Ǿ����ϴ�.\n");
								teemo_health -= r_skill; // ���ݷ¿� ���� Ƽ�� ü�� ����
								player_mana -= 50;			// ���� ��뷮�� ���� ��������
							}
							else { // ���� ������ 
								printf("\n������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 49: // 1Ű, ������ ���
							if (one_item_num >= 1){ // ������ ���� üũ
								printf("\n�ܲ��ܲ�, ����� ü�������� ���ʴϴ�.\n");
								printf("\n����� �ҷ��� ü��(%d)�� ȸ���մϴ�.\n", one_item);
								printf("\n���� ü������ ���� : %d��\n", one_item_num);
								one_item_num--;			// ���� ������ ���� ����
								player_health += one_item;	// ������ ȿ�ɿ� ���� ü��ȸ��
							}
							else{ // �ش� ������ ������
								printf("\nü�� ������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 50: // 2Ű
							if (two_item_num >= 1){ // ������ ���� üũ
								printf("\n�ܲ��ܲ�, ����� ���� ������ ���ʴϴ�.\n");
								printf("����� �ҷ��� ����(%d)�� ȸ���մϴ�.\n", two_item);
								printf("\n���� �������� ���� : %d��\n", two_item_num);
								two_item_num--;				// ���� ������ ���� ����
								player_mana += two_item;	// ������ ȿ�ɿ� ���� ���� ȸ��
							}
							else{ // �ش� ������ ������
								printf("\n���� ������ ���ڶ��ϴ�. ����� �׳� �۶����ϴ�.\n");
							}
							break;
						case 120: // ����Ű�� Ʈ���ŉ�����
							printf("\n���� Ű�� �����̽��ϴ�. ��¥�� �����Ͻðڽ��ϱ�?\n");
							printf("(y/n) : ");
							scanf("%c", &input_key);

							if (input_key == 'y'){  // ��Ȯ��
								input_key = 'x';
							}
							else {					// ���� Ȯ���� �ȉ��� ���
								input_key = 0;
							}
							break;
						default:
							printf("\n�߸��� Ű�� �Է��ϼ̽��ϴ�.\n");
							break;
						} // end switch						
					}
				}
				// �¸��� ����� ó��
				if (teemo_health <= 0){
					printf("Ƽ�� �����߷�����, �̳� ���� �����ٴ°� ���ݰ� �������� ���ư���� �մϴ�.\n");
				}
				else if (player_health <= 0) { // Game over(player �����)
					printf("Game over\n");
				}
				else{
					printf("�����߿� �����ϼ����Ƿ�, ���Ƽ�� �־�... ������ �����ϴ�.\n");// do nothing
				}
				}
				else{
					// �̹� Ƽ�� �����߷����� ó��
					printf("Ƽ�� �������ֽ��ϴ�.\n �̳� �Ұ� ���ٴ°� ���ݰ� �������� ���ư���� �մϴ�.\n");
				}
				system("pause");			
			break;
		////////////////////////////////////////////////// ���⼭���� �̿ϼ� �κ� �ܼ� �������̽� ó��
		case 75 : ////////////////////////////////////////////////////// western item mall(�̿�)
			system("cls");
			printf("\n\n �������� �̵��Ͽ���. \n");
			printf("\n\n                          [ ������ �Ա� ]\n\n");
			printf("�ɽ������� �������� ���� ���� ����̰� ������ ��� �ȳ��� �ϰ� �ִ�.\n");
			printf("\n����� : ����� �����ÿ� ���̶� �̿��� �Ұ����մϴ�. \n");

			printf("\n�������� ���ư���� �ߴ�. \n\n");		
			system("pause");
			system("cls");
			break;
		case 80 : /////////////////////////////////////////////////////// southern castle(����)
			system("cls");
			printf("\n\n �������� �̵��Ͽ���. \n");
			printf("\n\n                          [ ȫ���� ���̹� ]\n\n");
			printf("�� �̸��� ����. ���� ���� �� ��ü���� ���ݰ� �Ǿ���\n");
			printf("�׷��� �� ���̾��� ���̴�. ���̹ٳ� ����¡. \n\n");
			printf("�׷��� ���̹��� ������� ��� �̻����� �ϵ��ھ� �ߴ�. \n");
			printf("� ���⸦ Ż���ؾ� �ڴ�. \n\n");
			printf("PINK �� :  ""���� �� ������� ���԰����� ���� �� �ȵȴܴ�."" \n\n");
			
			system("pause");
			system("cls");

			// silence
			// ���� ������
			printf("...\n");
			system("pause");
			system("cls");
			printf("�� ����� ���ͳ� ������� �з����̸�,\n");
			printf("�� �Ҽ��ڿ� ���� ����, ���� �ǹ̷� ���ΰ��� �ƴմϴ�.\n");
			printf("���� �ƴϰ� ������ ���ϰ� �ߴٸ� ����帳�ϴ�.\n");
			printf("\n\nGame Over\n");
			input_key = 'x';
			break;
		case 72 : /////////////////////////////////////////////////////// northern mountain(�̿�)
			printf("\n\n �������� �̵��Ͽ���. \n");
			printf("\n\n                          [ �Ͼǻ� �Ա� ]\n\n");
			printf("������ ����̿� �а� ���� ����� ������ �ִ�.\n");
			printf("����� �ǳʴ� �ٸ��� ������ �ְ� �� �տ� �ȳ����� �����ִ�.\n");
			printf("\n���� : ����� �����ÿ� ���̶� �̿��� �Ұ����մϴ�. \n");

			printf("\n�������� ���ư���� �ߴ�. \n\n");
			system("pause");
			system("cls");
			break;
		case 105 ://///////////////////////////////////////////////////// skill check(��ų üũ)
			printf("\n[ ��ų Ȯ�� ]\n");
			printf("[q] - �转 (dmg: 150 mp: 20) \n");
			printf("[w] - �Ǿ (dmg: 130 mp: 15) \n");
			printf("[e] - �����转(����) (dmg: 120 mp: 30) \n");
			printf("[r] - ���̳� ��Ʈ����ũ (dmg: 300 mp: 50) \n");
			printf("1�� ������ - ü������ %d\n", one_item_num);
			printf("2�� ������ - �������� %d\n", two_item_num);
			system("pause");
			system("cls");
			break;
		///////////////////////////////////////////////////////////////// ���� �� ���� �ڵ鸵
		case 120 ://///////////////////////////////////////////////////// end game(���� ���� Ʈ����)
			printf("\n���� Ű�� �����̽��ϴ�. ��¥�� �����Ͻðڽ��ϱ�?\n");
			printf("(y/n) : ");
			scanf("%c", &input_key);

			if (input_key == 'y'){
				input_key = 'x';				
			}
			else {
				input_key = 0;
			}
			break;
		default://///////////////////////////////////////////////////// error handling(��Ÿ Ű�Է�)
			system("cls");
			printf("Ű������ ���� �ʾҽ��ϴ�. �ٽ� �Է����ּ���.\n");
			printf("�Է��� Ű = %d\n", input_key);
			system("pause");
			break;
		}
		


	}
	printf("\n������ �����մϴ�.\n");
	system("pause");
}

// ���� ���� ���Ƽ� �ϰ� ���� �����ð��� �� ���� �� ���� ���� ��ȸ�ҵ�...