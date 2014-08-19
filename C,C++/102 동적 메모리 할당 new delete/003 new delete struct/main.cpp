/*
	동적 구조체를 만들고,
	pointer가 제어
*/

#include <iostream>
#include <string>

using namespace std;

enum VehicleType {sedan, suv, truck, van, super, vehicle_max};

typedef struct Vehicle{
	int			type;
	string		name;
	int			price;
}VEHICLE;

int main(){
	// 1. 구조체 배열 동적 할당
	// 구조체로도 new를 이용할 수 있다.
	VEHICLE* pvehicle = new VEHICLE[3];
	{
		pvehicle[0].type = VehicleType::sedan;
		pvehicle[0].name = "Malibu";
		pvehicle[0].price = 21000;

		pvehicle[1] = { VehicleType::suv, "QM5", 21500 };
		pvehicle[2] = { VehicleType::truck, "RAM", 41500 };
		
	}

	// 만약에 delete[1]만 해주면 주소 1에 들어있는 값만 삭제되면서 모양이 이상해진다.
	// 따라서 의미가 없으므로, 그냥 한번에 삭제하도록 한다.
	delete[] pvehicle; 
	pvehicle = nullptr;

	return 0;
}

// vector! vector! vectorrrrrrrrrrrrrrrrrrrrrrr!
