#pragma once
#include "Tile.h"
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
	void initializeMap();
	Tile get(int x, int y);
	void set(int x, int y, Tile t);
	void panNorth();
	void panEast();
	void panSouth();
	void panWest();
	int centerXCoord = 0;//MAP_WIDTH / 2;
	int centerYCoord = 0;//MAP_WIDTH / 2;
	SaveFile saveFile;
	std::vector<Tile> map;

private:
	void loadMap();
};

