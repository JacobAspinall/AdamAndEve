#pragma once
#include "Tile.h"
class Water :
	public Tile
{
public:
	Water();
	~Water();
	int interact(Entity& e, GameMap& myMap);

	bool startedFishing = false;
};

