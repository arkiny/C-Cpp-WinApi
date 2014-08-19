/*
	@author		Heedong Arkiny Lee
	@date		07212014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	과제 ] 나의 곡 리스트 만들기
	1. APINK		Mr.chu
	2. AOA			단발머리
	3. Girls Day	Darling
	4.

	------------------------
	1번 곡 추가 (맨앞에)
	2번 곡 삭제 (원하는 부분)
	3번 곡 삽입 (곡과 곡 사이에)

	이 과제는 대부분 struct(구조체)와 포인터를 이용하여
	global function 및 main 함수를 최소화 하려고 노력한 코드입니다.
	그냥 함수 쓰면 엄청 쉬운 과젭니다.
	혹시 보시는 분들, 그냥 함수 쓰세요 함수...... 진짜 쓸모 없는데서 개삽질함
*/

#include <stdio.h>		// printf()
#include <string.h>		// strcpy()
#include <stdlib.h>		// system()
#include <conio.h>		// _getch()

// 최대 문자열 입력 개수
const int MAX_STRING = 128;

// 음악 정보를 가지고 있는 structure(class)
typedef struct song_info{
	// 확실한 Memory 확보를 위해 포인터를 쓰지 않는다.
	char artist_name[MAX_STRING];		// 가수 이름
	char song_name[MAX_STRING];			// 음악 이름	
}SONG;

// 음악정보를 가지고 있는 Data node class
typedef struct node {
	song_info data; // data의 확실한 저장을 위해서 포인터를 이용하지 않는다.
	node* next_node;

	// 동적 할당으로 만들어야 하는가?
	// No, I will use libary from C++
	// 예전에 강사님이 말한 strcpy를 이용해봄
	void inputData(char input_artist_name[MAX_STRING], 
					char input_song_name[MAX_STRING], 
					node *input_next_node){
		strcpy(data.artist_name, input_artist_name);
		strcpy(data.song_name, input_song_name);
		next_node = input_next_node;
	}
}NODE;

