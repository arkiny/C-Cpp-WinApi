/*
	STL : Standard Template Library
	list
*/


#include <string>
#include <list>
#include <iostream>
#include <algorithm> // unique

using std::string;
using std::list;
using std::cout;
using std::endl;


enum VehicleType { sedan, suv, truck, van, super, vehicle_max };

typedef struct Vehicle{
	int			type;
	string		name;
	int			price;
}VEHICLE;

int main(){
	// Vehicle�� �����Ͱ��� ���������μ� �޸� ���� ���δ�.
	list<VEHICLE*> vl; // vehicle list

	// list�� ��쿡�� push_back, push_front, pop_back, pop_front ��� �ִ�.
	// �����͸� �̿��ϰ� �ǹǷ� �޸� ������ �����ϰ� ������ �Ѵ�.
	VEHICLE* pvehicle = new VEHICLE[3];
	{
		pvehicle[0].type = VehicleType::sedan;
		pvehicle[0].name = "Malibu";
		pvehicle[0].price = 21000;
		pvehicle[1] = { VehicleType::suv, "QM5", 21500 };
		pvehicle[2] = { VehicleType::truck, "RAM", 41500 };


		vl.push_back(&pvehicle[0]);
		vl.push_back(&pvehicle[1]);
		vl.push_back(&pvehicle[2]);

		// ���⼭ ���� push_front�� �̿��� �տ� �߰�

		VEHICLE* pvehicle1 = new Vehicle;
		pvehicle1->type = VehicleType::sedan;
		pvehicle1->name = "Chairman";
		pvehicle1->price = 50000000;

		vl.push_front(pvehicle1);
		
		// ������ ������ �ٽ� �������Ƿ�,
		// ���� ������ ������ vl(����Ʈ)���� �������ְ� �ȴ�. 
		// (�ű⼭�ۿ� ������ ���ϰԵȴ�.)
		pvehicle1 = new Vehicle;
		pvehicle1->type = VehicleType::suv;
		pvehicle1->name = "Navigator";
		pvehicle1->price = 500000000;

		vl.push_front(pvehicle1);

		for (VEHICLE* i : vl){
			cout << "������: " << i->name 
				<< "\t����Ÿ��: " << i->type 
				<< "\t�������� : " << i->price << endl;
		}

		cout << "\nauto type�� �̿�----------+" << endl;
		for (auto i : vl){ 
			cout << "������: " << i->name
				<< "\t����Ÿ��: " << i->type
				<< "\t��������: " << i->price << endl;
		}

		//--------------------------------------------------
		// ����Ʈ ���� ������ �����Ҷ�
		// �Ҵ�� �޸� ������ �ݵ�� �ؾ��Ѵ�.
		// ���� ���������� ���� �������Ѵ�.
		//--------------------------------------------------
		// �޸� ����
		vl.pop_back();	// �������� ��, �ٵ� �ݺ��ؾߵ���...
						// �׸��� �����͸� ����� �ƴ�?!


		// �̰� �޸𸮼���ŭ �ݺ�
		pvehicle1 = vl.back();
		delete pvehicle1;
		vl.pop_back;
		// ��ݺ�

		vl.clear(); // �׷��� �̰� �� ����
		
		delete pvehicle1;
		pvehicle1 = nullptr;
	}
	delete[] pvehicle;
	pvehicle = nullptr;

	

	// unique_pointer
	//std::unique();

	return 0;
}
