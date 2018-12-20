#pragma once
#include "Task.h"

//Causes entity to do a random walk
class WalkRandomly :
	public Task
{
public:
	WalkRandomly(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap);
	~WalkRandomly();
	int run();
};

