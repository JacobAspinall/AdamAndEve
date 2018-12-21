#include "GameWindow.h"



GameWindow::GameWindow(GameMap& map)
	:map{ map }
{

}


GameWindow::~GameWindow()
{
}

//Runs necessary initialization functions from PDcurses
void GameWindow::init() {
	initscr();
	noecho();
	curs_set(0);
	timeout(1);
	start_color();
	refresh();

}

//displays map on terminal based upon the camera's x and y coords
void GameWindow::render() {
	std::string output = "";
	int topLeftXCoord = cameraXcoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = cameraYcoord - MAP_DISPLAY_HEIGHT / 2;
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
				Tile* tileToPrint = map.get(j, i);
				if (tileToPrint->entity == nullptr) {
					output += getSymbol(tileToPrint->object.get());
					foregroundColor = getColor(tileToPrint->object.get());
				}
				else {
					output += getSymbol(tileToPrint->entity.get());
					foregroundColor = getColor(tileToPrint->entity.get());
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
	//Print coords
	std::string coords = "(" + std::to_string(cameraXcoord) + ", " + std::to_string(cameraYcoord) + ")";
	mvprintw(0, 0, coords.c_str());
	refresh();
}

//Returns the color used for a tile
int GameWindow::getColor(Tile* t) {
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

//Returns the color used for am object
int GameWindow::getColor(Object* o) {
	if (o == nullptr)
		return EMPTY_SYMBOL;

	switch (o->type) {
	case ObjectType::Tree:
		return TREE_COLOR;
	default:
		return COLOR_BLACK;
	}
}

//Returns the character that wil be displayed for an object
char GameWindow::getSymbol(Object* o) {

	if (o == nullptr)
		return EMPTY_SYMBOL;

	switch (o->type) {
	case ObjectType::Tree:
		return TREE_SYMBOL;
	default:
		return EMPTY_SYMBOL;
	}
}

//Returns the color used for am entity
int GameWindow::getColor(Entity* e) {
	if (e == nullptr)
		return EMPTY_SYMBOL;

	switch (e->type) {
	case EntityType::Human:
		if ((static_cast<Human*>(e))->isMan()) {
			return MAN_COLOR;
		}
		else {
			return WOMAN_COLOR;
		}
	default:
		return COLOR_BLACK;
	}
}

//Returns the character that wil be displayed for an entity
char GameWindow::getSymbol(Entity* e) {
	if (e == nullptr)
		return EMPTY_SYMBOL;

	switch (e->type) {
	case EntityType::Human:
		//Human h = *e;
		if ((static_cast<Human*>(e))->isMan()) {
			return MAN_SYMBOL;
		}
		else {
			return WOMAN_SYMBOL;
		}
		
	default:
		return ' ';
	}
}

//Centers camera one tile to the north and re-renders the screen
void GameWindow::panCameraNorth() {
	if (map.isValidCoordinate(cameraXcoord, cameraYcoord - 1))
		cameraYcoord -= 1;
	render();
}

//Centers camera one tile to the east and re-renders the screen
void GameWindow::panCameraEast() {
	if (map.isValidCoordinate(cameraXcoord + 1, cameraYcoord + 1))
		cameraXcoord += 1;
	render();
}

//Centers camera one tile to the south and re-renders the screen
void GameWindow::panCameraSouth() {
	if (map.isValidCoordinate(cameraXcoord, cameraYcoord + 1))
		cameraYcoord += 1;
	render();
}

//Centers camera one tile to the west and re-renders the screen
void GameWindow::panCameraWest() {
	if (map.isValidCoordinate(cameraXcoord - 1, cameraYcoord))
		cameraXcoord -= 1;
	render();
}
