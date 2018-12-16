#pragma once
#include "TileType.h"
#include "curses.h"
class Tile
{
public:
	Tile();
	virtual ~Tile();
	TileType type;
	char symbol;
	int foregroundColor;
	int backgroundColor;
	int colorPair;
};

