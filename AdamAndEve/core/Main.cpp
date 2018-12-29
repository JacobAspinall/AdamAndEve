#include "GameMaster.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"
#include "Player.h"
#include "SDL.h"


void readUserInput(SDL_Event* e, Player& p, GameMap& map);

int main(int argc, char *args[]) {
	
	GameMaster game = GameMaster();


	GameWindow mainWindow = GameWindow(game.map, game);
	mainWindow.player = game.player;
	mainWindow.init();
	bool quit = false;
	
	
	while(!quit) {
		SDL_Event e;
		bool startOfTick = true;
		game.setNextMove(MoveType::NoAction);
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			if (e.type == SDL_SCANCODE_GRAVE) {
				mainWindow.devConsoleEnabled = !mainWindow.devConsoleEnabled;
				break;
			}
			if (mainWindow.devConsoleEnabled == false) {
				mainWindow.KeyPressHandler(e, startOfTick);
				startOfTick = false;
			}
			//if (mainWindow.devConsoleEnabled == true) {
			//	readUserInputForDevConsole();
			//}


		}

		
		game.runNextMove();
		mainWindow.cameraXcoord = game.player.lock()->xCoord;
		mainWindow.cameraYcoord = game.player.lock()->yCoord;

		//Clear screen
		SDL_RenderClear(mainWindow.renderer);

		mainWindow.render();

		//Update screen
		SDL_RenderPresent(mainWindow.renderer);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));


	}

	return 0;

}


//Reads user input and sets the players next move
//-non-blocking
void readUserInput(SDL_Event* e, Player& p) {
	
	if (e == nullptr) {
		p.nextMove = MoveType::NoAction;
		return;
	}


	if (e->type == SDL_KEYDOWN)
	{
		//Select surfaces based on key press
		switch (e->key.keysym.sym)
		{
		case SDLK_w:
			p.nextMove = MoveType::North;
			break;

		case SDLK_a:
			p.nextMove = MoveType::West;
			break;

		case SDLK_s:
			p.nextMove = MoveType::South;
			break;

		case SDLK_d:
			p.nextMove = MoveType::East;
			break;

		case SDLK_f:
			p.nextMove = MoveType::Interact;
			break;

		case SDLK_o:
			//map.dropItem(p, (int)p.inventory.size() - 1);
			break;

		case SDLK_p:
			//map.pickUpItem(p, (int)map.get(p.xCoord, p.yCoord)->items.size() - 1);
			break;

		default:
			p.nextMove = MoveType::NoAction;
			break;
		}
	}

}

void readUserInputForDevConsole() {


}