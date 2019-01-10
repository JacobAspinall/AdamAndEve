#pragma once
#include "Task.h"
#include "MoveType.h"
#include "MovementVector.h"
class Move :
	public Task
{
public:
	Move(Entity& e, GameMap& myMap, MovementVector direction) : direction{ direction }, Task(e, myMap) { isMovementTask = true; };
	~Move();
	int run();
	MovementVector direction;
};

