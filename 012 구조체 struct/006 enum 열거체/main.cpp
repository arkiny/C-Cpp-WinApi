/*
열거체 enum
- enumerate
*/

#include <stdio.h> // printf()

// 중간값을 바꿔줘도 앞쪽 값은 변하지 않지만
// 이후 값은 바뀐다.
enum week { Monday, Tuesday, Wednesday = 4, Thursday, Friday, Saturday, Sunday };

// 자연스럽게 Weapon_max는 가진 무기수의 MAX값을 가지게 된다.
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

	printf("무기 종류 = %s\n", str[Secondary]);

} // main()