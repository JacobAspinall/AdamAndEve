#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

//Runs task at the top of the entitys task queue.
//
//return: number of game ticks until the task needs to be run again
int Entity::makeMove() {
	return taskQueue.front()->run();
}
