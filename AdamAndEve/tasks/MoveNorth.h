#pragma once
#include "Task.h"
class MoveNorth :
	public Task
{
public:
	MoveNorth(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~MoveNorth();
	int run();
};

