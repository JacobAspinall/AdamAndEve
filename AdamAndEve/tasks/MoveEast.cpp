#include "MoveEast.h"
#include "Entity.h"
#include "GameMap.h"




MoveEast::~MoveEast()
{
}

int MoveEast::run() {
	map.moveEntityEast(entity);
	entity.endCurrentTask();
	return 1;
}
