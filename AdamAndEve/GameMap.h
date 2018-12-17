#pragma once
#include "Tile.h"
#include "Tiles.h"
#include "SaveFile.h"
#include "Constants.h"
#include <vector>
#include "curses.h"




class GameMap
{
public:
	GameMap();
	~GameMap();
	void displayMap();
	//void initializeMap();
	Tile get(int x, int y);
	void set(int x, int y, Tile t);
	bool isValidCoordinate(int x, int y);
	SaveFile saveFile;
	std::vector<Tile> map;

private:
	void loadMap();
};

