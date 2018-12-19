#pragma once
#include "Tile.h"
#include "Tiles.h"
#include "SaveFile.h"
#include "Constants.h"
#include <vector>
#include "curses.h"
#include "Human.h"




class GameMap
{
public:
	GameMap();
	~GameMap();
	void displayMap();
	//void initializeMap();
	std::shared_ptr<Tile> get(int x, int y);
	void set(int x, int y, std::shared_ptr<Tile> t);
	bool isValidCoordinate(int x, int y);
	void moveEntityNorth(Entity e);
	void moveEntityEast(Entity e);
	void moveEntitySouth(Entity e);
	void moveEntityWest(Entity e);


	SaveFile saveFile;
	std::vector<std::shared_ptr<Tile>> map;
	std::shared_ptr<Human> player;


private:
	void loadMap();
};

