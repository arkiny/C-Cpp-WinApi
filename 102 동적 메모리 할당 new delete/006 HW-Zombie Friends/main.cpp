/*
	@author		Heedong Arkiny Lee
	@date		07292014
	@git		https://github.com/arkiny/SGA-Learning-Heedong


	���� Ī����
	1. ���� ģ�� �߰�
	2. ���� ģ�� ����
	x. ����

	���� ģ�� 1�� ��Ÿ����. -> �� ������� 1����
	vector, new delete Ȱ��

	��������� ������ �� ������ �غ��� �� ��Ģ����
	vector�� Ȱ���Ѵ�.

	���ݴ� �����ϰ� ���Ӵ�� ����� �ʹ�... 
	�ϸ� �󸶵��� �߰��Ҽ� �ִ�.

	** ������ ���� �����Ϳ� �����ؼ� ���...
	���� ] ���� ���⼭ dequeue��, delete���� double pointer�� ������?
*/
#include <vector>
#include <string>
#include <iostream>

// using
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

// user defined type TUBBY
typedef struct TUBBY{
	int z_number;
}tubby;

// Proto Type
void enqueueTUBBY(vector<TUBBY*> *vinput, void **data, TUBBY zinput);
void deleteTUBBY(vector<TUBBY*> *vinput);
TUBBY dequeueTUBBY(vector<TUBBY*> *vinput);
void printVector(vector<TUBBY*> *vinput);
char screenRendering(vector<TUBBY*> *vinput);

// main function
int main(){	
	// variable init
	vector<TUBBY*> tv;
	void *pdat = nullptr;
	char key = 0;
	int time = 1;

	while (key != 88 && key != 120){
		key = screenRendering(&tv);
		switch (key)
		{
		case 49:		// 1
			enqueueTUBBY(&tv, &pdat, { time });
			time++;
			break;
		case 50:		//2
			dequeueTUBBY(&tv);
			break;
		case 88:		//x
		case 120:		//X (capital)
			// do nothing
			// will be broken automatically
			break;
		default:
			cout << "�߸��� Ű�Դϴ�. 1, 2, x�߿� �ٽ� �Է����ּ���." << endl;
			break;
		} // switch
		system("pause");
		system("cls");
	} // while
	

	// Memory Cleaning Time!
	deleteTUBBY(&tv);
	// ������ Memory�� free ��Ű�� c++ function(C++11)�̶�µ�...
	// Double check���� �ѹ��� ����ش�.
	tv.shrink_to_fit();

	// Memory Leak checking
	
	system("pause");

	return 0;
} // main()

//�����ϰ� ȭ�� ����ϰ� Ű�� �Է¹޾��ִ� �Լ�
//@param vector<TUBBY*> *vinput ����� ���� ������
//@return char �Է¹��� ĳ����
char screenRendering(vector<TUBBY*> *vinput){
	char keyinput = 0;
	cout << "�ڷ���� Ī����~ �츮��� Ī��Ī��~!" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. �ڷ���� Ī�� ���� ��ͱ�" << endl;
	cout << "2. �ڷ���� ģ�� ���� ������" << endl;
	cout << "x. ���� ���� ����" << endl;
	cout << "--------------------------------" << endl;
	cout << "------- �ڷ����Ī�� ����Ʈ ------" << endl;
	printVector(vinput);
	cout << "--------------------------------" << endl;
	cout << "��� �Է� : ";
	cin >> keyinput;
	return keyinput;
}

// �ٷ��� �Լ��� helper function
// @param vector<TUBBY*> *vinput ����� ���� ������
void printVector(vector<TUBBY*> *vinput){
	if (vinput->size() == 0){
		cout << "�ڷ���� Ī������ �ƹ��� �����~��" << endl;
	}
	else { // pointer�� �޾ƿԱ� ������ range for�� ����� �Ұ����ϴ�.
		for (int i = 0; i < vinput->size(); i++){
			cout << vinput->at(i)->z_number << " ";
		}
		cout << endl;
	}
}

