#pragma once
#include "Task.h"
class MoveSouth :
	public Task
{
public:
	MoveSouth(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~MoveSouth();
	int run();
};

