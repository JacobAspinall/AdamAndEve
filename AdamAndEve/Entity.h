#pragma once
#include "EntityType.h"
#include "Task.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void makeMove();

	EntityType type = EntityType::Empty;
	std::unique_ptr<Task> task;

	int xCoord;
	int yCoord;


};

