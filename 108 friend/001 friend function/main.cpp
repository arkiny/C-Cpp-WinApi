/*
	friend�� �����ؼ� ���� �ִٰ� �մϴ�.
	�׳� �����ϻ� .... �ִ��� �������̽� ���� �ϼ�
	�̷��� �ִٰ� �˰� ������ �˴ϴ�.
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

	ofs << dat.nval << " " << dat.fval << "\n";// �̰͵� ����
	
	ofs.close();
}

class LoadFile{
public:
	void LoadFromFile(Data& dat, char* filename);
};

void LoadFile::LoadFromFile(Data& dat, char* filename){
	ifstream ifs;

	ifs.open(filename, std::ios_base::in);
	
	// �����ѵ� ���� ����� ��
	ifs >> dat.nval >> dat.fval;

	ifs.close();
}

/*
	main
*/
void main(){
	DATA dat;

	// class �ȿ� �ִ� private data�� �Ϲ� �����Լ��� �̿��Ҽ� �ִ�.
	// ��?
	// API�� ����ڵ带 ���� �Ǿ��� �� �̰� ���� ����Ÿ�� �ܺ��Լ����� �����Ҽ� �ְԲ�
	// �������ִ� �� ������ �ִ�.
	setData(dat, 5, 5.4f);	

	dat.show();

	// cout ���·� ������ֱ� ����,
	// Data Ŭ���� ���ο� << operator overloading �Ѵ�.
	// ostream�� �����ؾ��� ���� ������(operator) ������ ���� ���Ѵ�.
	cout << dat << endl;

	// cin ���·� �Է�
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