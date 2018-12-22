#pragma once
#include "Task.h"
class MoveEast :
	public Task
{
public:
	MoveEast(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~MoveEast();
	int run();
};