// structure for singlyLinkedList
// Kinda Class
typedef struct SinglyLinkedList{
	int size;	// list의 size
	node *head;	// head의 주소
	
	// Constructor
	// 빈 singlylinkedlist를 만든다
	void SinglyLinkedListInit(node *input_head){
		size = 0;
		head = input_head;
	}

	// index에 있는 node를 삭제, 여기서 index는 zero-based
	// @param int index (지우고 싶은 곳)
	void removeNode(int index){
		node *cur = head;
		if (size == 0){						// 아무것도 없을때
			printf("삭제할 데이타가 없습니다.\n");
			system("pause");
		}
		else if (index == 0){				// 맨처음 것을 지우고 싶을때
			head = cur->next_node;			// 맨 처음 노드를 다음 노드로 설정해줍니다.
			size--;							// 사이즈 줄임 ㅋ
		}
		else {								// 그 이후것을 지우고 싶을때
			// should get predecessor
			for (int i = 0; i < index - 1; i++){	// 정확한 그 위치 것을 지우고 싶으면, 그 앞에서 멈춰서
				cur = cur->next_node;				// node를 조정해줘야 합니다.
			}
			cur->next_node = cur->next_node->next_node; // 앞쪽 노드가 해당 노드를 무시하고 다음 노드로
														// 바로 넘어가게 처리
			size--;										// 사이즈 줄이기
		}	
	}

	// FIFO에 따라, node 가장 처음에 enqueue한다.
	// @param node *input 가장 처음에 삽입할 노드의 주소값
	void enqueue(node *input){
		if (size == 0){					// 아무것도 없는 새 리스트일때
			head = input;				// 첫 노드는 인풋 노드
			size++;						// 사이즈가 올라갑니다.
		}
		else{
			input->next_node = head;	// 아닐때는 입력받은 노드의 다음값을 헤드로 처리하고
										// (정확히는 그 헤드노드가 위치한 주소값)
			head = input;				// 헤드 노드를 입력받은 주소값으로 대체합니다.
			size++;						// 물론 사이즈 증가
		}
	}

	// FILO에 따라, Stack 가장 마지막에 push한다.
	// @param node *input 가장 마지막에 push할 노드의 주소값
	void push(node *input){
		if (size == 0){					
			head = input;				// 아무것도 없는 새리스트일때, enqueue와 같습니다.
			size++;						// 사이즈 증가
		}
		else {
			node *cur = head;			// Iterating.... 마지막 노드까지 이동합니다.
			while (cur->next_node != nullptr){
				cur = cur->next_node;
			}
			cur->next_node = input;		// 마지막 노드 다음 노드는 입력받은 노드의 주소값
			input->next_node = nullptr;	// 혹시 모르니 input노드의 다음값은 nullptr로 다시 잡아줬습니다.
			size++;						// 사이즈 증가
		}
	}

	// 원하는 위치에 node를 삽입하는 함수 삽! 입!
	// @param node *input 삽입할 노드
	// @param int index 삽입할 위치
	void insert(node *input, int index){
		node *cur = head;				// 원하는 위치까지 우리를 이동시켜줄 커서
		if (index == 0){				// 만약 제일 처음위치에 삽!입! 해주려면 enqueue랑 다를게 없으니
			this->enqueue(input);		// enqueue를 호출해줍니다.
		}
		else {
			for (int i = 0; i < index - 1; i++){	// 우리는 우리가 삽!입! 하고 싶은 곳의
													// 바로 앞까지 이동할 예정입니다. 
													// 왜냐면 전ㅎ... 가 아니라 전 노드(Predecssor)
													// 가 필요하니까요. 
				cur = cur->next_node;				
			}
			input->next_node = cur->next_node;		// 입력받은 노드의 다음은 이동한 노드의 다음노드로 조정
			cur->next_node = input;					// 입력받은 위치의 전노드의 next_node를 입력받은 노드로 조정
													// 글로 설명하면 어렵지만 그리면서 하면 쉽습니다.
		}
		size++;										// 사이즈가 커집니다. 무럭무럭
	}

	// string으로 출력하는 함수
	// 원래는 char[]를 반납해야 하나, 여기서는 간단하게 출력하는
	// 함수로 구현
	void toString(){
		node *cur = head;
		int i = 0;
		while (cur != nullptr){
			printf("%d.  ", i);
			printf("%s\t", cur->data.artist_name);
			printf("%s\n", cur->data.song_name);
			cur = cur->next_node;
			i++;
		}
	}
};

//prototype
void dataLoading(SinglyLinkedList *input_list, node *dataBase, int *dbSz);
void ScreenUpdate(SinglyLinkedList *input_list);
void worker(char *input, SinglyLinkedList *input_list, node *dataBase, int *dbSz);
char keyinput();
void print_signature();

////////////////////////////// main ////////////////////////////
void main(){
	// Memory Allocation, main database
	node dataBase[100] = {};	// 코딩중에 이 db처리가 가장 큰 문제였습니다.
								// 대부분 포인터를 이용해서 코딩해서 여기저기서 직접 간섭이 일어나서 캐망
							
							// 주소를 받아서 처리하므로, 원래 있던 곳에 최대한 넣지 않도록 해야한다.
	int dbSize = 0;			// 안그러면 노드 에러가 생김, 리므부로 db에서 뺀 곳에 넣을수 있도록
							// 할수 있으나 여기선 생략하도록 하고, db에 순차대로 입력한뒤
							// 넘치면 다시 처음부터 하는 걸로 한다.
	SinglyLinkedList list = {};	// 리스트 초기화
	char key = -1;				// 키
	
	// data initialization and loading
	dataLoading(&list, dataBase, &dbSize);
	
	// 실질적인 실행부분
	while (key != 'q'){
		ScreenUpdate(&list);
		key = keyinput();
		worker(&key, &list, dataBase, &dbSize);
	}
}

