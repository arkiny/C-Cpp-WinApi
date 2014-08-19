/*
	namespace define

	namespace is really important in c#
	header is removed in the c#
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace CAT
{
	string name = "kitty";
	void show(){
		cout << "The cat's name is " << name << "." <<endl;
	}
	void show2();
}

void show();

void main(){
	show(); // the global function show
	::show();; // still the global function show

	CAT::show(); // the show function in CAT namepace
	CAT::show2(); // we can use like this even if the namespace is below the main function
				  // function prototype is necessary in the front of the main function at least
}

void show(){
	cout << "There is nothing." << endl;
}

namespace CAT{
	string cat_gf = "meow";
	void show2(){
		cout << "The name of the cat's girl friend is " << cat_gf <<"."<< endl;
	}
}