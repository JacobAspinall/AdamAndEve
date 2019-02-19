#include "WalkRandomly.h"
#include "Entity.h"
#include "GameMap.h"
#include "MoveType.h"
#include "Move.h"
#include <random>
#include "MoveInStraightLine.h"




WalkRandomly::~WalkRandomly()
{
}


int WalkRandomly::run() {

	Human& human = static_cast<Human&>(entity);
	static std::default_random_engine generator;
	static std::uniform_int_distribution<int> distribution(1, 360);

	int angle = distribution(generator); 
		
		human.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MovementVector(std::sin(angle), std::cos(angle)))));


	return 10;

}