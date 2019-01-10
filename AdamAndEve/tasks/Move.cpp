#include "Move.h"
#include "Entity.h"
#include "GameMap.h"




Move::~Move()
{
}

int Move::run() {

	if (direction.x != 0 || direction.y != 0)
		map.moveEntity(entity, direction);
	entity.endCurrentTask();
	return 1;
}
