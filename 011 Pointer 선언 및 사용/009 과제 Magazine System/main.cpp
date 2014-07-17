/*
	@author		Heedong Arkiny Lee
	@date		07152014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	���� ]]
		źâ �ý���.. (Magazine System)
		1. rifle	30					pfunc = rifle
		2. pistol	7					pfunc = pistol
		3. knife	infinite			...
		4. grenade	2					...

		r. reload

		�߻��ư.. Spacebar				pfunc = fire

		���� ������ ������ �Ѿ��� �Ҹ�

		�Լ� ������ Ȱ��
		tip] ź���� static or �迭 Ȱ��

		---------------------------------------------

		Function Pointer �� static �ɼ�, MVC ���Ͽ� ���ؼ� �����غ�...
		���� �� ���α׷������� static�� ���� �Լ� �ȿ� ���� �ʿ䰡 ����
		���� ������� �����Ǿ� �ֻ��� ������ ����°�....

		���� �ʿ��Ҽ��� �ְ�����...

		�ּ��� ���� �޲������� ����, ��κ� �����ð��� ��� �͵��̶� ���� �ʽ��ϴ�.
		�ð��� ���� �ɸ� ������ MVC ���� ���� Flowchart �׷�����

		�װ� �������� �ʹ� ���������� �����ϰ� �������...
		Flow��Ʈ�� ���������� ���� �ø�...
*/

#include <stdio.h>	// printf()
#include <conio.h>	// _getch()

// dataset
// ���� ���� ������ �̿��� ����Ÿ ����
static int ammo_stat[] = { 30, 9, 99, 2 };	// rifle , pistol , knife , granade
static int magazine[] = { 3, 2 };			// rifle , pistol

// prototype

// Main module
// �����ϰ��� �ϴ� ����� �ֻ��� �Լ�
void system_window_module();
void print_signature();

// model
// ���������� ���ӿ����� ���� �Լ���
void rifle();
void pistol();
void knife();
void grenade();
void reload(int current_weapon);

// control
// ������ Ű��Ʈ���� ����ϴ� �Լ�
char keyinput();

// view
// ȭ�� ����� ����ϴ� �Լ���
void interfaceRender_upside();
void effect_swap(int weapon);
void effect_reload_no_mag();
void effect_can_not_reload();
void effect_reload_complete(int magazine, int ammo);
void effect_need_reload();
void effect_no_grenade();

// main
void main(){
	print_signature();
	system_window_module();
} // main()

// �ý��� ������ ���
// ���ӳ����� �ý��� �� ȿ���� �ڸ��� ����ϴ� â
// ���� �ڸ� ����Ʈ�� �Ŵ�¡ �ϴ� ���ҵ� �Ѵ�...
// ���� MVC ���� ������ �����ϸ鼭 �ϴٰ� ����..
void system_window_module(){
	// â������ �ʿ��� �Լ��� �ʱ�ȭ
	char key = -1;
	// �⺻ ����� ������
	// ������ ���� ���� �κп��� ���� �ٷ����� �޾ƾ� ������
	// ���⼱ function pointer �� static ���� �����̹Ƿ� �׳� ��
	// default weapon = rifle
	void(*p_func)() = rifle;	// �⺻ �Լ��� rifle
	int current_weapon = 0;		// ���� ���� �ĺ���
	int flag = 0;				// ���� ���Ḧ ���� �÷��� ����

	// �������̽� ���
	interfaceRender_upside();

	
	// �̺κ��� ��Ʈ�ѷ� �־�� �ұ�?
	while (flag != 1){
		key = keyinput();
		switch (key)
		{
		case '1':
			p_func = rifle;				// �Լ� �����Ϳ� rifle �Լ� ����!
			current_weapon = 0;			// ���� ���� �ĺ��� 0
			effect_swap(0);				// ����ĺ� ������ �̿��� ��ȯ ����Ʈ(���� ����)
			break;
		case '2':
			p_func = pistol;			// �Լ� �����Ϳ� pistol �Լ� ����!
			current_weapon = 1;			// ���� ���� �ĺ��� 1(���� ����)
			effect_swap(1);				
			break;
		case '3':
			p_func = knife;				// �Լ� ������ p_func�� knife �Լ� ����!
			current_weapon = 2;
			effect_swap(2);
			break;
		case '4':
			p_func = grenade;			// �Լ� �����Ϳ� grenade �Լ� ����!
			current_weapon = 3;
			effect_swap(3);
			break;
		case ' ':
			p_func();					// ������ �Լ� �߽�! 
			break;
		case 'r':
			reload(current_weapon);		// ���� ����ĺ� ������ �̿��� ���� �ǽ�
			break;
		case 'x':
			flag = 1;					// ���� ���Ḧ ���� ���̽�
			break;
		default:
			break;
		}// end switch()
	}// end while()
}// system_window_module()

// ���� ���
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07152014 ����\n");
	printf("============================================================\n");
}

