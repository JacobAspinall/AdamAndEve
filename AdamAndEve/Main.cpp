#include "GameMaster.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"
#include "Player.h"

void readUserInput(std::shared_ptr<Player> p);

int main() {
	
	GameMaster game = GameMaster();


	GameWindow mainWindow = GameWindow(game.map);
	mainWindow.init();

	
	while (1) {
		mainWindow.centerXCoord = game.player->xCoord;
		mainWindow.centerYCoord = game.player->yCoord;

		mainWindow.render();
		readUserInput(game.player);
		game.runNextMove();
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		
	}

}

void readUserInput(std::shared_ptr<Player> p) {

	char input, finalInput = 0;
	while ((input = getch()) != ERR) {
		finalInput = input;
	}
	
	switch (finalInput) {
		case 'w':
			p->nextMove = MoveType::North;
			break;
		case 'a':
			p->nextMove = MoveType::West;
			break;
		case 's':
			p->nextMove = MoveType::South;
			break;
		case 'd':
			p->nextMove = MoveType::East;
			break;
		default:
			p->nextMove = MoveType::NoAction;
			break;
	}


}