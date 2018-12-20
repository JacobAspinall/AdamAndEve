#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

int Entity::makeMove() {
	return taskQueue.front()->run();
}
