#include "WalkRandomly.h"
#include "Entity.h"
#include "GameMap.h"


WalkRandomly::WalkRandomly(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap)
{
	entity = e;
	map = myMap;
}


WalkRandomly::~WalkRandomly()
{
}


int WalkRandomly::run() {

	std::shared_ptr<Human> human = std::dynamic_pointer_cast<Human>(entity);

	switch (rand() % 4 + 1) {

	case 0:
		break;
	case 1:
		map->moveEntityNorth(entity);
		break;
	case 2:
		map->moveEntityEast(entity);
		break;
	case 3:
		map->moveEntitySouth(entity);
		break;
	case 4:
		map->moveEntityWest(entity);
		break;
	}

	return 10;

}