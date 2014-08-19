/*
	STL : Standard Template Library
	vector - �迭�� �ڷᱸ��ȭ �� Ŭ����
*/

#include <iostream>
#include <vector>

// std��� Ŭ�������� vector�� �̾Ƽ� ���ڴ�.
using std::vector;
using std::cout;
using std::endl;

void main(){
	//1. vector < datatype > name;
	vector<int> vi; // vector ���� ����
	
	//2. ������ �߰�
	vi.push_back(2);
	vi.push_back(-3);

	//3. ���ϴ� ��ġ���� ���
	cout << "vi�� �ι�° �� = " << vi.at(1) << "\n" 
		//���߿� ������ �����Ǹ� �ϸ鼭 �ѹ��� ���캼��
		<< vi[1] <<endl;

	vi.push_back(12);
	vi.push_back(42);
	
	// 4. vector���� ��簪�� �ϰ� ��� (range based for)
	// range based for���� ��������, iterator�� ����Ѱ��
	//vector<int>::iterator itr;
	//itr = vi.begin();
	//for (; itr != vi.end();){
	//	// do things
	//	itr++;
	//}

	cout << "--------------------------" << endl;
	// 5. ��, range based for���� ���ᰪ�� �˼� �ֱ� ������ ��� ����� �����ϴ�.
	for (int i : vi){
		cout << i << endl;
	}

	// 6. vector ���� // �⺻������ ���� �Ӽ��� stack
	vi.pop_back();
	cout << "--------------------------" << endl;
	for (int i : vi){
		cout << i << endl;
	}

	// 7. vector ���� - �Ӹ����� (dequeue)
	vi.erase(vi.begin());
	cout << "--------------------------" << endl;
	for (int i : vi){
		cout << i << endl;
	}
	
}