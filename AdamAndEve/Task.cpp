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

void Task::run() {

}
