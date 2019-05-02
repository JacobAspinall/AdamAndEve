#include "GameMaster.h"
#include "PlayerTask.h"
#include "WalkRandomly.h"
#include "MoveInStraightLine.h"
#include "Interact.h"
#include "StoneAxe.h"
#include "StoneHoe.h"




GameMaster::GameMaster()
{
	initializeMap(map);
	std::shared_ptr<Player> playerSharedPtr = std::make_shared<Player>(Gender::MAN);
	std::unique_ptr<Tile> t = std::make_unique<Grass>();
	t->entity = playerSharedPtr;
	player = playerSharedPtr;
	map.set(10, 10, std::move(t));

	player.lock()->taskQueue.emplace_front(std::make_unique<PlayerTask>(*(std::static_pointer_cast<Entity>(playerSharedPtr)).get(), map));
	player.lock()->xCoord = 10;
	player.lock()->yCoord = 10;


	entityList.push_back(std::weak_ptr<Entity>(playerSharedPtr));
	moveQueue.push(std::weak_ptr<Entity>(playerSharedPtr));

	//Make myself a wife
	std::unique_ptr<Tile> wifeTile = std::make_unique<Grass>();
	std::shared_ptr<Human> wifey = std::make_shared<Human>(Gender::WOMAN);
	wifeTile->entity = wifey;
	map.set(11, 11, std::move(wifeTile));

	wifey->taskQueue.emplace_front(std::make_unique<WalkRandomly>(*(std::static_pointer_cast<Entity>(wifey)).get(), map));
	wifey->xCoord = 11;
	wifey->yCoord = 11;

	entityList.push_back(std::weak_ptr<Entity>(wifey));
	moveQueue.push(std::weak_ptr<Entity>(wifey));

	//Add items
	player.lock()->addItemToInventory(std::make_shared<StoneHoe>());
	player.lock()->addItemToInventory(std::make_shared<StoneAxe>());



}


GameMaster::~GameMaster()
{
}

//Runs the next move of the game
//Updates every Entity on the game map that is scheduled to move on the next move.
void GameMaster::runNextMove() {
	while (moveQueue.top().lock()->timeOfNextMove <= gameTurn) {
		std::shared_ptr<Entity> e = moveQueue.top().lock();
		moveQueue.pop();
		int timeUntilNextTurn = e->makeMove();
		e->timeOfNextMove = gameTurn + timeUntilNextTurn;
		moveQueue.push(e);
	}
	gameTurn++;

}

void GameMaster::setNextMove(PlayerMove m) {
		player.lock()->nextMove = m;
	
}

void GameMaster::movePlayerToCoords(int xCoord, int yCoord, int innerXCoord, int innerYCoord) {
	player.lock()->removeMovementTasks();
	player.lock()->setCurrentTask(std::move(std::make_unique<MoveInStraightLine>(*(player.lock()), map, xCoord, yCoord, innerXCoord, innerYCoord)));
}

bool GameMaster::hasObject(int xCoord, int yCoord, int innerXCoord, int innerYCoord) {
	if (map.get(xCoord, yCoord)->object != nullptr)
		return true;
	else
		return false;
}

void GameMaster::interactWithObject(int xCoord, int yCoord, int innerXCoord, int innerYCoord) {
	player.lock()->setCurrentTask(std::move(std::make_unique<Interact>(*(player.lock()), map)));
}

void GameMaster::facePlayerTowards(int xCoord, int yCoord, int innerXCoord, int innerYCoord) {
	double a = xCoord - player.lock()->xCoord;
	double b = yCoord - player.lock()->yCoord;
	double c = sqrt(a*a + b * b);
	map.assignDirection(*(player.lock()), a / c, b / c);
}

bool GameMaster::tileIsNextToPlayer(int xCoord, int yCoord) {
	if (abs(player.lock()->xCoord - xCoord) <= 1 && abs(player.lock()->yCoord - yCoord) <= 1)
		return true;
	else
		return false;

}

std::vector<ItemType> GameMaster::getPlayerInventory() {
	std::vector<ItemType> items = std::vector<ItemType>();

	for (int i = 0; i < static_cast<int>(player.lock()->inventory.size()); i++) {
		items.push_back(player.lock()->inventory.at(i)->type);
	}
	return items;
}

void GameMaster::setSelectedItem(int inventoryPosition) {
	player.lock()->selectedItem = inventoryPosition;

}
