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

	SDL_Init(SDL_INIT_VIDEO);
	mainWindow = SDL_CreateWindow("Adam and Eve", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	texture = Texture(renderer);
	//grassTexture = SDL_LoadBMP("textures/tiles.bmp");
	//SDL_BlitSurface(grassTexture, NULL, mainSurface, NULL);
	//SDL_UpdateWindowSurface(mainWindow);
	//initscr();
	//noecho();
	//curs_set(0);
	//timeout(1);
	//start_color();
	//refresh();

}

//displays map on terminal based upon the camera's x and y coords
void GameWindow::render() {

	int topLeftXCoord = cameraXcoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = cameraYcoord - MAP_DISPLAY_HEIGHT / 2;
	int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	int currentRow = 0;
	int currentCol = 0;
	bool validCoord = false;

	for (int i = topLeftYCoord, screenYindex = 0; i < bottomLeftYCoord; i++, screenYindex++) {
		for (int j = topLeftXCoord, screenXindex = 0; j < topRightXCoord; j++, screenXindex++) {
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				SDL_Rect textureLocation = { getTextureLocation(map.get(j, i)),0,16,16 };
				texture.render(screenXindex * 16, screenYindex * 16, &textureLocation);
				if (map.get(j, i)->object != nullptr) {
					SDL_Rect textureLocation = { getTextureLocation(map.get(j, i)->object.get()),0,16,16 };
					texture.render(screenXindex * 16, screenYindex * 16, &textureLocation);
				}
				if ((int)map.get(j, i)->items.size() > 0) {
					SDL_Rect textureLocation = { getTextureLocation(map.get(j, i)->items.back().get()),0,16,16 };
					texture.render(screenXindex * 16, screenYindex * 16, &textureLocation);
				}
				if (map.get(j, i)->entity != nullptr) {
						SDL_Rect textureLocation = { getTextureLocation(map.get(j, i)->entity.get()),0,16,16 };
						texture.render(screenXindex * 16, screenYindex * 16, &textureLocation);
				}
			}
		}
	}


	



	//std::string output = "";
	//int topLeftXCoord = cameraXcoord - MAP_DISPLAY_WIDTH / 2;
	//int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	//int topLeftYCoord = cameraYcoord - MAP_DISPLAY_HEIGHT / 2;
	//int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	//int currentRow = 0;
	//int currentCol = 0;
	//bool validCoord = false;
	//int currentColorPair = 1;
	//int foregroundColor;
	//int backgroundColor;

	//for (int i = topLeftYCoord; i < bottomLeftYCoord; i++) {
	//	for (int j = topLeftXCoord; j < topRightXCoord; j++) {
	//		//Check for map bounds
	//		if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
	//			Tile* tileToPrint = map.get(j, i);
	//			if (tileToPrint->entity == nullptr && (int)tileToPrint->items.size() == 0) {
	//				output += getSymbol(tileToPrint->object.get());
	//				foregroundColor = getColor(tileToPrint->object.get());
	//			}
	//			else if(tileToPrint->entity == nullptr){

	//				output += getSymbol(tileToPrint->items.back().get());
	//				foregroundColor = getColor(tileToPrint->items.back().get());
	//			}
	//			else {
	//				output += getSymbol(tileToPrint->entity.get());
	//				foregroundColor = getColor(tileToPrint->entity.get());
	//			}
	//			
	//			backgroundColor = getColor(tileToPrint);

	//			//Turn on color
	//			auto search = colorPairs.find((foregroundColor << 16) | backgroundColor);
	//			if (search != colorPairs.end()) {
	//				attron(COLOR_PAIR(search->second));
	//				currentColorPair = search->second;
	//			}
	//			else {
	//				init_pair(colorPairs.size() + 1, foregroundColor, backgroundColor);
	//				colorPairs.insert({ ((foregroundColor) << 16) | backgroundColor , colorPairs.size() + 1 });
	//				attron(COLOR_PAIR(colorPairs.size()));
	//				currentColorPair = colorPairs.size();
	//			}
	//			
	//			
	//			validCoord = true;
	//		}
	//		else {
	//			output += ' ';
	//		}

	//		mvprintw(currentRow, currentCol, output.c_str());
	//		//Turn off color
	//		if (validCoord) {
	//			attroff(COLOR_PAIR(currentColorPair));
	//			//currentColorPair++;
	//		}
	//		validCoord = false;

	//		currentCol++;
	//		output = "";
	//	}
	//	currentRow++;
	//	currentCol = 0;


	//}
	////Print coords
	//std::string coords = "(" + std::to_string(cameraXcoord) + ", " + std::to_string(cameraYcoord) + ")";
	//mvprintw(0, 0, coords.c_str());

	//if (displayingInventory)
	//	displayInventory(*player.lock());
	//refresh();
}

//Returns the color used for a tile
int GameWindow::getTextureLocation(Tile* t) {
	if (t == nullptr)
		return 0;

	switch (t->type) {
	case TileType::Grass:
		return 0;
	case TileType::Sand:
		return 0;
	default:
		return 0;

	}
}

//Returns the color used for am object
int GameWindow::getTextureLocation(Object* o) {
	if (o == nullptr)
		return 0;

	switch (o->type) {
	case ObjectType::Tree:
		return 16;
	default:
		return 0;
	}
}


//Returns the color used for am entity
int GameWindow::getTextureLocation(Entity* e) {
	if (e == nullptr)
		return 0;

	switch (e->type) {
	case EntityType::Human:
		if ((static_cast<Human*>(e))->isMan()) {
			return 32;
		}
		else {
			return 48;
		}
	default:
		return 0;
	}
}



//Returns the color used for an Item
int GameWindow::getTextureLocation(Item* i) {
	if (i == nullptr)
		return 0;

	switch (i->type) {
	case ItemType::Log:
		return 64;
	default:
		return 0;
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

void GameWindow::displayInventory(Human& h) {
	mvprintw(2, 0, "Inventory:");
	for (int i = 0; i < static_cast<int>(h.inventory.size()); i++) {
		mvprintw(i + 3, 0, h.inventory[i]->name.c_str());
	}
	refresh();
}
