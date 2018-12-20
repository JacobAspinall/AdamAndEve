#pragma once
#include "Tile.h"
#include "Tiles.h"
#include "SaveFile.h"
#include "Constants.h"
#include <vector>
#include "curses.h"
#include "Human.h"



//Container for the game map
//member functions must be used to make any changes to the game map
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
	void moveEntityNorth(std::shared_ptr<Entity> e);
	void moveEntityEast(std::shared_ptr<Entity> e);
	void moveEntitySouth(std::shared_ptr<Entity> e);
	void moveEntityWest(std::shared_ptr<Entity> e);


	SaveFile saveFile;
	std::vector<std::shared_ptr<Tile>> map;
	


private:

};

