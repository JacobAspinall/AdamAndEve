#include "WalkRandomly.h"
#include "Entity.h"
#include "GameMap.h"
#include "MoveType.h"
#include "Move.h"
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
		//human.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MoveType::North)));
		break;
	case 2:
		//human.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MoveType::East)));
		break;
	case 3:
		//human.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MoveType::South)));
		break;
	case 4:
		//human.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MoveType::West)));
		break;
	}

	return 10;

}