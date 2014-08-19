/*
	@author		Heedong Arkiny Lee
	@date		07212014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	���� ] ���� �� ����Ʈ �����
	1. APINK		Mr.chu
	2. AOA			�ܹ߸Ӹ�
	3. Girls Day	Darling
	4.

	------------------------
	1�� �� �߰� (�Ǿտ�)
	2�� �� ���� (���ϴ� �κ�)
	3�� �� ���� (��� �� ���̿�)

	�� ������ ��κ� struct(����ü)�� �����͸� �̿��Ͽ�
	global function �� main �Լ��� �ּ�ȭ �Ϸ��� ����� �ڵ��Դϴ�.
	�׳� �Լ� ���� ��û ���� �����ϴ�.
	Ȥ�� ���ô� �е�, �׳� �Լ� ������ �Լ�...... ��¥ ���� ���µ��� ��������
*/

#include <stdio.h>		// printf()
#include <string.h>		// strcpy()
#include <stdlib.h>		// system()
#include <conio.h>		// _getch()

// �ִ� ���ڿ� �Է� ����
const int MAX_STRING = 128;

// ���� ������ ������ �ִ� structure(class)
typedef struct song_info{
	// Ȯ���� Memory Ȯ���� ���� �����͸� ���� �ʴ´�.
	char artist_name[MAX_STRING];		// ���� �̸�
	char song_name[MAX_STRING];			// ���� �̸�	
}SONG;

