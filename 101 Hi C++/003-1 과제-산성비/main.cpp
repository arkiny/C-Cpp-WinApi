/*
	@author		Heedong Arkiny Lee
	@date		07242014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	과제 ]

	String class 활용
	compare 활용 or find 활용
	c : str[][10] = { "first", "second", "third" };
	c++ : string[5] = .....;

	다섯개의 단어 배열
	___, ___, ___, ___, ___

	입력 : ___
	해당 단어를 삭제

	산성비 게임? 비동기식 입력이 안되서 못할득
	피곤해서 오늘은 새로운 도전은 생략함요..
*/

#include <iostream> // std::
#include <string>	// string, strcmp
#include <stdlib.h> // srand(), rand(), _sleep
#include <time.h>	// time()
#include <conio.h> // _getch();


using namespace std;

//  Database... 나중에는 파일에서도 받아올수가 있음
const string DATABASE[25]
= { "GuildWar", "Mabinogi", "Terra", "Aion", "Ragnarok",
"Rift", "City Racer", "Starcraft", "Command and Conquer", "Genesis",
"Granado Espada", "League of Legends", "Diablo", "Rainbow6", "Ghost Recon",
"Endwar", "HAWX", "Tropico", "Walking Dead", "Mirror's Edge",
"Battlefield", "Call of Duty", "Halflife", "Portal", "Team Fortress2"};

//prototype;
void showArray(string *input_array);
void var_init(string *input, string *input_array, int *score);
void upper_UI();

void main(){

	// Random Seed
	srand(time(NULL));

	// Variable Init
	// 입력받을 변수
	string input = "";
	// DATABASE에서 랜덤으로 문자열을 불러와 화면에 출력한다.
	string output_string[5]	= {}; 
	int score = 0;
	time_t startTime = 0;
	time_t endTime = 0;
	time_t typingTime = 0;
	int combo = -1;
	int temp_score = -1;

	// 최초 변수 입력
	var_init(&input, output_string, &score);


	// 최초 화면 출력
	upper_UI();
	cout << "현재 점수 : " << score << endl;
	cout << "------------------------------" << endl;
	showArray(output_string);
	cout << "시간은 프롬프트가 나타나는 즉시 계산되며," << endl;
	cout << "아무키나 치시면 게임이 시작됩니다." << endl;
	_getch();
	system("cls");

	// strcmp 메소드는 비교 string이 모두 같을시 0
	// 첫글자가 다르냐 같냐에 따라서 음수 혹은 양수로 결과값을 리턴한다.

	while (strcmp(input.c_str(), "exit") != 0){ // 혹시 exit break가 안걸릴때 대비
		
		upper_UI();

		cout << "현재 점수 : " << score << endl;
		cout << "------------------------------" << endl;
		showArray(output_string);
		
		cout << "입력 : ";
		
		// 프롬프트가 뜨고나서 타자 치는 시간 계산
		startTime = time(NULL);
		getline(cin, input);
		endTime = time(NULL);
		typingTime = endTime - startTime;

		// 종료를 원할시
		if (strcmp(input.c_str(), "exit") == 0) {
			cout << "\n최종점수 : \n" << score << endl;
			cout << "프로그램 종료" << endl;
			break;
		}

		cout << "입력받은 단어 : " << input << endl;
		
		// 매 루프가 돌때마다 콤보와 score 계산츤 초기화
		combo = 0;
		temp_score = 0;
		for (int i = 0; i < 5; i++){
			// 만약 같은 걸 찾아냈을경우, 득점에 필요한 계산을 마친뒤에,
			// 그 자리에 새로운 문자열을 채워넣는다.
			if (strcmp(input.c_str(), output_string[i].c_str()) == 0){
				combo++;
				cout << output_string[i] << "-입력 성공" << endl;
				temp_score = combo*input.length() - typingTime;
				cout << combo << "콤보 * " << input.length() << " 단어길이 -" << typingTime << "시간 = " << endl;
				cout << temp_score << "득점하셨습니다." << endl;
				score = temp_score + score;
				cout << "현재까지 득점 : " << score << endl;

				output_string[i] = DATABASE[rand() % 25];
			}
			// 오타났을시에
			else if (i == 4){
				score = score - 10;
				cout << "No such a word, 점수 감소 - 10점" << endl;
			}
			else{
				// do nothing
			}
		}
		_sleep(1000);
		system("cls");
	}
}

// 변수 최초 init
void var_init(string *input, string *input_array, int *score){
	*input = "";
	for (int i = 0; i < 5; i++){
		input_array[i] = DATABASE[rand() % 25];
	}
	*score = 0;
}

// 간단한 어레이 출력 함수
void showArray(string *input_array){
	for (int i = 0; i < 5; i++){
		cout << input_array[i] << " | ";
	}
	cout << endl;
}

// ui 출력
void upper_UI(){
	cout << "이희동" << endl;
	cout << "SGA51A" << endl;
	cout << "07242014 과제" << endl;
	cout << "아래에 나와있는 단어중 하나를 입력해 삭제하세요." << endl;
	cout << "콤보(한번에 많은 칸을 없앴을 때) * 시간(s) * 단어길이수로 득점계산됩니다." << endl;
	cout << "종료는 exit을 쳐주세요." << endl;
	cout << "------------------------------------------------------------------" << endl;
}