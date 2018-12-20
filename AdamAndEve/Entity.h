#pragma once
#include "EntityType.h"

#include <list>
#include "Task.h"
#include <memory>
#include "Direction.h"

//Abstract class to represent anything that is run by AI.
//e.g. a human or a chicken
//When using this class, initialize it as a pointer to one of its derived classes to prevent object slicing
//
//Example:
//		std::unique_ptr<Entity> e = std::make_unique<Human>(MAN);
//
class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual int makeMove();
	virtual void setCurrentTask(std::unique_ptr<Task> t);
	virtual void endCurrentTask();

	EntityType type = EntityType::Empty;
	std::list<std::unique_ptr<Task>> taskQueue;

	int xCoord;
	int yCoord;
	long long timeOfNextMove = 0;
	Direction directionFacing = Direction::NORTH;



};

