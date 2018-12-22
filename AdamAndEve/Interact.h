#pragma once
#include "Task.h"
class Interact :
	public Task
{
public:
	Interact(Entity& e, GameMap& myMap) : Task(e, myMap) {};
	~Interact();
	int run();
};

