#include "GameMap.h"
#include "Grass.h"
#include <string>
#include <iostream>



GameMap::GameMap()
{
	map.reserve(MAP_WIDTH*MAP_WIDTH);
	saveFile = SaveFile();
	initializeMap();
}


GameMap::~GameMap()
{
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			//delete loadedMap[i][j];
		}
	}
}

//Call when creating a brand new map
void GameMap::initializeMap() {

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map.push_back(Grass());
		}
	}

	saveFile.saveFullMap(map);
}

void GameMap::displayMap() {
	std::string output = "";
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			//output += map[i][j]->symbol;
		}
		output += '\n';
	}
	std::cout << output;
}

void GameMap::loadMap() {

}

Tile GameMap::get(int x, int y) {

	return map[x * MAP_WIDTH + y];
}

void GameMap::set(int x, int y, Tile t) {

	map[x * MAP_WIDTH + y] = t;
}

