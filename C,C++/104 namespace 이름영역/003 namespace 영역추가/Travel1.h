// #ifndef (var_name) , #endif
// if not defined --> if something is not defined, define var_name
// to check double booking
#ifndef _TRAVEL1_H_  
#define _TRAVEL1_H_

#include <string>

namespace travel{
	// 재정의가 필요한 경우
	// 재정의시에 포인터로 재정의해줄수도 있다.
	// 이 경우 포인터로 따로 지정해서 만들 필요가 없어진다.
	/*typedef struct traveltype	{
	}TRAVELTYPE, *PTRAVELTYPE;*/
	//PTRAVELTYPE = trvPtr; -> 이렇게
	typedef enum traveltype	{
		LAOS, JEJU, FUKUSHIMA, TRAVELMAX
	}TRAVELTYPE;

	// static을 해주면 되긴 하는데, 일단 concurrency에 관련된 문제라
	// 나중에 하면 ...
	// concurrency 부분을 완전히 까먹고 있었다... 나란 놈 병신놈.....
	std::string travelname[TRAVELTYPE::TRAVELMAX] = {
		"LAOS", "JEJU", "FUKUSHIMA"
	};

	typedef struct fuking{
		std::string name;
	};
}


#endif
