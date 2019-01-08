#pragma once
#include "Tile.h"
#include "Tiles.h"
#include "SaveFile.h"
#include "Constants.h"
#include <vector>
#include "curses.h"
#include "Human.h"
#include <mutex>



//Container for the game map
//member functions must be used to make any changes to the game map
class GameMap
{
public:
	GameMap();
	~GameMap();
	//void initializeMap();
	Tile* get(int x, int y);
	void set(int x, int y, std::unique_ptr<Tile> t);
	bool isValidCoordinate(int x, int y);
	void moveEntityNorth(Entity& e);
	void moveEntityEast(Entity& e);
	void moveEntitySouth(Entity& e);
	void moveEntityWest(Entity& e);
	Tile* tileInFrontof(Entity& e);
	void dropItem(Entity& e, int inventoryIndex);
	void pickUpItem(Entity& e, int tileItemsIndex);

	std::mutex* mapMutex;

	SaveFile saveFile;
	std::vector<std::unique_ptr<Tile>> map;
	


private:

};

