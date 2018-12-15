#pragma once
#include "TileType.h"
class Tile
{
public:
	Tile();
	virtual ~Tile();
	TileType type;
	char symbol;
};

