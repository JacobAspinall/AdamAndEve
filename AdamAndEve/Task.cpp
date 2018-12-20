#include "Task.h"



Task::Task()
{
}

Task::Task(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap) {
	entity = e;
	map = myMap;
}


Task::~Task()
{
}


//Calculates an entitys next move and updates the game map
//reutrn: number of ticks until entity needs to be updated again
int Task::run() {
	return 1;
}
