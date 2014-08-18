#include <iostream>
#include <string>
#include "callback.h"

using std::cout;
using std::endl;
using std::string;

typedef struct data{
	int posx = 10;
	int posy = 30;
}DATA;

void onEvent(void *pdat){
	cout << ((char*)pdat) << endl;
}

void msg(void *pdat){
	cout << "something destroyed" << endl;
	cout << ((data*)pdat)->posx << ", " 
		<< ((data*)pdat)->posy << endl;
}


char strmsg[50] = "";

void main(){
	DATA dat;
	/*void *ptr = nullptr;*/
	//callback* event1 = new callbackFunction<void>(onEvent);
	callback* event1 = new callbackFunction(msg);
	event1->call(&dat);
	delete event1;
	
	//
	string strmsg = "Hello callback";
	char str[50] = "";
	strcpy(str, strmsg.c_str());
	callback* event2 = new callbackFunction(msg);
	event2->call(str);
	delete event2;
}