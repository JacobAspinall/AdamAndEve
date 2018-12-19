#pragma once
#include "GameMap.h"
#include "Entity.h"
#include "Player.h"
# include "InitializeMap.h"
# include <vector>

class GameMaster
{
public:
	GameMaster();
	~GameMaster();
	void runNextMove();


	GameMap map;
	std::vector<std::shared_ptr<Entity>> entityList;
	std::shared_ptr<Player> player;

};

