#include "WalkRandomly.h"
#include "Entity.h"
#include "GameMap.h"





WalkRandomly::~WalkRandomly()
{
}


int WalkRandomly::run() {

	Human& human = static_cast<Human&>(entity);

	switch (rand() % 4 + 1) {

	case 0:
		break;
	case 1:
		map.moveEntityNorth(entity);
		break;
	case 2:
		map.moveEntityEast(entity);
		break;
	case 3:
		map.moveEntitySouth(entity);
		break;
	case 4:
		map.moveEntityWest(entity);
		break;
	}

	return 10;

}