// ���������� ������ �ִ� Data node class
typedef struct node {
	song_info data; // data�� Ȯ���� ������ ���ؼ� �����͸� �̿����� �ʴ´�.
	node* next_node;

	// ���� �Ҵ����� ������ �ϴ°�?
	// No, I will use libary from C++
	// ������ ������� ���� strcpy�� �̿��غ�
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
	int size;	// list�� size
	node *head;	// head�� �ּ�
	
	// Constructor
	// �� singlylinkedlist�� �����
	void SinglyLinkedListInit(node *input_head){
		size = 0;
		head = input_head;
	}

	// index�� �ִ� node�� ����, ���⼭ index�� zero-based
	// @param int index (����� ���� ��)
	void removeNode(int index){
		node *cur = head;
		if (size == 0){						// �ƹ��͵� ������
			printf("������ ����Ÿ�� �����ϴ�.\n");
			system("pause");
		}
		else if (index == 0){				// ��ó�� ���� ����� ������
			head = cur->next_node;			// �� ó�� ��带 ���� ���� �������ݴϴ�.
			size--;							// ������ ���� ��
		}
		else {								// �� ���İ��� ����� ������
			// should get predecessor
			for (int i = 0; i < index - 1; i++){	// ��Ȯ�� �� ��ġ ���� ����� ������, �� �տ��� ���缭
				cur = cur->next_node;				// node�� ��������� �մϴ�.
			}
			cur->next_node = cur->next_node->next_node; // ���� ��尡 �ش� ��带 �����ϰ� ���� ����
														// �ٷ� �Ѿ�� ó��
			size--;										// ������ ���̱�
		}	
	}

	// FIFO�� ����, node ���� ó���� enqueue�Ѵ�.
	// @param node *input ���� ó���� ������ ����� �ּҰ�
	void enqueue(node *input){
		if (size == 0){					// �ƹ��͵� ���� �� ����Ʈ�϶�
			head = input;				// ù ���� ��ǲ ���
			size++;						// ����� �ö󰩴ϴ�.
		}
		else{
			input->next_node = head;	// �ƴҶ��� �Է¹��� ����� �������� ���� ó���ϰ�
										// (��Ȯ���� �� ����尡 ��ġ�� �ּҰ�)
			head = input;				// ��� ��带 �Է¹��� �ּҰ����� ��ü�մϴ�.
			size++;						// ���� ������ ����
		}
	}

	// FILO�� ����, Stack ���� �������� push�Ѵ�.
	// @param node *input ���� �������� push�� ����� �ּҰ�
	void push(node *input){
		if (size == 0){					
			head = input;				// �ƹ��͵� ���� ������Ʈ�϶�, enqueue�� �����ϴ�.
			size++;						// ������ ����
		}
		else {
			node *cur = head;			// Iterating.... ������ ������ �̵��մϴ�.
			while (cur->next_node != nullptr){
				cur = cur->next_node;
			}
			cur->next_node = input;		// ������ ��� ���� ���� �Է¹��� ����� �ּҰ�
			input->next_node = nullptr;	// Ȥ�� �𸣴� input����� �������� nullptr�� �ٽ� �������ϴ�.
			size++;						// ������ ����
		}
	}

	// ���ϴ� ��ġ�� node�� �����ϴ� �Լ� ��! ��!
	// @param node *input ������ ���
	// @param int index ������ ��ġ
	void insert(node *input, int index){
		node *cur = head;				// ���ϴ� ��ġ���� �츮�� �̵������� Ŀ��
		if (index == 0){				// ���� ���� ó����ġ�� ��!��! ���ַ��� enqueue�� �ٸ��� ������
			this->enqueue(input);		// enqueue�� ȣ�����ݴϴ�.
		}
		else {
			for (int i = 0; i < index - 1; i++){	// �츮�� �츮�� ��!��! �ϰ� ���� ����
													// �ٷ� �ձ��� �̵��� �����Դϴ�. 
													// �ֳĸ� ����... �� �ƴ϶� �� ���(Predecssor)
													// �� �ʿ��ϴϱ��. 
				cur = cur->next_node;				
			}
			input->next_node = cur->next_node;		// �Է¹��� ����� ������ �̵��� ����� �������� ����
			cur->next_node = input;					// �Է¹��� ��ġ�� ������� next_node�� �Է¹��� ���� ����
													// �۷� �����ϸ� ������� �׸��鼭 �ϸ� �����ϴ�.
		}
		size++;										// ����� Ŀ���ϴ�. ��������
	}

	// string���� ����ϴ� �Լ�
	// ������ char[]�� �ݳ��ؾ� �ϳ�, ���⼭�� �����ϰ� ����ϴ�
	// �Լ��� ����
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
	node dataBase[100] = {};	// �ڵ��߿� �� dbó���� ���� ū ���������ϴ�.
								// ��κ� �����͸� �̿��ؼ� �ڵ��ؼ� �������⼭ ���� ������ �Ͼ�� ĳ��
							
							// �ּҸ� �޾Ƽ� ó���ϹǷ�, ���� �ִ� ���� �ִ��� ���� �ʵ��� �ؾ��Ѵ�.
	int dbSize = 0;			// �ȱ׷��� ��� ������ ����, ���Ǻη� db���� �� ���� ������ �ֵ���
							// �Ҽ� ������ ���⼱ �����ϵ��� �ϰ�, db�� ������� �Է��ѵ�
							// ��ġ�� �ٽ� ó������ �ϴ� �ɷ� �Ѵ�.
	SinglyLinkedList list = {};	// ����Ʈ �ʱ�ȭ
	char key = -1;				// Ű
	
	// data initialization and loading
	dataLoading(&list, dataBase, &dbSize);
	
	// �������� ����κ�
	while (key != 'q'){
		ScreenUpdate(&list);
		key = keyinput();
		worker(&key, &list, dataBase, &dbSize);
	}
}

