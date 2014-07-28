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
	// Vehicle의 포인터값을 저장함으로서 메모리 낭비를 줄인다.
	list<VEHICLE*> vl; // vehicle list

	// list의 경우에는 push_back, push_front, pop_back, pop_front 모두 있다.
	// 포인터를 이용하게 되므로 메모리 관리를 세심하게 해저야 한다.
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

		// 여기서 부턴 push_front를 이용해 앞에 추가

		VEHICLE* pvehicle1 = new Vehicle;
		pvehicle1->type = VehicleType::sedan;
		pvehicle1->name = "Chairman";
		pvehicle1->price = 50000000;

		vl.push_front(pvehicle1);
		
		// 포인터 지정을 다시 해줬으므로,
		// 이제 포인터 관리는 vl(리스트)에서 관리해주게 된다. 
		// (거기서밖에 관리를 못하게된다.)
		pvehicle1 = new Vehicle;
		pvehicle1->type = VehicleType::suv;
		pvehicle1->name = "Navigator";
		pvehicle1->price = 500000000;

		vl.push_front(pvehicle1);

		for (VEHICLE* i : vl){
			cout << "차랑명: " << i->name 
				<< "\t차량타입: " << i->type 
				<< "\t차량가격 : " << i->price << endl;
		}

		cout << "\nauto type을 이용----------+" << endl;
		for (auto i : vl){ 
			cout << "차랑명: " << i->name
				<< "\t차량타입: " << i->type
				<< "\t차량가격: " << i->price << endl;
		}

		//--------------------------------------------------
		// 리스트 안의 포인터 정리할때
		// 할당된 메모리 정리를 반드시 해야한다.
		// 지가 어질렀으면 지가 지워야한다.
		//--------------------------------------------------
		// 메모리 정리
		vl.pop_back();	// 지워지긴 함, 근데 반복해야되잖...
						// 그리고 포인터만 지운거 아님?!


		// 이걸 메모리수만큼 반복
		pvehicle1 = vl.back();
		delete pvehicle1;
		vl.pop_back;
		// 재반복

		vl.clear(); // 그래서 이게 더 편함
		
		delete pvehicle1;
		pvehicle1 = nullptr;
	}
	delete[] pvehicle;
	pvehicle = nullptr;

	

	// unique_pointer
	//std::unique();

	return 0;
}
