/*
	왜 동적 할당이 필요 할까?

	- 적 캐릭터 1000마리 ...
	- 필요할 때, 한두마리씩 생성 ..

	- 메모리 풀링 ( Memory pooling )
	- 동적 <- 메모리는 아끼지만 프로세스 시간 들어감
	- 적절히 섞어 써야 한다.
*/

#include <iostream>

using namespace std;

void CreateData(void **data, int input);
void DeleteData(void **data);

void main(){
	//1. 이름이 있는 변수
	int num = 61;
	int *pnum = &num;

	cout << "값 = " << *pnum << " 주소 = " << pnum << endl;

	//2. 이름이 없이 포인터로 관리
	int *pnum1 = nullptr;

	// new -> 동적으로 int만큼 만들어주셈! 크기의 방만 만들어놓고, 그 주소를 pnum1이 관리
	// pnum1은 유일하게 new int로 만든 메모리에 접근할수 있는 키가 됨
	pnum1 = new int;
	{// 중괄호는 보기 좋으라고 한거
		*pnum1 = 77;
		cout << "pnum1 값 = " << *pnum1 << endl;
	}
	delete pnum1;		// delete
	pnum1 = nullptr;	// nullptr
	// 키 초기화를 하는 습관을 가져야 한다.
	// 이것도 많은 논란이 있다. 
	// c++은 garbage collector가 없어서 메모리 관리를 해줘야한다.
	// 그래서 새롭게 나온게 있음 ㅋ unique...(그닥 추천하진 않는다)
	// 수십년동안 이렇게 했는데..........

	// 3. 메모리 할당과 동시에 초기화
	void *pnum2 = new float(3.1415f);

	// 값과 주소 출력
	cout << "pnum 2 값 : " << *(float*)pnum2 << endl	
		 << "pnum 2 주소 : " << pnum2 << endl;

	delete pnum2;
	pnum2 = nullptr;

	// 확장...
	void *pdat = nullptr;

	CreateData(&pdat, 45);

	cout << *(int*)pdat << endl;
	//cout << pdat  ...->45가 출력
	
	DeleteData(&pdat);
}	

//*****************************************//
void CreateData(void **data, int input){
	*data = new int(input);
	*(int*)*(data) = input;
}

void DeleteData(void **data){
	delete *data;
	*data = nullptr;
}
//******************************************//