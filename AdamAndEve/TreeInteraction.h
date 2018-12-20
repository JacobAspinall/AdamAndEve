#pragma once
#include "Task.h"
#include "Tile.h"
class TreeInteraction :
	public Task
{
public:
	TreeInteraction(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap);
	~TreeInteraction();

	int run();
	bool startedChopping = false;
};

