#pragma once
#include "TileType.h"
#include "curses.h"
#include "Object.h"
#include "Entity.h"
#include "Item.h"
#include <memory>
#include <vector>

//Abstract class to represent the ground of each tile on the game map
//e.g. grass, water, sand, etc.
//

class Tile
{
public:
	Tile();
	virtual ~Tile();
	void removeObject();
	TileType type;
	std::shared_ptr<Object> object;
	std::shared_ptr<Entity> entity;
	std::vector<std::shared_ptr<Item>> items;


};