// �⺻������ ������ ���� ���� data structure�߿� queue(FIFO)�� ���¸� ����ִ�.
// ���� �Լ� ���¸� enqueue, dequeue�� ®��
// addTUBBY�� double pointer���� �̿��ϸ�
// ��� ó���Ҽ� ������? �� ����ϸ鼭 § �Լ�
// enqueue������ �����ϰ� ���������͸� �̿��ؼ� ������� �־���.
// @param vector<TUBBY*> *vinput ����Ÿ�� �߰��� ���� (���⼭ ���� ���� �������ְ� ���׸����� �Ҽ�?)
// @param void **data double pointer for data
// @param TUBBY zinput ������ �� ����Ÿ
void enqueueTUBBY(vector<TUBBY*> *vinput, void **data, TUBBY zinput){
	cout << "ģ���� ���οԾ��~ �츮��� �λ��ؿ�~" << endl;
	cout << "�ȳ�~��" << endl;
	*data = new TUBBY(zinput);
	*(TUBBY*)*(data) = zinput;
	vinput->push_back((TUBBY*)*(data));
	data = nullptr;  // double pointer�� �ƹ����� �Ȱ���Ű�� ����(for security)
}

// ȥ�ڼ� �����ϸ鼭 ������������
// pointer is like bullshit....
// �ּ����� ������ ����� ���... ���߿� ����� �ϱ����� ������ �ʰ� ����
// @param vector<TUBBY*> *vinput dequeue���μ����� ó���ϱ� ���� ����
TUBBY dequeueTUBBY(vector<TUBBY*> *vinput){
	if (vinput->empty()){
		cout << "���� ģ������ ���µ� �� ���� �������� �׷�����~?" << endl;
		return { -1 }; // Exception ó�� ����� �ϴµ� ����...
	}
	else{
		//TUBBY* dequeueTUBBY(vector<TUBBY> *vinput, void **data){
		//*(TUBBY*)*(data) = vinput->front(); // �Ǿտ� �̾Ƽ� data�� �Ѱ���
		//									 // �׷� ��� dequeue��?	
		// �׷��� ret�ÿ��� ��ü �ӽ� �޸𸮸� ���ؼ� ret���ִ� ������ ����
		// �̰� ó���ϰ� �ٷ� ó���Ƿ���?	
		// ��ü �ӽø޸𸮰� �ް�, �����͸� �̿��ؼ� ����
		cout << "���� ģ������ ���� ���� �� �ڷ���� Ī���� ���� �����~" << endl;
		cout << "������~��" << endl;
		TUBBY ret = *vinput->front();
		// ���⼭ ���� ���� �����Ͱ� �ʿ��Ұ��ΰ�.
		// �����͸� �޾ƿͼ� ������ ����
		// ���������Ͱ� �ʿ��ϴ�! �ᱹ ���⼭�� ����� �� �ּ� ...
		// �ۿ��� data�� �״�� �����Դ��� ���� �����Ͱ� �Ⱦ������� �޸� ������..
		// �޸� ������ ����Ű�� �ǹǷ� �ϴ� �������?
		//*data = new TUBBY(); // �̷��� �Ǹ� ���� �����ؿ��� ��...
		//*(TUBBY*)(ptr) = *(vinput->front());

		// front�� �����͸� �����ؿͼ�(������ �ӽ� �޸𸮹Ƿ� ���ư���)
		void *ptr = vinput->front();
		// �ش� ������ ����������. ���� Ȯ�ν� �����Ⱚ���� �ٲ�°� Ȯ��
		// delete�� ����Ʈ�� �޾Ƽ� ����Ʈ�� ������ �޸𸮰��� ��ȯ�ϹǷ�
		// �̷��� ���°͵� �´°� ����.
		delete ptr; // ���������ͷ� ĳ�����ϸ� �ٽ� ���� ��ȯ�ϴ°� �³�?
		ptr = nullptr; // ptr����

		// �Ǿ� ����
		vinput->erase(vinput->begin());

		return ret;
	}
}

// ������ �ּ��� �̰ǵ� �̰� �޸𸮸� ����� �����ϴ� �� Ȯ���� �غ��� ������...
// �޸� ���� ������ �ȳ�����...
// �޸� ������ ���� ����
// @param vector<TUBBY*> *vinput dequeue���μ����� ó���ϱ� ���� ����
void deleteTUBBY(vector<TUBBY*> *vinput){
	cout << "�ڷ���� ģ����" << endl;
	cout << "��û��(�޸� û��)�� �ϰ�," << endl;
	cout << "��� ���� ���ð��̿���~��" << endl;
	cout << "�ڷ����� Ī���� �ȳ��~��" << endl;
	void *ptr = nullptr;
	while(!vinput->empty()){
		ptr = vinput->back();
		delete ptr;
		vinput->pop_back();				
	}		
	ptr = nullptr; // ptr ����
}