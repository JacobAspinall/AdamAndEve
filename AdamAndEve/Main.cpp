#include "GameMap.h"
#include <chrono>
#include <thread>
#include <iostream>
//#include "include/curses.h"

void readUserInput(GameMap& map);

int main() {
	GameMap map = GameMap();

	while (1) {
		map.displayMap();
		//clear();
		readUserInput(map);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

}

void readUserInput(GameMap& map) {

	char input;
	std::cin >> input;

	switch (input) {
		case 'w':
			map.panNorth();
			break;
		case 'a':
			map.panWest();
			break;
		case 's':
			map.panSouth();
			break;
		case 'd':
			map.panEast();
			break;
		default:
			break;
	}


}