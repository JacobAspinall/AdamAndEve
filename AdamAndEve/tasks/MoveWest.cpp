#include "MoveWest.h"
#include "Entity.h"
#include "GameMap.h"





MoveWest::~MoveWest()
{
}

int MoveWest::run() {
	map.moveEntityWest(entity);
	entity.endCurrentTask();
	return 1;
}
