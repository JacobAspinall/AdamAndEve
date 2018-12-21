#pragma once
#include "Task.h"

//Moves player based upon its next move
class PlayerTask :
	public Task
{
public:
	PlayerTask(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~PlayerTask();
	int run();
};

