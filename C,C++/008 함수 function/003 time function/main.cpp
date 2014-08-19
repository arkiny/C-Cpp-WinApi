/*
	ǥ�� ���̺귯�� �Լ�( Standard Library Function )
	time �ð� ���
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

	printf("����ð� = %u\n", currentTime);
	printf("����ð� = %s\n", asctime(localtime(&currentTime)));

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
	5�ʰ� ������ ... �˶��� ���ִ� �Լ�
	���α׷��� �����ϰ� 5�ʰ� ����Ǹ�,
	-> 5�ʰ� �������ϴ�.

	while (true){
	if (5�� ��� üũ == true) --> �Լ�ȭ
	{
	print and break
	}
	else {
	nextturn
	}
	}

	bool Alarm( ���� �ð�, int countdown )
	*/