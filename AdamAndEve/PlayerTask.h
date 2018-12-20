#pragma once
#include "Task.h"
class PlayerTask :
	public Task
{
public:
	PlayerTask(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> map);
	~PlayerTask();
	int run();
};

