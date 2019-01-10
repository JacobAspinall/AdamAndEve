#include "GameMap.h"
#include <string>
#include <iostream>


GameMap::GameMap()
{
	map.resize(MAP_WIDTH*MAP_WIDTH);
	mapMutex = new std::mutex;

}


GameMap::~GameMap()
{
	delete mapMutex;
}

//returns pointer to the tile at coordinates x and y
Tile* GameMap::get(int x, int y) {
	if (!isValidCoordinate(x, y)) {
		return nullptr;
	}
	return map[y * MAP_WIDTH + x].get();
}

// sets the tile at x,y to the passed in tile t
void GameMap::set(int x, int y, std::unique_ptr<Tile> t) {
	if (isValidCoordinate(x, y)) {
		map[y * MAP_WIDTH + x] = std::move(t);
	}

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
void GameMap::moveEntityNorth(Entity& e) {
	if (e.tileYCoord > 0) {
		e.tileYCoord -= 1;
	}
	else {
		Tile* t = get(e.xCoord, e.yCoord);
		int newXcoord = t->entity->xCoord;
		int newYcoord = t->entity->yCoord - 1;
		if (isValidCoordinate(newXcoord, newYcoord)) {
			Tile* newTile = get(newXcoord, newYcoord);
			if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
				if (newTile->entity == nullptr) {
					newTile->entity = std::move(t->entity);
					t->entity = nullptr;
					e.yCoord = newYcoord;
					e.tileYCoord = 15;
				}
			}
		}
	}
	e.directionFacing = Direction::NORTH;
}

//If legal, moves an entity one tile to its east, otherwise the entity with stay put
void GameMap::moveEntityEast(Entity& e) {
	if (e.tileXCoord < 15) {
		e.tileXCoord += 1;
	}
	else {
		Tile* t = get(e.xCoord, e.yCoord);
		int newXcoord = t->entity->xCoord + 1;
		int newYcoord = t->entity->yCoord;
		if (isValidCoordinate(newXcoord, newYcoord)) {
			Tile* newTile = get(newXcoord, newYcoord);
			if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
				if (newTile->entity == nullptr) {
					newTile->entity = std::move(t->entity);
					t->entity = nullptr;
					e.xCoord = newXcoord;
					e.tileXCoord = 0;
				}
			}
		}
	}
	e.directionFacing = Direction::EAST;
}

//If legal, moves an entity one tile to its south, otherwise the entity with stay put
void GameMap::moveEntitySouth(Entity& e) {
	if (e.tileYCoord < 15) {
		e.tileYCoord += 1;
	}
	else {
		Tile* t = get(e.xCoord, e.yCoord);
		int newXcoord = t->entity->xCoord;
		int newYcoord = t->entity->yCoord + 1;
		if (isValidCoordinate(newXcoord, newYcoord)) {
			Tile* newTile = get(newXcoord, newYcoord);
			if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
				if (newTile->entity == nullptr) {
					newTile->entity = std::move(t->entity);
					t->entity = nullptr;
					e.yCoord = newYcoord;
					e.tileYCoord = 0;
				}
			}
		}
	}
	e.directionFacing = Direction::SOUTH;
}

//If legal, moves an entity one tile to its west, otherwise the entity with stay put
void GameMap::moveEntityWest(Entity& e) {
	if (e.tileXCoord > 0) {
		e.tileXCoord -= 1;
	}
	else {
		Tile* t = get(e.xCoord, e.yCoord);
		int newXcoord = t->entity->xCoord - 1;
		int newYcoord = t->entity->yCoord;
		if (isValidCoordinate(newXcoord, newYcoord)) {
			Tile* newTile = get(newXcoord, newYcoord);
			if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
				if (newTile->entity == nullptr) {
					newTile->entity = std::move(t->entity);
					t->entity = nullptr;
					e.xCoord = newXcoord;
					e.tileXCoord = 15;
				}
			}
		}
	}
	e.directionFacing = Direction::WEST;
}

void GameMap::moveEntityNorthEast(Entity& e) {
	moveEntityNorth(e);
	moveEntityEast(e);
	e.directionFacing = Direction::EAST;
}

void GameMap::moveEntityNorthWest(Entity& e) {
	moveEntityNorth(e);
	moveEntityWest(e);
	e.directionFacing = Direction::WEST;
}

void GameMap::moveEntitySouthEast(Entity& e) {
	moveEntitySouth(e);
	moveEntityEast(e);
	e.directionFacing = Direction::EAST;
}

void GameMap::moveEntitySouthWest(Entity& e) {
	moveEntitySouth(e);
	moveEntityWest(e);
	e.directionFacing = Direction::WEST;
}

void GameMap::moveEntity(Entity& e, MovementVector direction) {
	double newTileXCoord = e.tileXCoord + direction.x;
	double newTileYCoord = e.tileYCoord + direction.y;
	int newXCoord = e.xCoord;
	int newYCoord = e.yCoord;

	if (newTileXCoord > 15) {
		newTileXCoord -= 15;
		newXCoord++;
	}
	else if (newTileXCoord < 0) {
		newTileXCoord += 15;
		newXCoord--;
	}

	if (newTileYCoord > 15) {
		newTileYCoord -= 15;
		newYCoord++;
	}
	else if (newTileYCoord < 0) {
		newTileYCoord += 15;
		newYCoord--;
	}
	if (newXCoord != e.xCoord || newYCoord != e.yCoord) {

		if (isValidCoordinate(newXCoord, newYCoord)) {
			Tile* newTile = get(newXCoord, newYCoord);
			if (newTile->object == nullptr || newTile->object->canWalkOn == true) {
				if (newTile->entity == nullptr) {
					Tile* t = get(e.xCoord, e.yCoord);
					newTile->entity = std::move(t->entity);
					t->entity = nullptr;
					e.xCoord = newXCoord;
					e.yCoord = newYCoord;
					e.tileXCoord = newTileXCoord;
					e.tileYCoord = newTileYCoord;
				}
			}
		}
	}
	else {
		e.tileXCoord = newTileXCoord;
		e.tileYCoord = newTileYCoord;
	}

}

Tile* GameMap::tileInFrontof(Entity& e) {
	switch (e.directionFacing) {
	case Direction::NORTH:
		return get(e.xCoord, e.yCoord - 1);
	case Direction::EAST:
		return get(e.xCoord + 1, e.yCoord);
	case Direction::SOUTH:
		return get(e.xCoord, e.yCoord + 1);
	case Direction::WEST:
		return get(e.xCoord - 1, e.yCoord);
	default:
		return nullptr;
	}
}


void GameMap::dropItem(Entity& e, int inventoryIndex) {
	Tile* t = get(e.xCoord, e.yCoord);
	Human& h = static_cast<Human&>(e);
	if (inventoryIndex < (int)h.inventory.size() && inventoryIndex >= 0) {
		t->items.push_back(h.inventory[inventoryIndex]);
		h.inventory.erase(h.inventory.begin() + inventoryIndex);
	}

}


void GameMap::pickUpItem(Entity& e, int tileItemsIndex) {
	Tile* t = get(e.xCoord, e.yCoord);
	Human& h = static_cast<Human&>(e);
	if (tileItemsIndex < (int)t->items.size() && tileItemsIndex >= 0) {
		h.inventory.push_back(t->items[tileItemsIndex]);
		t->items.erase(t->items.begin() + tileItemsIndex);
	}
}







