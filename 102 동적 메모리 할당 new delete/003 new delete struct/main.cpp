/*
	���� ����ü�� �����,
	pointer�� ����
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
	// 1. ����ü �迭 ���� �Ҵ�
	VEHICLE* pvehicle = new VEHICLE[3];
	{
		pvehicle[0].type = VehicleType::sedan;
		pvehicle[0].name = "Malibu";
		pvehicle[0].price = 21000;

		pvehicle[1] = { VehicleType::suv, "QM5", 21500 };
		pvehicle[2] = { VehicleType::truck, "RAM", 41500 };
		
	}
	delete[] pvehicle;
	pvehicle = nullptr;

	return 0;
}

// vector! vector! vectorrrrrrrrrrrrrrrrrrrrrrr!