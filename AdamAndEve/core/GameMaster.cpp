#include "GameMaster.h"
#include "PlayerTask.h"
#include "WalkRandomly.h"



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

void GameMaster::setNextMove(MovementVector t) {
		player.lock()->nextMove = t;
	
}
