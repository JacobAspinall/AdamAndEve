#include "GameMaster.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"
#include "Player.h"
#include "SDL.h"
#include "DevConsole.h"
#include <thread>

void GUI_thread(GameMaster& game);
void game_thread(GameMaster& game);

int main(int argc, char *args[]) {
	
	GameMaster game = GameMaster();
	

	std::thread gui_thread(GUI_thread, std::ref(game));

	while (1) {
		std::thread game_thread(game_thread, std::ref(game));
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		game_thread.join();
	}

	
	return 0;
}

void game_thread(GameMaster& game) {
	game.map.mapMutex->lock();
	game.runNextMove();
	game.map.mapMutex->unlock();
	
}


void GUI_thread(GameMaster& game) {
	Window mainWindow = Window();
	mainWindow.init();

	GameWindow gameWindow = GameWindow(game.map, game, mainWindow);
	gameWindow.player = game.player;

	DevConsole devConsole = DevConsole(game, mainWindow);
	bool devConsoleOn = false;
	bool madeMove = false;
	bool quit = false;
	while (!quit) {
		
		SDL_Event e;
		gameWindow.startOfTick = true;
		//game.setNextMove(MoveType::NoAction);
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_BACKQUOTE) {
				if (!devConsoleOn) {
					SDL_StartTextInput();
					mainWindow.screens.push_back(&devConsole);
					devConsoleOn = true;
				}
				else {
					SDL_StopTextInput();
					mainWindow.screens.pop_back();
					devConsoleOn = false;
				}
			}
			mainWindow.handleEvent(&e);
			madeMove = true;
		}

		if (!madeMove) {
			mainWindow.handleEvent(NULL);
		}
		else {
			madeMove = false;
		}

		
		gameWindow.cameraXcoord = game.player.lock()->xCoord;
		gameWindow.cameraYcoord = game.player.lock()->yCoord;
		mainWindow.drawWindow();

	}
	
}