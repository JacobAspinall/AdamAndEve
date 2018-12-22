#pragma once
#include "Object.h"
#include "TileType.h"

//Represents a tree
class Tree :
	public Object
{
public:
	Tree();
	~Tree();
	int interact(Entity& e, GameMap& myMap);
	bool startedChopping = false;
};
