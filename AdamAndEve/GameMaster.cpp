#include "GameMaster.h"
#include "PlayerTask.h"
#include "WalkRandomly.h"


//In charge of executing the required actions each game tick.
//-Run the next move for each entity scheduled to move on a turn, and reshedule them afterwards.
//
//Example:
//		GameMaster g = GameMaster();
//		while (1) {
//			g.runNextMove();
//		}
//
GameMaster::GameMaster()
{
	initializeMap(map);
	player = std::make_shared<Player>(MAN);
	std::shared_ptr<Tile> t = std::make_shared<Grass>();
	t->entity = player;
	map.set(10, 10, t);

	player->taskQueue.emplace_front(std::make_unique<PlayerTask>(player, std::make_shared<GameMap>(map)));
	player->xCoord = 10;
	player->yCoord = 10;

	entityList.push_back(player);
	moveQueue.push(player);

	//Make myself a wife
	std::shared_ptr<Tile> wifeTile = std::make_shared<Grass>();
	std::shared_ptr<Human> wifey = std::make_shared<Human>(WOMAN);
	wifeTile->entity = wifey;
	map.set(11, 11, wifeTile);

	wifey->taskQueue.emplace_front(std::make_unique<WalkRandomly>(wifey, std::make_shared<GameMap>(map)));
	wifey->xCoord = 11;
	wifey->yCoord = 11;

	entityList.push_back(wifey);
	moveQueue.push(wifey);


}


GameMaster::~GameMaster()
{
}

//Runs the next move of the game
//Updates every Entity on the game map that is scheduled to move on the next move.
void GameMaster::runNextMove() {
	while (moveQueue.top()->timeOfNextMove <= gameTurn) {
		std::shared_ptr<Entity> e = moveQueue.top();
		moveQueue.pop();
		int timeUntilNextTurn = e->makeMove();
		e->timeOfNextMove = gameTurn + timeUntilNextTurn;
		moveQueue.push(e);
	}
	gameTurn++;

}
