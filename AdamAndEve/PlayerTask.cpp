#include "PlayerTask.h"
#include "Player.h"
#include "Entity.h"
#include "GameMap.h"



PlayerTask::PlayerTask(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap)
{
	entity = e;
	map = myMap;
}


PlayerTask::~PlayerTask()
{
}

int PlayerTask::run() {

	std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(entity);

	switch (player->nextMove) {

	case MoveType::NoAction:
		break;
	case MoveType::North:
		map->moveEntityNorth(entity);
		break;
	case MoveType::East:
		map->moveEntityEast(entity);
		break;
	case MoveType::South:
		map->moveEntitySouth(entity);
		break;
	case MoveType::West:
		map->moveEntityWest(entity);
		break;
	case MoveType::Interact:
		break;
	}
	return 1;
}
