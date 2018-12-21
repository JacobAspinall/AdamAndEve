#pragma once
#include "Task.h"

//Causes entity to do a random walk
class WalkRandomly :
	public Task
{
public:
	WalkRandomly(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~WalkRandomly();
	int run();
};

