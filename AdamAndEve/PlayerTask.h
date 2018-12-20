#pragma once
#include "Task.h"

//Moves player based upon its next move
class PlayerTask :
	public Task
{
public:
	PlayerTask(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> map);
	~PlayerTask();
	int run();
};