////////////////////////////////////////////////////////////////////// Model
// �������� ���μ����� �����ϴ� ���
// ���� �� ������ ��µǴ� ȿ���� ����Ѵ�
// @param int current_weapon ���� ���� �ĺ��� ����
void reload(int current_weapon){
	if (current_weapon == 0){	// ���� ���Ⱑ 0(������) �϶�
		if (magazine[0] > 0){	// ���� �Ѿ� �� Ȯ��
			ammo_stat[0] = 30;	// ������
			magazine[0] -= 1;	// źâ���� ����
			effect_reload_complete(magazine[0], ammo_stat[0]);	// �������� ����Ʈ ���
		}
		else {
			effect_reload_no_mag();	// źâ�� �������� ����Ʈ ���
		} // end inner if
	}
	else if (current_weapon == 1){	// ���� ���Ⱑ 1(����)�϶�
		if (magazine[1] > 0){		// ���� �Ѿ� �� Ȯ��
			ammo_stat[1] = 9;		// ������
			magazine[1] -= 1;		// źâ���� ����
			effect_reload_complete(ammo_stat[1], magazine[1]);	// ������ ����Ʈ ���
		}
		else {
			effect_reload_no_mag();	// źâ ������ ����Ʈ ���
		} // end inner if
	}
	else {
		effect_can_not_reload();	// �������� �Ұ����� ���⸦ ������ �ҽ��� ����Ʈ ���
	}// end outer iff
} // reload()

// M4A1 ���ݽ� ȿ���� ����Ʈ ���
// ��ź ���� ����
// ���� ȿ�� ���
void rifle(){
	if (ammo_stat[0] > 0){ // ��ź�� 0���� ������
		ammo_stat[0]--;	// ��ź ���ڰ���
		printf("ȿ���� : (������ ��� �Ҹ�) �߽� ����\n"); // ȿ�� ���
		printf("System : ������ ��ź - %d\n", ammo_stat[0]);	// ��ź ���� ���
	}
	else{
		effect_need_reload();	// ������ �ʿ�� ���
	} // end if
} // rifle()

// Pistol ���ݽ� ȿ���� ����Ʈ ���
// ��ź ���� ����
// ���� ȿ�� ���
void pistol(){
	if (ammo_stat[1] > 0){ // ��ź�� 0���� ������
		ammo_stat[1]--; // ��ź ���� ����
		printf("ȿ���� : (���� ��� �Ҹ�) �߽� ���߻���\n"); // ȿ�� ���
		printf("System : ���� ��ź - %d\n", ammo_stat[1]);  // ��ź ���� ���
	}
	else {
		effect_need_reload(); // ������ �ʿ�� ���
	} // end if
}  // pistol()

// ����� ������ źâ�̹Ƿ� �����ϰ� ��¸� �Ѵ�.
void knife(){	
	printf("ȿ���� : (�ֵθ��� �Ҹ�) ����\n");	
}

// ����ź �Լ��� �݉����� ȿ���� ����Ʈ ���
void grenade(){
	if (ammo_stat[3] > 0){
		ammo_stat[3]--;	// ����ź ��ź ���� ����
		printf("Player : ���� ����ź!\n");		// ȿ�� ���
		printf("System : ����ź ��ź - %d\n", ammo_stat[3]); // ��ź ���� ���
	}
	else {
		effect_no_grenade();  // ����ź�� ������ ���
	} // end if()
}  // grenade()


////////////////////////////////////////////////////////////////////// View
// ����ź�� ������ ���
// ����ź�� �⺻������ �������� ����
void effect_no_grenade(){
	printf("ȿ���� : (����� �ϴ� �Ҹ�)");
	printf("Player : ����ź�� �����ϴ�.");
}

// �������� �ǽ��Ҷ� �����
void effect_need_reload(){
	printf("ȿ���� : (��Ƽ谡 ������ ������� �Ҹ�) ƽƽ\n");
	printf("System : �������� �ʿ��մϴ�.\n");
} // effect_need_reload()

// ȭ�� �������̽� ���� ������ ����ϱ� ���� �κ�
void interfaceRender_upside(){
	printf("1. M4A1 | 2. Desert Eagle | 3. Knife | 4. Grenade\n");
	printf("r. reload | x. module stop\n\n");
	printf("System Msg ��\n");
	printf("����������������������������������������������������������\n");
} //interfaceRender_upside()

// �� ���⸦ ������ ����Ʈ�� ǥ��
// @param int weapon ���� ���� �ĺ��� ����
void effect_swap(int weapon){
	switch (weapon)
	{
	case 0:
		printf("\nM4A1�� ����������ϴ�\n");
		break;
	case 1:
		printf("\nDersert Eagle�� ����������ϴ�\n");
		break;
	case 2:
		printf("\nM50 ����� ����������ϴ�\n");
		break;
	case 3:
		printf("\n����ź�� ����������ϴ�.\n");
		break;
	default:
		break;
	} // end switch
} // effect_swap()

// źâ�� �����Ҷ� ����Ʈ�� ǥ��
void effect_reload_no_mag(){
	printf("Player : źâ�� ������..\n");
} // effect_reload_no_mag()

// �������� ǥ��
void effect_reload_complete(int magazine, int ammo){
	printf("ȿ���� : (źâ�� ���� ����� �Ҹ�) ö��\n");
	printf("System : ������ �Ϸ�, ���� źâ : %d, ��ź : %d\n", magazine, ammo);
} // effect_reload_complete()

// ����ź ���� �������� �Ұ����Ҷ��� ǥ��
void effect_can_not_reload(){
	printf("System : �� ���� �������� �Ұ����մϴ�.\n");
} // effect_can_not_reload()


////////////////////////////////////////////////////////////////////// Control
// ������ Ű�� �Է������� Ű�� �м��ϰ� char�� ����
// @return char input �÷��̾ �Է��� ĳ����
char keyinput(){
	char input = _getch();
	if (input == 0) {
		input = _getch();
	}
	return input;
} // input;