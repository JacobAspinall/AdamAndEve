#include "WalkRandomly.h"
#include "Entity.h"
#include "GameMap.h"
#include "MoveNorth.h"
#include "MoveEast.h"
#include "MoveSouth.h"
#include "MoveWest.h"
#include <random>




WalkRandomly::~WalkRandomly()
{
}


int WalkRandomly::run() {

	Human& human = static_cast<Human&>(entity);
	static std::default_random_engine generator;
	static std::uniform_int_distribution<int> distribution(0, 4);

	switch (distribution(generator)) {

	case 0:
		break;
	case 1:
		human.setCurrentTask(std::move(std::make_unique<MoveNorth>(entity, map)));
		break;
	case 2:
		human.setCurrentTask(std::move(std::make_unique<MoveEast>(entity, map)));
		break;
	case 3:
		human.setCurrentTask(std::move(std::make_unique<MoveSouth>(entity, map)));
		break;
	case 4:
		human.setCurrentTask(std::move(std::make_unique<MoveWest>(entity, map)));
		break;
	}

	return 10;

}