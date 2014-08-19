#ifndef _TRAVEL2_H_
#define _TRAVEL2_H_

#include <string>

namespace travel{
	// 재정의가 필요한 경우
	// 재정의시에 포인터로 재정의해줄수도 있다.
	// 이 경우 포인터로 따로 지정해서 만들 필요가 없어진다.
	/*typedef struct traveltype	{
	}TRAVELTYPE, *PTRAVELTYPE;*/
	//PTRAVELTYPE = trvPtr; -> 이렇게
	enum traveltype2{
		PALLOW, BUSAN, OKINAWA, TRAVELMAX2
	};

	// static을 해주면 되긴 하는데, 일단 concurrency에 관련된 문제라
	// 나중에 하면 ...
	// concurrency 부분을 완전히 까먹고 있었다... 나란 놈 병신놈.....
	std::string travelname2[traveltype2::TRAVELMAX2] = {
		"PALLOW", "BUSAN", "OKINAWA"
	};
}

#endif