// 첫 데이타 로딩
// @param SinglyLInkedList *input_list 저장할 데이타 스트럭쳐
// @param node *dataBase 노드들이 저장될 데이터 베이스
// @param int *dbSz 정확히는 사이즈는 아니고 인덱스. 나중에 이걸 처리할 방법을 생각해봐야겠다.
void dataLoading(SinglyLinkedList *input_list, node *dataBase, int *dbSz){
	dataBase[0] = { { "A-PINK", "Mr. Chu" }, nullptr };
	dataBase[1] = { { "A.O.A", "단발머리" }, nullptr };
	dataBase[2] = { { "Girls Day", "Darling" }, nullptr };
	dataBase[3] = { { "Daft Punk", "Get Lucky" }, nullptr };
	dataBase[4] = { { "Deadmou5", "Ghost''n stuff" }, nullptr };	
	*dbSz = 5;

	// singly linked list init
	input_list->SinglyLinkedListInit(NULL);

	for (int i = 0; i < 5; i++){
		input_list->push(&dataBase[i]);
	}
}

// 매 루프마다 스크린을 업데이트 해주는 함수
// @param SinglyLinkedList *input_list 리스트를 받아와서 출력한다.
void ScreenUpdate(SinglyLinkedList *input_list){
	system("cls");
	print_signature();
	printf("HD's music playlist-----------\n");
	input_list->toString();
	printf("------------------------------\n");
	printf("Menu\n");
	printf("① 맨 앞에 곡 추가 (enqueue)\n");
	printf("② 맨 뒤에 곡 추가 (push)\n");
	printf("③ 원하는 곳에 곡 추가 (insert)\n");
	printf("④ 곡 삭제\n");
	printf("ⓠ 종료\n");
	printf("------------------------------\n");
	printf("키입력 : \n");
}

// 유저가 키를 입력했을때 처리하는 워커
// 리스트와 데이터베이스를 업데이트 한다. 
// 여기서 데이터 베이스는 node array를 이용해서 직접 관리해주기 때문에 
// 메모리 관련한 부분은 처리할수 있지만, 너무 저급해진다..
// 일단 100번까지 데이타베이스(메모리처리)를 가능하게 해놨지만,
// 아무래도 100번 이상 데이타를 입력 했을시에 문제가 생긴다. (메모리 누 ㅋ 수 ㅋ)
// 메모리 동적 재할당이 시급합니다.
void worker(char *input, SinglyLinkedList *input_list, node *dataBase, int *dbSz){
	char input_artist[MAX_STRING];
	char input_songName[MAX_STRING];
	int input_index;

	//////////////////////////////////////////////////////////////////////////////////////
	// 메모리를 직접만지려니 생기는 포풍문제....
	// 일단은 그냥 하드하게 처리하고 담일은 나중에 생각하자...
	// 이렇게 되면 100번 쓰게 되면 처음으로 되돌아가 원래 있던 데이타가 삭제되는 불상사가 생긴다.
	// 차후에 해결책 모색...
	//////////////////////////////////////////////////////////////////////////////////////
	if (*dbSz == 100){
		*dbSz = 0;
	}

	// 귀찮아서 하드코딩 ㅡㅡ
	switch (*input)
	{
	case '1':
		printf("가수 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_artist);
		printf("곡 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_songName);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->enqueue(dataBase + *dbSz);
		*dbSz = *dbSz + 1;
		break;
	case '2':
		printf("가수 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_artist);
		printf("곡 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_songName);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->push(dataBase + *dbSz);
		*dbSz = *dbSz + 1;
		break;
	case '3':
		printf("가수 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_artist);
		printf("곡 정보를 입력해주세요.\n입력 : ");
		scanf("%s", &input_songName);
		printf("원하는 곳을 입력해주세요.\n입력 : ");
		scanf("%d", &input_index);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->insert(dataBase + *dbSz, input_index);
		*dbSz = *dbSz + 1;
		break;
	case '4':
		printf("지울 곡을 입력해주세요.\n입력 : ");
		scanf("%d", &input_index);
		input_list->removeNode(input_index);
		break;
	default:
		break;
	}
}

// 유저로부터 키를 받아와서 출력하는 메뉴
char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput

// 서명
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07212014 과제\n");
	printf("------------------------------\n");
}