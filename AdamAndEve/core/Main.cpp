#include "GameMaster.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"
#include "Player.h"

void readUserInput(Player& p, GameMap& map, GameWindow& gameWindow );

int main() {
	
	GameMaster game = GameMaster();


	GameWindow mainWindow = GameWindow(game.map);
	mainWindow.player = game.player;
	mainWindow.init();

	
	while (1) {
		
		readUserInput(*(game.player.lock()), game.map, mainWindow);
		game.runNextMove();
		mainWindow.cameraXcoord = game.player.lock()->xCoord;
		mainWindow.cameraYcoord = game.player.lock()->yCoord;
		mainWindow.render();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		
		
	}

}


//Reads user input and sets the players next move
//-non-blocking
void readUserInput(Player& p, GameMap& map, GameWindow& gameWindow) {

	char charsSeen = 0;
	char input, finalInput = 0;


	while ((input = getch()) != ERR) {
		finalInput = input;
		charsSeen++;
		if (charsSeen > 3)
			break;

	}
	flushinp();
	
	switch (finalInput) {
		case 'w':
			p.nextMove = MoveType::North;
			break;
		case 'a':
			p.nextMove = MoveType::West;
			break;
		case 's':
			p.nextMove = MoveType::South;
			break;
		case 'd':
			p.nextMove = MoveType::East;
			break;
		case 'f':
			p.nextMove = MoveType::Interact;
			break;
		case 'i':
			if(!gameWindow.displayingInventory)
				gameWindow.displayingInventory = true;
			else
				gameWindow.displayingInventory = false;
			break;
		case 'p':
			map.dropItem(p, (int)p.inventory.size() - 1);
		default:
			p.nextMove = MoveType::NoAction;
			break;
	}


}