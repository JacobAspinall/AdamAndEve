#pragma once
#include "Task.h"
class MoveWest :
	public Task
{
public:
	MoveWest(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~MoveWest();
	int run();
};

