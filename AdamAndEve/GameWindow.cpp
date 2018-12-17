#include "GameWindow.h"



GameWindow::GameWindow(GameMap map)
	:map{ map }
{

}


GameWindow::~GameWindow()
{
}

void GameWindow::init() {
	initscr();
	noecho();
	start_color();
	refresh();

}

void GameWindow::refresh() {
	std::string output = "";
	int topLeftXCoord = centerXCoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = centerYCoord - MAP_DISPLAY_HEIGHT / 2;
	int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	int currentRow = 0;
	int currentCol = 0;
	bool validCoord = false;
	int currentColorPair = 1;

	for (int i = topLeftYCoord; i < bottomLeftYCoord; i++) {
		for (int j = topLeftXCoord; j < topRightXCoord; j++) {
			//Check for map bounds
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				output += getSymbol(map.get(i, j).object.type);
				int foregroundColor = getColor(map.get(i, j).object.type);
				int backgroundColor = getColor(map.get(i, j).type);

				//Turn on color
				auto search = colorPairs.find((foregroundColor << 16) & backgroundColor);
				if (search != colorPairs.end()) {
					attron(COLOR_PAIR(search->second));
					currentColorPair = search->second;
				}
				else {
					init_pair(colorPairs.size() + 1, foregroundColor, backgroundColor);
					colorPairs.insert({ ((foregroundColor) << 16) & backgroundColor , colorPairs.size() + 1 });
					attron(COLOR_PAIR(colorPairs.size()));
					currentColorPair = colorPairs.size();
				}
				
				
				validCoord = true;
			}
			else {
				output += ' ';
			}

			mvprintw(currentRow, currentCol, output.c_str());
			//Turn off color
			if (validCoord) {
				attroff(COLOR_PAIR(currentColorPair));
				//currentColorPair++;
			}
			validCoord = false;

			currentCol++;
			output = "";
		}
		currentRow++;
		currentCol = 0;


	}

}

int GameWindow::getColor(TileType t) {

	switch (t) {
	case TileType::Grass:
		return GRASS_COLOR;
	case TileType::Sand:
		return SAND_COLOR;

	}
}

int GameWindow::getColor(ObjectType t) {

	switch (t) {
	case ObjectType::Tree:
		return TREE_COLOR;
	}
}

char GameWindow::getSymbol(ObjectType t) {

	switch (t) {
	case ObjectType::Tree:
		return TREE_SYMBOL;
	default:
		return ' ';
	}
}

void GameWindow::panNorth() {
	if (map.isValidCoordinate(centerXCoord, centerYCoord - 1))
		centerYCoord -= 1;
}

void GameWindow::panEast() {
	if (map.isValidCoordinate(centerXCoord + 1, centerYCoord + 1))
		centerXCoord += 1;
}

void GameWindow::panSouth() {
	if (map.isValidCoordinate(centerXCoord, centerYCoord + 1))
		centerYCoord += 1;
}

void GameWindow::panWest() {
	if (map.isValidCoordinate(centerXCoord - 1, centerYCoord))
		centerXCoord -= 1;
}

void initColorPairs() {


}