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
	curs_set(0);
	timeout(1);
	start_color();
	refresh();

}

void GameWindow::render() {
	std::string output = "";
	int topLeftXCoord = centerXCoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = centerYCoord - MAP_DISPLAY_HEIGHT / 2;
	int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	int currentRow = 0;
	int currentCol = 0;
	bool validCoord = false;
	int currentColorPair = 1;
	int foregroundColor;
	int backgroundColor;

	for (int i = topLeftYCoord; i < bottomLeftYCoord; i++) {
		for (int j = topLeftXCoord; j < topRightXCoord; j++) {
			//Check for map bounds
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				std::shared_ptr<Tile> tileToPrint = map.get(j, i);
				if (tileToPrint->entity == nullptr) {
					output += getSymbol(tileToPrint->object);
					foregroundColor = getColor(tileToPrint->object);
				}
				else {
					output += getSymbol(tileToPrint->entity);
					foregroundColor = getColor(tileToPrint->entity);
				}
				
				backgroundColor = getColor(tileToPrint);

				//Turn on color
				auto search = colorPairs.find((foregroundColor << 16) | backgroundColor);
				if (search != colorPairs.end()) {
					attron(COLOR_PAIR(search->second));
					currentColorPair = search->second;
				}
				else {
					init_pair(colorPairs.size() + 1, foregroundColor, backgroundColor);
					colorPairs.insert({ ((foregroundColor) << 16) | backgroundColor , colorPairs.size() + 1 });
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
	refresh();
}

int GameWindow::getColor(std::shared_ptr<Tile> t) {
	if (t == nullptr)
		return EMPTY_SYMBOL;

	switch (t->type) {
	case TileType::Grass:
		return GRASS_COLOR;
	case TileType::Sand:
		return SAND_COLOR;
	default:
		return COLOR_BLACK;

	}
}

int GameWindow::getColor(std::shared_ptr<Object> o) {
	if (o == nullptr)
		return EMPTY_SYMBOL;

	switch (o->type) {
	case ObjectType::Tree:
		return TREE_COLOR;
	default:
		return COLOR_BLACK;
	}
}

char GameWindow::getSymbol(std::shared_ptr<Object> o) {

	if (o == nullptr)
		return EMPTY_SYMBOL;

	switch (o->type) {
	case ObjectType::Tree:
		return TREE_SYMBOL;
	default:
		return EMPTY_SYMBOL;
	}
}

int GameWindow::getColor(std::shared_ptr<Entity> e) {
	if (e == nullptr)
		return EMPTY_SYMBOL;

	switch (e->type) {
	case EntityType::Human:
		if ((std::dynamic_pointer_cast<Human>(e))->isMan()) {
			return MAN_COLOR;
		}
		else {
			return WOMAN_COLOR;
		}
	default:
		return COLOR_BLACK;
	}
}

char GameWindow::getSymbol(std::shared_ptr<Entity> e) {
	if (e == nullptr)
		return EMPTY_SYMBOL;

	switch (e->type) {
	case EntityType::Human:
		//Human h = *e;
		if ((std::dynamic_pointer_cast<Human>(e))->isMan()) {
			return MAN_SYMBOL;
		}
		else {
			return WOMAN_SYMBOL;
		}
		
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