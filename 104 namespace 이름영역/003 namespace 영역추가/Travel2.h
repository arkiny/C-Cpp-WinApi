#ifndef _TRAVEL2_H_
#define _TRAVEL2_H_

#include <string>

namespace travel{
	// �����ǰ� �ʿ��� ���
	// �����ǽÿ� �����ͷ� ���������ټ��� �ִ�.
	// �� ��� �����ͷ� ���� �����ؼ� ���� �ʿ䰡 ��������.
	/*typedef struct traveltype	{
	}TRAVELTYPE, *PTRAVELTYPE;*/
	//PTRAVELTYPE = trvPtr; -> �̷���
	enum traveltype2{
		PALLOW, BUSAN, OKINAWA, TRAVELMAX2
	};

	// static�� ���ָ� �Ǳ� �ϴµ�, �ϴ� concurrency�� ���õ� ������
	// ���߿� �ϸ� ...
	// concurrency �κ��� ������ ��԰� �־���... ���� �� ���ų�.....
	std::string travelname2[traveltype2::TRAVELMAX2] = {
		"PALLOW", "BUSAN", "OKINAWA"
	};
}

#endif