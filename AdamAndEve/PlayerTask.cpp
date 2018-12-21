#include "PlayerTask.h"
#include "Player.h"
#include "Entity.h"
#include "GameMap.h"
#include "Interact.h"





PlayerTask::~PlayerTask()
{
}


int PlayerTask::run() {

	Player& player = static_cast<Player&>(entity);

	switch (player.nextMove) {

	case MoveType::NoAction:
		break;
	case MoveType::North:
		map.moveEntityNorth(entity);
		break;
	case MoveType::East:
		map.moveEntityEast(entity);
		break;
	case MoveType::South:
		map.moveEntitySouth(entity);
		break;
	case MoveType::West:
		map.moveEntityWest(entity);
		break;
	case MoveType::Interact:
		entity.setCurrentTask(std::move(getInteractTask(entity, map)));
		break;
	}
	return 1;
}
