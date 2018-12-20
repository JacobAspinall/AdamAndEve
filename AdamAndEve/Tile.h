#pragma once
#include "TileType.h"
#include "curses.h"
#include "Object.h"
#include "Entity.h"
#include <memory>

//Abstract class to represent the ground of each tile on the game map
//e.g. grass, water, sand, etc.
//When using this class, initialize it as a pointer to one of its derived classes to prevent object slicing
//
//Example:
//		std::unique_ptr<Tile> e = std::make_unique<Grass>();
//

class Tile
{
public:
	Tile();
	virtual ~Tile();
	TileType type;
	std::shared_ptr<Object> object;
	std::shared_ptr<Entity> entity;


};

