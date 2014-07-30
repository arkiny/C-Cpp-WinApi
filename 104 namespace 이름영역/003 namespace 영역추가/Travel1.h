// #ifndef (var_name) , #endif
// if not defined --> if something is not defined, define var_name
// to check double booking
#ifndef _TRAVEL1_H_  
#define _TRAVEL1_H_

#include <string>

namespace travel{
	// �����ǰ� �ʿ��� ���
	// �����ǽÿ� �����ͷ� ���������ټ��� �ִ�.
	// �� ��� �����ͷ� ���� �����ؼ� ���� �ʿ䰡 ��������.
	/*typedef struct traveltype	{
	}TRAVELTYPE, *PTRAVELTYPE;*/
	//PTRAVELTYPE = trvPtr; -> �̷���
	typedef enum traveltype	{
		LAOS, JEJU, FUKUSHIMA, TRAVELMAX
	}TRAVELTYPE;

	// static�� ���ָ� �Ǳ� �ϴµ�, �ϴ� concurrency�� ���õ� ������
	// ���߿� �ϸ� ...
	// concurrency �κ��� ������ ��԰� �־���... ���� �� ���ų�.....
	std::string travelname[TRAVELTYPE::TRAVELMAX] = {
		"LAOS", "JEJU", "FUKUSHIMA"
	};

	typedef struct fuking{
		std::string name;
	};
}


#endif
