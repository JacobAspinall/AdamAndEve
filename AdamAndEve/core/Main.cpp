#include "GameMaster.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"
#include "Player.h"
#include "SDL.h"



int main(int argc, char *args[]) {
	
	GameMaster game = GameMaster();

	Window mainWindow = Window();
	mainWindow.init();

	GameWindow gameWindow = GameWindow(game.map, game, mainWindow);
	gameWindow.player = game.player;

	bool quit = false;
	while (!quit) {

		SDL_Event e;
		gameWindow.startOfTick = true;
		game.setNextMove(MoveType::NoAction);
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			if (e.type == SDL_SCANCODE_GRAVE) {
				//mainWindow.devConsoleEnabled = !mainWindow.devConsoleEnabled;
				//break;
			}
	
			mainWindow.handleEvent(e);

		}




		
		
		game.runNextMove();
		gameWindow.cameraXcoord = game.player.lock()->xCoord;
		gameWindow.cameraYcoord = game.player.lock()->yCoord;
		mainWindow.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	
	}



	/*
	GameWindow mainWindow = GameWindow(game.map, game);
	mainWindow.player = game.player;
	mainWindow.init();
	bool quit = false;
	std::vector<Window*> openWindows;
	openWindows.push_back(&mainWindow);
	
	
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
	*/
	return 0;

}