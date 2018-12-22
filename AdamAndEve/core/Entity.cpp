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
	return taskQueue.front().get()->run();
}

void Entity::setCurrentTask(std::unique_ptr<Task> t) {
	if(t != nullptr)
		taskQueue.emplace_front(std::move(t));
}

void Entity::endCurrentTask() {
	taskQueue.pop_front();
}
