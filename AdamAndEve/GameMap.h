#pragma once
#include "Tile.h"

const int MAP_DISPLAY_WIDTH = 64;
const int MAP_DISPLAY_HEIGHT = 32;
const int CHUNK_WIDTH = 256;

class GameMap
{
public:
	GameMap();
	~GameMap();
	void DisplayMap();

private:
	void GenerateMap();
	Tile* map[MAP_DISPLAY_HEIGHT][MAP_DISPLAY_WIDTH];
};

