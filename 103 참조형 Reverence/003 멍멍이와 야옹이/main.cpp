/*과제]

	@author		Heedong Arkiny Lee
	@date		07292014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	Original Specification -------------------------------------
	강쥐와 냥이 ]]

	pet 구조체 정의 ]]
		- 이름,애정도
	
	예 ))

	철수 20일간 해외여행을 떠난다
	"다롱이"와 "야롱이"를 순자에게 맡긴다
	먹이를 하루에 한번 준다

	먹이를 먹으면 애정도 1씩 증가
	먹이를 못먹으면 애정도 2씩 감소
	애정도가 0이 되면 가출

	20일간 버티기

	함수 ]] & 형태로 구조체 전달

	-------------------------------------------------------------
	변형된 것(도전해본 것) -
	1. 구조체 대신에 구조체 주소를 가진 vector를 &형태로 전달
		-> pointer와 reference의 만남!
	2. vector를 이용했으므로 고양이 숫자가 자유롭기 때문에,
		난이도 조절은 고양이 숫자로 실시

	좀 더 도전해 보고 싶은 점
	1. 여기서 double pointer를 이용한다면?
	2. 여기서 double pointer가 굳이 필요한지?
	------------------------------------------------------------
	
	따로 종료 인터페이스는 안넣음
*/

#include <iostream> // cout, cin, endl
#include <string>	// string
#include <vector>	// vector
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Global Constant Variable
const unsigned int DEFAULT_AFFECTION_POINT = 25; // default affection point
const string catName[] = { "냥이", "먕이", "나비", "반장", 
						"알렉", "정남", "조석", "수지", 
						"현영", "뱅이", "호두", "몬드" };

typedef struct cat {
	string name;							// 고양이 이름
	unsigned int affection_point;			// 애정도

	// 고양이가 도망갔는지 안도망갔는지 확인
	bool isRunAway(){
		return affection_point <= 0;
	}

	// 애정 받을 경우
	void feed(){
		affection_point += 1;
	}

	// 애정 못받을 경우
	void no_feed(){
		affection_point -= 2;
	}
}CAT;

//prototype
void screenRender(vector<CAT*> &input, int day);
void initCats(vector<CAT*> &input, int size);
void clearCats(vector<CAT*> &input);
int startScreen();
void printBadEnding();
void printGoodEnding();
bool step_feed(vector<CAT*> &input, int select);

//main
void main(){
	// seeding
	srand(time(NULL));

	// var init
	int day = 0; // 일차
	int nCat = 0; // 고양이 수
	int choice = 0; // 선택
	bool badEnding = false;
	vector<CAT*> cats; // 고양이들 메모리 주소관리

	// 첫화면 출력과 동시에 고양이 숫자를 정한다.
	nCat = startScreen();

	// 고양이 수만큼 고양이 초기화
	// @이름 처리할수 있게?
	initCats(cats, nCat); // 게임 시작시 고양이 숫자 받을수 있게 처리


	while (day != 21){
		screenRender(cats, day);
		cin >> choice;
		badEnding = step_feed(cats, choice);
		if (badEnding){			
			break;
		} // if
		day++;
		system("cls");
	} // while

	if (badEnding){
		printBadEnding();
	}
	else {
		printGoodEnding();
	}// if

	// 메모리 정리
	clearCats(cats);
}// main

// 입력한 수만큼 고양이 생성
// 동적할당 이용
// @param vector<CAT*> &input, CAT주소들의 벡터(수정될 벡터)
// @param int size 추가할 고양이들 숫자
void initCats(vector<CAT*> &input, int size){
	//@todo 고양이 이름 처리
	//포인터와 리퍼런스의 만남! 점점 코드가 복잡스레 해져가는구나!
	void *ptr = nullptr;
	for (int i = 0; i < size; i++){
		// 동적 할당
		ptr = new CAT({ catName[rand() % 12], DEFAULT_AFFECTION_POINT });
		input.push_back((CAT*)ptr);
	}
	ptr = nullptr;
} // initCats

// 고양이들이랑 놀아준 뒤에
// 도망간 고양이가 있으면 바로 프로세스를 멈추고 상황을 리턴한다.
// @param vector<CAT*> &input 고양이들
// @param int select 먹일 고양이 번호
// @return bool 도망간 고양이가 있는가?
bool step_feed(vector<CAT*> &input, int select){
	bool ret = false;
	for (int i = 0; i < input.size(); i++){
		if (select - 1 == i){
			input.at(i)->feed();
		}
		else {
			input.at(i)->no_feed();
			if (input.at(i)->isRunAway()){
				ret = true;
				break;
			}
		}
	}
	return ret;
}// step_feed

// 메모리 관리
// @param vector<CAT*> &input 메모리 정리를 해줄 vector
void clearCats(vector<CAT*> &input){
	void *ptr = nullptr;
	while (!input.empty()){
		ptr = input.back();
		delete ptr;
		input.pop_back();
		ptr = nullptr;
	}
} // clearCats

// 첫화면, 같이 살 고양이 숫자를 입력받아서 리턴한다.
// @return 입력받은 고양이 숫자
int startScreen(){
	int ret = 0;
	cout << "고양이 애정도 관리하기" << endl
		<< "------------------------------------------------------------" << endl
		<< "본 프로그램은 고양이들과의 애정도를 관리하면서" << endl
		<< "20일간 고양이들의 애정도가 0이하로 떨어지지 않게," << endl
		<< "관리하는 게임입니다." << endl
		<< "난이도는 같이 사는 고양이의 숫자로 조정됩니다." << endl
		<< "------------------------------------------------------------" << endl
		<< "몇 마리의 고양이와 같이 사시겠습니까?" << endl << endl
		<< "입력 : ";
	cin >> ret;
	while (ret <= 1){
		cout << "0마리나 1마리로는 게임을 시작할수 없습니다." << endl << endl
			<< "다시 입력해 주세요 : ";
		cin >> ret;
	}
	system("cls");
	return ret;
} // startScreen

void screenRender(vector<CAT*> &input, int day){
	cout << "고양이랑 놀아주기 게임"<< endl
		<< day << " 일차" << endl
		<< "------------------------------------------------------------" << endl;
	for (int i= 0; i < input.size(); i++){
		cout << i + 1<<". " << "이름 : " << input.at(i)->name 
			<< "\t애정도 : " << input.at(i)->affection_point << endl;
	}
	cout << "------------------------------------------------------------" << endl
		<< "고양이들이 집사와 놀고 싶어합니다. 몇번 고양이와 놀아주시겠습니까?" << endl
		<< "(해당고양이 애정도 1 상승, 다른 고양이들은 질투로 애정도 2 하강)" << endl << endl
		<< "선택 : ";
}// screendRender

// 해피엔딩 출력
void printGoodEnding(){
	cout << "그렇게 20일이후 당신은 고양이들과 영웡히 행복하게 살았답니다." << endl
		<< endl
		<< "Happy Ending" << endl;
	system("pause");
}

// 배드엔딩 출력
void printBadEnding(){
	cout << "으앙, 고양이가 도망가버렸어요 ㅠㅠ" << endl
		<< endl
		<< "Game Over" << endl;
	system("pause");
}