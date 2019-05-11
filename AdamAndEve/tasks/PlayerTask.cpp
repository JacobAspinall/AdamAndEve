#include "PlayerTask.h"
#include "Player.h"
#include "Entity.h"
#include "GameMap.h"
#include "Interact.h"
#include "Move.h"





PlayerTask::~PlayerTask()
{
}


int PlayerTask::run() {

	Player& player = static_cast<Player&>(entity);
	if (player.nextMove.type == MoveType::NoAction)
		return 1;
	else if (player.nextMove.type == MoveType::Move) {
		player.setCurrentTask(std::move(std::make_unique<Move>(entity, map, player.nextMove.direction)));
	}
	else if (player.nextMove.type == MoveType::Interact) {
		entity.setCurrentTask(std::move(std::make_unique<Interact>(entity, map)));
		player.nextMove = MoveType::NoAction;
	}

	return 0;
}
