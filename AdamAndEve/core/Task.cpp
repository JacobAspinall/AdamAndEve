#include "Task.h"




Task::Task(Entity& e, GameMap& myMap) 
	:entity(e), map(myMap)
{

}


Task::~Task()
{
}


//Calculates an entitys next move and updates the game map
//reutrn: number of ticks until entity needs to be updated again
int Task::run() {
	return 1;
}
