/*
����ü enum
- enumerate
*/

#include <stdio.h> // printf()

// �߰����� �ٲ��൵ ���� ���� ������ ������
// ���� ���� �ٲ��.
enum week { Monday, Tuesday, Wednesday = 4, Thursday, Friday, Saturday, Sunday };

// �ڿ������� Weapon_max�� ���� ������� MAX���� ������ �ȴ�.
enum weapon{ MainWeapon, Secondary, Melee, explosive, Anti_tank, WEAPON_MAX };

// main()
void main(){
	int week[9] = {};
	week[Monday] = 21;
	week[Tuesday] = 22;
	week[Wednesday] = 23;
	//.....
	week[Sunday] = 27;

	// 
	int weapon[WEAPON_MAX];
	char *str[] = { "Rifle", "Desert Eagle", "Gurka", "M48", "RPG-7" };

	printf("���� ���� = %s\n", str[Secondary]);

} // main()