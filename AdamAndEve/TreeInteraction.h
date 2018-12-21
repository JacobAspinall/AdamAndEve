#pragma once
#include "Task.h"
#include "Tile.h"
class TreeInteraction :
	public Task
{
public:
	TreeInteraction(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~TreeInteraction();

	int run();
	bool startedChopping = false;
};

