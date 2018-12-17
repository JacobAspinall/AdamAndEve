#pragma once
#include "TileType.h"
#include "curses.h"
#include "Object.h"
#include "Entity.h"
class Tile
{
public:
	Tile();
	virtual ~Tile();
	TileType type;
	Object object;
	Entity entity;
};

