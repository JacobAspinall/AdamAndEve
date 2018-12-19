#include "GameMap.h"
#include <string>
#include <iostream>


GameMap::GameMap()
{
	map.resize(MAP_WIDTH*MAP_WIDTH);
	//saveFile = SaveFile();
	//initializeMap();

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
/*void GameMap::initializeMap() {

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map.push_back(Grass());
		}
	}

	saveFile.saveFullMap(map);
}
*/


void GameMap::loadMap() {

}

std::shared_ptr<Tile> GameMap::get(int x, int y) {

	return map[x * MAP_WIDTH + y];
}

void GameMap::set(int x, int y, std::shared_ptr<Tile> t) {

	map[x * MAP_WIDTH + y] = t;
}

bool GameMap::isValidCoordinate(int x, int y) {
	if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_WIDTH)
		return true;
	else
		return false;
}



