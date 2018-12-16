#include "GameMap.h"
#include <string>
#include <iostream>

void clearScreen();

GameMap::GameMap()
{
	map.reserve(MAP_WIDTH*MAP_WIDTH);
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

void GameMap::displayMap() {

	std::string output = "";
	int topLeftXCoord = centerXCoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = centerYCoord - MAP_DISPLAY_HEIGHT / 2;
	int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	int currentRow = 0;
	int currentCol = 0;

	for (int i = topLeftYCoord; i < bottomLeftYCoord; i++) {
		for (int j = topLeftXCoord; j < topRightXCoord; j++) {
			//Check for map bounds
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				output += get(i, j).symbol;
				init_pair(1, get(i, j).foregroundColor, get(i,j).backgroundColor);
				attron(COLOR_PAIR(1));
			}
			else {
				output += ' ';
			}

			mvprintw(currentRow, currentCol, output.c_str());
			attroff(COLOR_PAIR(1));
			currentCol++;
			output = "";
		}
		currentRow++;
		currentCol = 0;
		

	}
}

void GameMap::loadMap() {

}

Tile GameMap::get(int x, int y) {

	return map[x * MAP_WIDTH + y];
}

void GameMap::set(int x, int y, Tile t) {

	map[x * MAP_WIDTH + y] = t;
}

bool isValidCoordinate(int x, int y) {
	if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_WIDTH)
		return true;
	else
		return false;
}

void GameMap::panNorth() {
	if (isValidCoordinate(centerXCoord, centerYCoord - 1))
		centerYCoord -= 1;
}

void GameMap::panEast() {
	if (isValidCoordinate(centerXCoord + 1, centerYCoord + 1))
		centerXCoord += 1;
}

void GameMap::panSouth() {
	if (isValidCoordinate(centerXCoord, centerYCoord + 1))
		centerYCoord += 1;
}

void GameMap::panWest() {
	if (isValidCoordinate(centerXCoord - 1, centerYCoord))
		centerXCoord -= 1;
}

