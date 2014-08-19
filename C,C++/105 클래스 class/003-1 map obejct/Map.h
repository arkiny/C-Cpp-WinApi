/*
	@author		Heedong Arkiny Lee
	@date		08032014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	map class 만들기

	기본]
	enum tiletype { ROAD, WALL, MAX_TILE };
	CreateMap(int row, int column );					// 맵 init
	RenderMap();										// 만든 맵을 출력
	SetTile(int row, int column, tiletype etype);

	확장]
	SaveMapFile( filename );
	LoadMapFile( filename );
*/

#pragma once

#include <string> // string
#include <vector> // vector

using std::string;
using std::vector;

enum tiletype{ empty, full, player, enemy, tiletype_MAX };

typedef struct map_info {
	int map_row = 0;
	int map_column = 0;
	vector<int> map_data;
}MAP_INFO, *LPMAP_INFO;

class Map
{
public:
	// Basic Constructor
	// make empty (size = 0) array
	Map();

	// @param int vertical size
	// @param int horizontal size
	Map(int, int);

	// destructor
	~Map();

	// create map with input size
	// @param int column
	// @param int row
	void createMap(int, int);

	// print out map
	void renderMap();

	// set tile as input tile type
	// @param int x coordinate
	// @param int y coordinate
	void setTile(int, int, tiletype);

	// save map_info to file string as textfile
	// @param string filename
	void saveMapFile(string);

	// load map_info from file string 
	// @param string filename
	// @warning this function will clear up current map_info
	void loadMapFile(string);

private:
	MAP_INFO data; // map data
};

