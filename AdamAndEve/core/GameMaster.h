#pragma once
#include "GameMap.h"
#include "Entity.h"
#include "Player.h"
#include "InitializeMap.h"
#include <vector>
#include <queue>
#include "PlayerMove.h"

//In charge of executing the required actions each game tick.
//-Run the next move for each entity scheduled to move on a turn, and reshedule them afterwards.
//
//Example:
//		GameMaster g = GameMaster();
//		while (1) {
//			g.runNextMove();
//		}
//

class MoveQueueComparator {
public:
	bool operator()(std::weak_ptr<Entity> e1, std::weak_ptr<Entity> e2) {
		return e1.lock()->timeOfNextMove > e2.lock()->timeOfNextMove;
	}
};

class GameMaster
{
public:
	GameMaster();
	~GameMaster();
	void runNextMove();
	void setNextMove(PlayerMove m);
	void movePlayerToCoords(int xCoord, int yCoord, int innerXCoord, int innerYCoord);
	bool hasObject(int xCoord, int yCoord, int innerXCoord, int innerYCoord);
	void interactWithObject(int xCoord, int yCoord, int innerXCoord, int innerYCoord);
	void interactWithTile(int xCoord, int yCoord, int innerXCoord, int innerYCoord);
	void facePlayerTowards(int xCoord, int yCoord, int innerXCoord, int innerYCoord);
	bool tileIsNextToPlayer(int xCoord, int yCoord);
	std::vector<ItemType> getPlayerInventory();
	void setSelectedItem(int inventoryPosition);
	void dropItem(Entity& e, int intentoryIndex);
	void pickUpItem(Entity& e, int intentoryIndex);


	GameMap map;
	std::priority_queue<std::weak_ptr<Entity>, std::vector<std::weak_ptr<Entity>>, MoveQueueComparator> moveQueue;
	std::vector<std::weak_ptr<Entity>> entityList;
	std::weak_ptr<Player> player;
	long long gameTurn = 0;

};


