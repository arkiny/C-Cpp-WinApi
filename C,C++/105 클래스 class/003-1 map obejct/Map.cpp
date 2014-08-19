#include <iostream>
#include <fstream>
#include "Map.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

Map::Map()
{
	data.map_row = 0;
	data.map_column = 0;
	data.map_data.resize(0);
	data.map_data.shrink_to_fit();
}

Map::Map(int vertical, int horizontal){
	// re-use methods
	this->createMap(vertical, horizontal);
}

Map::~Map()
{
	// Memory Cleaning
	data.map_data.clear();
	data.map_data.resize(0);
	data.map_data.shrink_to_fit();
}

void Map::createMap(int row, int column){
	// Memory Cleaning
	this->~Map();

	data.map_row = row;
	data.map_column = column;	

	for (int i = 0; i < row*column; i++){
		data.map_data.push_back(empty);
	}
}

void Map::renderMap(){
	cout << "----------- Render Map -----------" << endl;
	for (int i = 0; i < (data.map_row * data.map_column); i++){
		cout << data.map_data[i];
		if (i % data.map_row == data.map_row - 1){
			cout << endl;
		}
	}
}

void Map::setTile(int x, int y, tiletype etype){
	data.map_data[x*(data.map_row) + y] = etype; // 1차 수열에서 2차 수열계산
}

void Map::saveMapFile(string filename){
	ofstream ofile(filename.c_str());

	if (!ofile){ // exception handling
		cout << "Unable to open the file to writing." << endl;
		return;
	}
	// 저장파일 format
	ofile.put('0' + data.map_row);
	ofile.put('0' + data.map_column);
	for (int i = 0; i < data.map_data.size(); i++){
		ofile.put('0'+data.map_data[i]);
	}	

	ofile.close();	
}

void Map::loadMapFile(string filename){
	ifstream ifile(filename.c_str());
	if (!ifile){ // exception handling
		cout << "Unable to open the file to writing." << endl;
		return;
	}
	
	data.map_row = ifile.get() - '0'; // char 에서 int로 cast하는 trick
	data.map_column = ifile.get() - '0';
	
	data.map_data.resize(0);
	data.map_data.shrink_to_fit();

	while (ifile.good()){
		data.map_data.push_back(ifile.get() - '0');
	}	

	ifile.close();
}