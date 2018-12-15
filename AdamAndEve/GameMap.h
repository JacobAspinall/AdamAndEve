#pragma once
#include "Tile.h"
#include "SaveFile.h"
#include "Constants.h"
#include <vector>




class GameMap
{
public:
	GameMap();
	~GameMap();
	void displayMap();
	void initializeMap();
	Tile get(int x, int y);
	void set(int x, int y, Tile t);
	int centerXCoord;
	int centerYCoord;
	SaveFile saveFile;
	std::vector<Tile> map;

private:
	void loadMap();
};

