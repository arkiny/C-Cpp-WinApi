/*
	표준 라이브러리 함수( Standard Library Function )
	time 시간 출력
	*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// function declaration
bool alarm(time_t Current_Time, int Countdown);

// main method
void main(){
	// Begin time
	const time_t currentTime = time(NULL);

	printf("현재시간 = %u\n", currentTime);
	printf("현재시간 = %s\n", asctime(localtime(&currentTime)));

	while (true){
		if (alarm(currentTime, 3)){
			printf("3 sec\n");
			break;
		}
		else {
			// do nothing
		}
	}// end while

}

// Do I have to use diff time?
// nah time change is complted after 1 sec
// thistime - current time is working
// @param	time_t Current_Time
// @param	int Contdowon
// @return	is the time?
bool alarm(time_t Current_Time, int Countdown){
	time_t thistime = time(NULL);
	if (thistime - Current_Time == Countdown){
		return true;
	}
	else{ return false; }
}
/*
	5초가 지나면 ... 알람을 해주는 함수
	프로그램이 시작하고 5초가 경과되면,
	-> 5초가 지났습니다.

	while (true){
	if (5초 경과 체크 == true) --> 함수화
	{
	print and break
	}
	else {
	nextturn
	}
	}

	bool Alarm( 시작 시간, int countdown )
	*/