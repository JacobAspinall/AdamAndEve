#pragma once
#include "TileType.h"
#include "curses.h"
#include "Object.h"
#include "Entity.h"
#include <memory>
class Tile
{
public:
	Tile();
	virtual ~Tile();
	TileType type;
	std::shared_ptr<Object> object;
	std::shared_ptr<Entity> entity;
};

