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

//	if(player.nextMove != MoveType::Interact)
	player.setCurrentTask(std::move(std::make_unique<Move>(entity, map, player.nextMove)));
	//else if(player.nextMove != MoveType::Interact)
	//	entity.setCurrentTask(std::move(std::make_unique<Interact>(entity, map)));

	return 0;
}