// ù ����Ÿ �ε�
// @param SinglyLInkedList *input_list ������ ����Ÿ ��Ʈ����
// @param node *dataBase ������ ����� ������ ���̽�
// @param int *dbSz ��Ȯ���� ������� �ƴϰ� �ε���. ���߿� �̰� ó���� ����� �����غ��߰ڴ�.
void dataLoading(SinglyLinkedList *input_list, node *dataBase, int *dbSz){
	dataBase[0] = { { "A-PINK", "Mr. Chu" }, nullptr };
	dataBase[1] = { { "A.O.A", "�ܹ߸Ӹ�" }, nullptr };
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

// �� �������� ��ũ���� ������Ʈ ���ִ� �Լ�
// @param SinglyLinkedList *input_list ����Ʈ�� �޾ƿͼ� ����Ѵ�.
void ScreenUpdate(SinglyLinkedList *input_list){
	system("cls");
	print_signature();
	printf("HD's music playlist-----------\n");
	input_list->toString();
	printf("------------------------------\n");
	printf("Menu\n");
	printf("�� �� �տ� �� �߰� (enqueue)\n");
	printf("�� �� �ڿ� �� �߰� (push)\n");
	printf("�� ���ϴ� ���� �� �߰� (insert)\n");
	printf("�� �� ����\n");
	printf("�� ����\n");
	printf("------------------------------\n");
	printf("Ű�Է� : \n");
}

// ������ Ű�� �Է������� ó���ϴ� ��Ŀ
// ����Ʈ�� �����ͺ��̽��� ������Ʈ �Ѵ�. 
// ���⼭ ������ ���̽��� node array�� �̿��ؼ� ���� �������ֱ� ������ 
// �޸� ������ �κ��� ó���Ҽ� ������, �ʹ� ����������..
// �ϴ� 100������ ����Ÿ���̽�(�޸�ó��)�� �����ϰ� �س�����,
// �ƹ����� 100�� �̻� ����Ÿ�� �Է� �����ÿ� ������ �����. (�޸� �� �� �� ��)
// �޸� ���� ���Ҵ��� �ñ��մϴ�.
void worker(char *input, SinglyLinkedList *input_list, node *dataBase, int *dbSz){
	char input_artist[MAX_STRING];
	char input_songName[MAX_STRING];
	int input_index;

	//////////////////////////////////////////////////////////////////////////////////////
	// �޸𸮸� ������������ ����� ��ǳ����....
	// �ϴ��� �׳� �ϵ��ϰ� ó���ϰ� ������ ���߿� ��������...
	// �̷��� �Ǹ� 100�� ���� �Ǹ� ó������ �ǵ��ư� ���� �ִ� ����Ÿ�� �����Ǵ� �һ�簡 �����.
	// ���Ŀ� �ذ�å ���...
	//////////////////////////////////////////////////////////////////////////////////////
	if (*dbSz == 100){
		*dbSz = 0;
	}

	// �����Ƽ� �ϵ��ڵ� �Ѥ�
	switch (*input)
	{
	case '1':
		printf("���� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_artist);
		printf("�� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_songName);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->enqueue(dataBase + *dbSz);
		*dbSz = *dbSz + 1;
		break;
	case '2':
		printf("���� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_artist);
		printf("�� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_songName);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->push(dataBase + *dbSz);
		*dbSz = *dbSz + 1;
		break;
	case '3':
		printf("���� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_artist);
		printf("�� ������ �Է����ּ���.\n�Է� : ");
		scanf("%s", &input_songName);
		printf("���ϴ� ���� �Է����ּ���.\n�Է� : ");
		scanf("%d", &input_index);

		dataBase[*dbSz].inputData(input_artist, input_songName, nullptr);
		input_list->insert(dataBase + *dbSz, input_index);
		*dbSz = *dbSz + 1;
		break;
	case '4':
		printf("���� ���� �Է����ּ���.\n�Է� : ");
		scanf("%d", &input_index);
		input_list->removeNode(input_index);
		break;
	default:
		break;
	}
}

// �����κ��� Ű�� �޾ƿͼ� ����ϴ� �޴�
char keyinput(){
	char ret = _getch(); // to return
	if (ret == 0){
		ret = _getch();
	} // if
	return ret;
} // keyinput

// ����
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07212014 ����\n");
	printf("------------------------------\n");
}