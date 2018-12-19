#pragma once
#include "Task.h"
class WalkRandomly :
	public Task
{
public:
	WalkRandomly(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap);
	~WalkRandomly();
	void run();
};

