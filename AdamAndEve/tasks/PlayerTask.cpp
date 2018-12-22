#include "PlayerTask.h"
#include "Player.h"
#include "Entity.h"
#include "GameMap.h"
#include "Interact.h"
#include "MoveNorth.h"
#include "MoveEast.h"
#include "MoveSouth.h"
#include "MoveWest.h"





PlayerTask::~PlayerTask()
{
}


int PlayerTask::run() {

	Player& player = static_cast<Player&>(entity);

	switch (player.nextMove) {

	case MoveType::NoAction:
		return 1;
		break;
	case MoveType::North:
		player.setCurrentTask(std::move(std::make_unique<MoveNorth>(entity,map)));
		break;
	case MoveType::East:
		player.setCurrentTask(std::move(std::make_unique<MoveEast>(entity, map)));
		break;
	case MoveType::South:
		player.setCurrentTask(std::move(std::make_unique<MoveSouth>(entity, map)));
		break;
	case MoveType::West:
		player.setCurrentTask(std::move(std::make_unique<MoveWest>(entity, map)));
		break;
	case MoveType::Interact:
		entity.setCurrentTask(std::move(std::make_unique<Interact>(entity, map)));
		break;
	}
	return 0;
}
