/*
	@author		Heedong Arkiny Lee
	@date		07292014
	@git		https://github.com/arkiny/SGA-Learning-Heedong


	좀비 칭구들
	1. 좀비 친구 추가
	2. 좀비 친구 삭제
	x. 종료

	좀비 친구 1번 나타났다. -> 총 좀비수는 1마리
	vector, new delete 활용

	기능적으로 부족할 순 있지만 해보는 걸 원칙으로
	vector를 활용한다.

	조금더 수정하고 게임답게 만들고 싶다... 
	하면 얼마든지 추가할수 있다.

	** 오늘은 좀더 포인터에 집중해서 놀았...
	질문 ] 만약 여기서 dequeue나, delete에서 double pointer를 쓰려면?
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
			cout << "잘못된 키입니다. 1, 2, x중에 다시 입력해주세요." << endl;
			break;
		} // switch
		system("pause");
		system("cls");
	} // while
	

	// Memory Cleaning Time!
	deleteTUBBY(&tv);
	// 강제로 Memory를 free 시키는 c++ function(C++11)이라는데...
	// Double check으로 한번더 비워준다.
	tv.shrink_to_fit();

	// Memory Leak checking
	
	system("pause");

	return 0;
} // main()

//간단하게 화면 출력하고 키를 입력받아주는 함수
//@param vector<TUBBY*> *vinput 출력할 벡터 포인터
//@return char 입력받은 캐릭터
char screenRendering(vector<TUBBY*> *vinput){
	char keyinput = 0;
	cout << "텔레토비 칭구들~ 우리모두 칭구칭구~!" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. 텔레토비 칭구 새로 사귀기" << endl;
	cout << "2. 텔레토비 친구 집에 보내기" << endl;
	cout << "x. 내가 집에 가기" << endl;
	cout << "--------------------------------" << endl;
	cout << "------- 텔레토비칭구 리스트 ------" << endl;
	printVector(vinput);
	cout << "--------------------------------" << endl;
	cout << "명령 입력 : ";
	cin >> keyinput;
	return keyinput;
}

// 바로위 함수의 helper function
// @param vector<TUBBY*> *vinput 출력할 벡터 포인터
void printVector(vector<TUBBY*> *vinput){
	if (vinput->size() == 0){
		cout << "텔레토비 칭구들이 아무도 없어요~♪" << endl;
	}
	else { // pointer로 받아왔기 때문에 range for문 사용이 불가능하다.
		for (int i = 0; i < vinput->size(); i++){
			cout << vinput->at(i)->z_number << " ";
		}
		cout << endl;
	}
}

// 기본적으로 과제로 내준 것은 data structure중에 queue(FIFO)의 형태를 띄고있다.
// 따라서 함수 형태를 enqueue, dequeue로 짰음
// addTUBBY를 double pointer문을 이용하면
// 어떻게 처리할수 있을까? 를 고민하면서 짠 함수
// enqueue까지는 간단하게 더블포인터를 이용해서 만들수가 있었다.
// @param vector<TUBBY*> *vinput 데이타를 추가할 벡터 (여기서 굳이 형식 안정해주고 제네릭으로 할수?)
// @param void **data double pointer for data
// @param TUBBY zinput 실제로 들어갈 데이타
void enqueueTUBBY(vector<TUBBY*> *vinput, void **data, TUBBY zinput){
	cout << "친구가 새로왔어요~ 우리모두 인사해요~" << endl;
	cout << "안녕~☆" << endl;
	*data = new TUBBY(zinput);
	*(TUBBY*)*(data) = zinput;
	vinput->push_back((TUBBY*)*(data));
	data = nullptr;  // double pointer가 아무곳도 안가르키게 리셋(for security)
}

// 혼자서 연구하면서 주저리주저리
// pointer is like bullshit....
// 주석들은 수많은 고민의 결과... 나중에 참고로 하기위해 지우지 않고 남김
// @param vector<TUBBY*> *vinput dequeue프로세스를 처리하기 위한 벡터
TUBBY dequeueTUBBY(vector<TUBBY*> *vinput){
	if (vinput->empty()){
		cout << "남은 친구들이 없는데 왜 집에 보내려고 그러시죠~?" << endl;
		return { -1 }; // Exception 처리 해줘야 하는데 귀찮...
	}
	else{
		//TUBBY* dequeueTUBBY(vector<TUBBY> *vinput, void **data){
		//*(TUBBY*)*(data) = vinput->front(); // 맨앞에 뽑아서 data에 넘겨줌
		//									 // 그럼 어떻게 dequeue함?	
		// 그래서 ret시에는 자체 임시 메모리를 통해서 ret해주는 식으로 결정
		// 이건 처리하고 바로 처리되려나?	
		// 자체 임시메모리가 받고, 포인터를 이용해서 삭제
		cout << "남은 친구들중 가장 먼저 온 텔레토비 칭구가 집에 갔어요~" << endl;
		cout << "빠바이~★" << endl;
		TUBBY ret = *vinput->front();
		// 여기서 과연 이중 포인터가 필요할것인가.
		// 데이터를 받아와서 데이터 삭제
		// 이중포인터가 필요하다! 결국 여기서도 지우는 건 주소 ...
		// 밖에서 data를 그대로 가져왔더니 예전 포인터가 안없어져서 메모리 간섭함..
		// 메모리 간섭을 일으키게 되므로 일단 열어줘야?
		//*data = new TUBBY(); // 이렇게 되면 새로 복사해오는 꼴...
		//*(TUBBY*)(ptr) = *(vinput->front());

		// front의 포인터를 복사해와서(변수내 임시 메모리므로 날아간다)
		void *ptr = vinput->front();
		// 해당 내용을 날려버린다. 실제 확인시 쓰레기값으로 바뀌는걸 확인
		// delete는 포인트를 받아서 포인트에 연관된 메모리값을 반환하므로
		// 이렇게 쓰는것도 맞는것 같다.
		delete ptr; // 좀비포인터로 캐스팅하면 다시 값을 반환하는거 맞나?
		ptr = nullptr; // ptr리셋

		// 맨앞 삭제
		vinput->erase(vinput->begin());

		return ret;
	}
}

// 지금의 최선이 이건데 이게 메모리를 제대로 삭제하는 지 확인을 해보고 싶은데...
// 메모리 릭이 나는지 안나는지...
// 메모리 정리를 위한 벡터
// @param vector<TUBBY*> *vinput dequeue프로세스를 처리하기 위한 벡터
void deleteTUBBY(vector<TUBBY*> *vinput){
	cout << "텔레토비 친구들" << endl;
	cout << "방청소(메모리 청소)를 하고," << endl;
	cout << "모두 집에 갈시간이에요~♩" << endl;
	cout << "텔레토피 칭구들 안녀엉~♬" << endl;
	void *ptr = nullptr;
	while(!vinput->empty()){
		ptr = vinput->back();
		delete ptr;
		vinput->pop_back();				
	}		
	ptr = nullptr; // ptr 리셋
}