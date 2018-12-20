#include "GameMap.h"
#include <string>
#include <iostream>


GameMap::GameMap()
{
	map.resize(MAP_WIDTH*MAP_WIDTH);

}


GameMap::~GameMap()
{
	for (int i = 0; i < MAP_DISPLAY_HEIGHT; i++) {
		for (int j = 0; j < MAP_DISPLAY_WIDTH; j++) {
			//delete loadedMap[i][j];
		}
	}
}

//returns pointer to the tile at coordinates x and y
std::shared_ptr<Tile> GameMap::get(int x, int y) {

	return map[y * MAP_WIDTH + x];
}

// sets the tile at x,y to the passed in tile t
void GameMap::set(int x, int y, std::shared_ptr<Tile> t) {

	map[y * MAP_WIDTH + x] = t;
}

//returns true if x,y are within the bounds of the map
//does not check if an entity is able to legally move to this tile(due to an obstruction e.g tree/wall)
bool GameMap::isValidCoordinate(int x, int y) {
	if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_WIDTH)
		return true;
	else
		return false;
}

//If legal, moves an entity one tile to its north, otherwise the entity with stay put
void GameMap::moveEntityNorth(std::shared_ptr<Entity> e) {
	std::shared_ptr<Tile> t = get(e->xCoord, e->yCoord);
	int newXcoord = t->entity->xCoord;
	int newYcoord = t->entity->yCoord - 1;
	if (isValidCoordinate(newXcoord, newYcoord)) {
		std::shared_ptr<Tile> newTile = get(newXcoord, newYcoord);
		if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
			if (newTile->entity == nullptr) {
				t->entity = nullptr;
				newTile->entity = e;
				e->yCoord = newYcoord;
			}
		}
	}

}

//If legal, moves an entity one tile to its east, otherwise the entity with stay put
void GameMap::moveEntityEast(std::shared_ptr<Entity> e) {
	std::shared_ptr<Tile> t = get(e->xCoord, e->yCoord);
	int newXcoord = t->entity->xCoord + 1;
	int newYcoord = t->entity->yCoord;
	if (isValidCoordinate(newXcoord, newYcoord)) {
		std::shared_ptr<Tile> newTile = get(newXcoord, newYcoord);
		if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
			if (newTile->entity == nullptr) {
				t->entity = nullptr;
				newTile->entity = e;
				e->xCoord = newXcoord;
			}
		}
	}
}

//If legal, moves an entity one tile to its south, otherwise the entity with stay put
void GameMap::moveEntitySouth(std::shared_ptr<Entity> e) {
	std::shared_ptr<Tile> t = get(e->xCoord, e->yCoord);
	int newXcoord = t->entity->xCoord;
	int newYcoord = t->entity->yCoord + 1;
	if (isValidCoordinate(newXcoord, newYcoord)) {
		std::shared_ptr<Tile> newTile = get(newXcoord, newYcoord);
		if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
			if (newTile->entity == nullptr) {
				t->entity = nullptr;
				newTile->entity = e;
				e->yCoord = newYcoord;
			}
		}
	}
}

//If legal, moves an entity one tile to its west, otherwise the entity with stay put
void GameMap::moveEntityWest(std::shared_ptr<Entity> e) {
	std::shared_ptr<Tile> t = get(e->xCoord, e->yCoord);
	int newXcoord = t->entity->xCoord - 1;
	int newYcoord = t->entity->yCoord;
	if (isValidCoordinate(newXcoord, newYcoord)) {
		std::shared_ptr<Tile> newTile = get(newXcoord, newYcoord);
		if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
			if (newTile->entity == nullptr) {
				t->entity = nullptr;
				newTile->entity = e;
				e->xCoord = newXcoord;
			}
		}
	}
}





