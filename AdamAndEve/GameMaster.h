#pragma once
#include "GameMap.h"
#include "Entity.h"
#include "Player.h"
#include "InitializeMap.h"
#include <vector>
#include <queue>

class MoveQueueComparator {
public:
	bool operator()(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2) {
		return e1->timeOfNextMove > e2->timeOfNextMove;
	}
};

class GameMaster
{
public:
	GameMaster();
	~GameMaster();
	void runNextMove();


	GameMap map;
	std::priority_queue<std::shared_ptr<Entity>, std::vector<std::shared_ptr<Entity>>, MoveQueueComparator> moveQueue;
	std::vector<std::shared_ptr<Entity>> entityList;
	std::shared_ptr<Player> player;
	long long gameTurn = 0;

};


