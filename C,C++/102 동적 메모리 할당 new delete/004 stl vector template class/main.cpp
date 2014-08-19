/*
	STL : Standard Template Library
	vector - 배열을 자료구조화 한 클래스
*/

#include <iostream>
#include <vector>

// std라는 클래스안의 vector만 뽑아서 쓰겠다.
using std::vector;
using std::cout;
using std::endl;

void main(){
	//1. vector < datatype > name;
	vector<int> vi; // vector 선언 종료
	
	//2. 데이터 추가
	vi.push_back(2);
	vi.push_back(-3);

	//3. 원하는 위치값을 출력
	cout << "vi의 두번째 값 = " << vi.at(1) << "\n" 
		//나중에 연산자 재정의를 하면서 한번더 살펴볼것
		<< vi[1] <<endl;

	vi.push_back(12);
	vi.push_back(42);
	
	// 4. vector안의 모든값을 일괄 출력 (range based for)
	// range based for문이 없었을때, iterator를 사용한경우
	//vector<int>::iterator itr;
	//itr = vi.begin();
	//for (; itr != vi.end();){
	//	// do things
	//	itr++;
	//}

	cout << "--------------------------" << endl;
	// 5. 끝, range based for문이 종료값을 알수 있기 때문에 계속 출력이 가능하다.
	for (int i : vi){
		cout << i << endl;
	}

	// 6. vector 삭제 // 기본적으로 가진 속성은 stack
	vi.pop_back();
	cout << "--------------------------" << endl;
	for (int i : vi){
		cout << i << endl;
	}

	// 7. vector 삭제 - 머리삭제 (dequeue)
	vi.erase(vi.begin());
	cout << "--------------------------" << endl;
	for (int i : vi){
		cout << i << endl;
	}
	
}