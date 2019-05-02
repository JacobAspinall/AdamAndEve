#pragma once
#include "EntityType.h"

#include <list>
#include "Task.h"
#include <memory>
#include "Direction.h"
#include "GameObject.h"

//Abstract class to represent anything that is run by AI.
//e.g. a human or a chicken
//
class Entity:
	public GameObject
{
public:
	Entity();
	virtual ~Entity();
	virtual int makeMove();
	virtual void setCurrentTask(std::unique_ptr<Task> t);
	virtual void endCurrentTask();
	void removeMovementTasks();

	EntityType type = EntityType::Empty;
	std::list<std::unique_ptr<Task>> taskQueue;

	int xCoord;
	int yCoord;
	static const int hitboxRadius = 16;
	double tileXCoord = 15;
	double tileYCoord = 15;
	long long timeOfNextMove = 0;
	Direction directionFacing = Direction::SOUTH;



};

