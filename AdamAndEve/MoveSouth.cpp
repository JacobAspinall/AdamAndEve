#include "MoveSouth.h"
#include "Entity.h"
#include "GameMap.h"





MoveSouth::~MoveSouth()
{
}

int MoveSouth::run() {
	map.moveEntitySouth(entity);
	entity.endCurrentTask();
	return 1;
}
