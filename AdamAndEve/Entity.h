#pragma once
#include "EntityType.h"

#include <list>
#include "Task.h"
#include <memory>

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual int makeMove();

	EntityType type = EntityType::Empty;
	std::list<std::unique_ptr<Task>> taskQueue;

	int xCoord;
	int yCoord;
	long long timeOfNextMove = 0;


};

