#pragma once
#include "Task.h"
#include "MovementVector.h"
class MoveInStraightLine :
	public Task
{
public:
	MoveInStraightLine(Entity& e, GameMap& myMap, int xDestination, int yDestination) : xDestination{ xDestination }, yDestination{ yDestination }, Task(e, myMap) {isMovementTask = true; };
	~MoveInStraightLine();
	int run();
	int xDestination;
	int yDestination;
};

