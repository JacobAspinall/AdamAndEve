#include "MoveNorth.h"
#include "Entity.h"
#include "GameMap.h"





MoveNorth::~MoveNorth()
{
}

int MoveNorth::run() {
	map.moveEntityNorth(entity);
	entity.endCurrentTask();
	return 1;
}
