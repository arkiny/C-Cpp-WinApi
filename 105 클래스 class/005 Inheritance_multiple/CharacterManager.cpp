#include <iostream>
#include "CharacterManager.h"
using std::cin;
using std::cout;
using std::endl;


CharacterManager::CharacterManager()
{
	vCharData.resize(0);
	vCharData.shrink_to_fit();
}

CharacterManager::~CharacterManager()
{
	void *ptr = nullptr;
	for (int i = 0; i < vCharData.size(); i++){
		ptr = vCharData.back();
		delete ptr;
		vCharData.pop_back();
	}
	ptr = nullptr;
	vCharData.resize(0);
	vCharData.shrink_to_fit();
}

bool CharacterManager::addCharacter(){
	string b_name = "";
	int b_Physical = -1;
	int b_Leadership = -1;
	int b_Intelligence = -1;
	char re = 0;

	character *p_ch = nullptr;
	p_ch = new character();
	
	cout << "신규장수 이름 : "; 
	cin >> b_name;
	cout << "무력(0~inf) : "; 
	cin >> b_Physical;
	cout << "통솔(0~inf) : "; 
	cin >> b_Leadership;
	cout << "지력(0~inf) : "; 
	cin >> b_Intelligence;
	if (b_Physical < 0 || b_Leadership < 0 || b_Intelligence < 0){
		cout << "입력하신 수치가 형식에 일치하지 않습니다." << endl;
		cout << "다시 입력해주세요." << endl;
		delete p_ch;
		p_ch = nullptr;
		system("pause");
		cin.clear();
		return true;
	}

	p_ch->setName(b_name);
	p_ch->setPhysical(b_Physical);
	p_ch->setLeadership(b_Leadership);
	p_ch->setIQ(b_Intelligence);

	vCharData.push_back(p_ch);
	p_ch = nullptr;
	cout << "더 입력하시겠습니까?(y/n)"; cin >> re;
	return re == 'y' || re == 'Y';
}

void CharacterManager::showAll(){
	for (unsigned int i = 0; i < vCharData.size(); i++){
		vCharData.at(i)->show();
	}
}