/*
	�� ���� �Ҵ��� �ʿ� �ұ�?

	- �� ĳ���� 1000���� ...
	- �ʿ��� ��, �ѵθ����� ���� ..

	- �޸� Ǯ�� ( Memory pooling )
	- ���� <- �޸𸮴� �Ƴ����� ���μ��� �ð� ��
	- ������ ���� ��� �Ѵ�.
*/

#include <iostream>

using namespace std;

void CreateData(void **data, int input);
void DeleteData(void **data);

void main(){
	//1. �̸��� �ִ� ����
	int num = 61;
	int *pnum = &num;

	cout << "�� = " << *pnum << " �ּ� = " << pnum << endl;

	//2. �̸��� ���� �����ͷ� ����
	int *pnum1 = nullptr;

	// new -> �������� int��ŭ ������ּ�! ũ���� �游 ��������, �� �ּҸ� pnum1�� ����
	// pnum1�� �����ϰ� new int�� ���� �޸𸮿� �����Ҽ� �ִ� Ű�� ��
	pnum1 = new int;
	{// �߰�ȣ�� ���� ������� �Ѱ�
		*pnum1 = 77;
		cout << "pnum1 �� = " << *pnum1 << endl;
	}
	delete pnum1;		// delete
	pnum1 = nullptr;	// nullptr
	// Ű �ʱ�ȭ�� �ϴ� ������ ������ �Ѵ�.
	// �̰͵� ���� ����� �ִ�. 
	// c++�� garbage collector�� ��� �޸� ������ ������Ѵ�.
	// �׷��� ���Ӱ� ���°� ���� �� unique...(�״� ��õ���� �ʴ´�)
	// ���ʳ⵿�� �̷��� �ߴµ�..........

	// 3. �޸� �Ҵ�� ���ÿ� �ʱ�ȭ
	void *pnum2 = new float(3.1415f);

	// ���� �ּ� ���
	cout << "pnum 2 �� : " << *(float*)pnum2 << endl	
		 << "pnum 2 �ּ� : " << pnum2 << endl;

	delete pnum2;
	pnum2 = nullptr;

	// Ȯ��...
	void *pdat = nullptr;

	CreateData(&pdat, 45);

	cout << *(int*)pdat << endl;
	//cout << pdat  ...->45�� ���
	
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