#include "GameMap.h"
#include "Grass.h"
#include <string>
#include <iostream>



GameMap::GameMap()
{
	GenerateMap();
}


GameMap::~GameMap()
{
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			delete map[i][j];
		}
	}
}

void GameMap::DisplayMap() {
	std::string output = "";
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			output += map[i][j]->symbol;
		}
		output += '\n';
	}
	std::cout << output;
}

void GameMap::GenerateMap() {
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			map[i][j] = new Grass();
		}
	}

}
