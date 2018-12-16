#include "GameMap.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "curses.h"

void readUserInput(GameMap& map);

int main() {
	GameMap map = GameMap();
	initscr();
	noecho();
	start_color();
	while (1) {
		map.displayMap();
		refresh();
		readUserInput(map);
		//std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

}

void readUserInput(GameMap& map) {

	char input;
	input = getch();

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