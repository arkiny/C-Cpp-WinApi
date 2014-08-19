/*
	friend로 도배해서 쓸수 있다고 합니다.
	그냥 예시일뿐 .... 최대한 인터페이스 만들어서 하셈
	이런게 있다고만 알고 있으면 됩니다.
*/

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

using std::ostream;
using std::istream;

using std::ofstream;
using std::ifstream;

typedef class Data
{	
public:
	//2. friend class
	friend class SaveFile;
	friend class LoadFile;
public:
	friend void setData(Data& in, int v1, float v2);
	void show();

	//1. friend function
	friend ostream& operator<< (ostream& os, Data& dat);
	friend istream& operator>> (istream& is, Data& dat);

private:
	int nval = 0;
	float fval = 0.0f;
}DATA;


void setData(Data& in, int v1, float v2){
	in.nval = v1;
	in.fval = v2;
}

istream& operator>>(istream& is, Data& dat){
	is >> dat.nval;
	is >> dat.fval;		
	return is;
}

ostream& operator<<(ostream& os, Data& dat){
	os << "operator ]] " << dat.nval << ", " << dat.fval << endl;
	return os;
}

void Data::show(){
	cout << "----- data show -----" << endl;
	cout << nval << " , " << fval << endl;
}

class SaveFile{
public:	
	void SaveToFile( Data& dat, char* filename );
	//Data dat;
};

void SaveFile::SaveToFile(Data& dat, char* filename){
	ofstream ofs;
	ofs.open(filename, std::ios_base::out);

	/*ofs.put(dat.nval);
	ofs.put(dat.fval);*/

	ofs << dat.nval << " " << dat.fval << "\n";// 이것도 가능
	
	ofs.close();
}

class LoadFile{
public:
	void LoadFromFile(Data& dat, char* filename);
};

void LoadFile::LoadFromFile(Data& dat, char* filename){
	ifstream ifs;

	ifs.open(filename, std::ios_base::in);
	
	// 심플한데 갠히 힘들게 함
	ifs >> dat.nval >> dat.fval;

	ifs.close();
}

/*
	main
*/
void main(){
	DATA dat;

	// class 안에 있는 private data를 일반 전역함수로 이용할수 있다.
	// 왜?
	// API나 상용코드를 보게 되었을 때 이걸 내부 데이타를 외부함수에서 접근할수 있게끔
	// 설정해주는 걸 볼수가 있다.
	setData(dat, 5, 5.4f);	

	dat.show();

	// cout 형태로 출력해주기 위해,
	// Data 클래스 내부에 << operator overloading 한다.
	// ostream을 리턴해야지 후위 연산자(operator) 연산을 하지 못한다.
	cout << dat << endl;

	// cin 형태로 입력
	cin >> dat;

	SaveFile save;
	save.SaveToFile(dat, "sav.txt");

	cout << dat ;

	LoadFile load;
	load.LoadFromFile(dat, "sav.txt");

	cout << dat ;

	//listen.show();
	//listen.dat.show();
}