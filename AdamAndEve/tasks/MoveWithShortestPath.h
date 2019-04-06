#pragma once
#include "Task.h"
class MoveWithShortestPath :
	public Task
{
public:
	MoveWithShortestPath(Entity& e, GameMap& myMap, int xDestination, int yDestination, int innerXDestination, int innerYDestination) : xDestination { xDestination }, yDestination{ yDestination }, innerXDestination{ innerXDestination }, innerYDestination{ innerYDestination }, Task(e, myMap) {isMovementTask = true; };
	~MoveWithShortestPath();

	int run();
	int xDestination;
	int yDestination;
	int innerXDestination;
	int innerYDestination;
};

