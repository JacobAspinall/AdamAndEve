#include "GameMap.h"
#include "InitializeMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameWindow.h"
#include "Human.h"

void readUserInput(GameWindow& map);

int main() {
	
	//std::cout << COLOR_PAIRS << std::endl;
	//while (1) {}
	GameMap map = GameMap();
	initializeMap(map);
	map.player = std::make_shared<Human>(MAN);
	std::shared_ptr<Tile> t = std::make_shared<Grass>();
	t->entity = map.player;
	map.set(10, 10, t);

	GameWindow mainWindow = GameWindow(map);
	mainWindow.init();

	
	while (1) {
		mainWindow.render();
		readUserInput(mainWindow);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		
	}

}

void readUserInput(GameWindow& window) {

	char input;
	flushinp();
	input = getch();
	
	switch (input) {
		case 'w':
			window.panNorth();
			break;
		case 'a':
			window.panWest();
			break;
		case 's':
			window.panSouth();
			break;
		case 'd':
			window.panEast();
			break;
		default:
			break;
	}


}