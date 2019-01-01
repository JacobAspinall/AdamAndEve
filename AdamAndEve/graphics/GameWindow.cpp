#include "GameWindow.h"
#include "ClipCode.h"




GameWindow::GameWindow(GameMap& map, GameMaster& master, Window& mainWindow)
	:map{ map }, gameMaster{ master }, mainWindow{ mainWindow }, Screen(mainWindow)
{
	this->mainWindow.screens.push_back(this);
	init();
	this->addKeyPressHandler(KeyPressHandler);
}


GameWindow::~GameWindow()
{
}

//Runs necessary initialization functions from PDcurses
void GameWindow::init() {
	createTextureClip(0, 0, 16, 16, ClipCode::GRASS);
	createTextureClip(16, 0, 16, 16, ClipCode::TREE);
	createTextureClip(32, 0, 16, 16, ClipCode::MAN);
	createTextureClip(48, 0, 16, 16, ClipCode::WOMAN);
	createTextureClip(64, 0, 16, 16, ClipCode::LOG);

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
				draw(screenXindex * 16, screenYindex * 16, getClipCode(map.get(j, i)));
				if (map.get(j, i)->object != nullptr) {
					draw(screenXindex *16, screenYindex *16, getClipCode(map.get(j, i)->object.get()));
				}
				if ((int)map.get(j, i)->items.size() > 0) {
					draw(screenXindex * 16, screenYindex * 16, getClipCode(map.get(j, i)->items.back().get()));
				}
				if (map.get(j, i)->entity != nullptr) {
					draw(screenXindex * 16, screenYindex * 16, getClipCode(map.get(j, i)->entity.get()));
				}
			}
		}
	}
}

//Returns the color used for a tile
int GameWindow::getClipCode(Tile* t) {
	if (t == nullptr)
		return 0;

	switch (t->type) {
	case TileType::Grass:
		return ClipCode::GRASS;
	case TileType::Sand:
		return 0;
	default:
		return 0;

	}
}

//Returns the color used for am object
int GameWindow::getClipCode(Object* o) {
	if (o == nullptr)
		return 0;

	switch (o->type) {
	case ObjectType::Tree:
		return ClipCode::TREE;
	default:
		return 0;
	}
}


//Returns the color used for am entity
int GameWindow::getClipCode(Entity* e) {
	if (e == nullptr)
		return 0;

	switch (e->type) {
	case EntityType::Human:
		if ((static_cast<Human*>(e))->isMan()) {
			return ClipCode::MAN;
		}
		else {
			return ClipCode::WOMAN;
		}
	default:
		return 0;
	}
}



//Returns the color used for an Item
int GameWindow::getClipCode(Item* i) {
	if (i == nullptr)
		return 0;

	switch (i->type) {
	case ItemType::Log:
		return ClipCode::LOG;
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


void KeyPressHandler(Screen& window, SDL_Event& e){
	GameWindow& gameWindow = static_cast<GameWindow&>(window);
	bool isStartOfTick = gameWindow.startOfTick;
	gameWindow.startOfTick = false;
	static bool northKeyDown = false;
	static bool southKeyDown = false;
	static bool eastKeyDown = false;
	static bool westKeyDown = false;
	static bool interactionKeyDown = false;

	MoveType nextMove = MoveType::NoAction;

	bool northKeyStartedDown = false;
	bool eastKeyStartedDown = false;
	bool westKeyStartedDown = false;
	bool southKeyStartedDown = false;

	if(isStartOfTick)
		gameWindow.gameMaster.setNextMove(MoveType::NoAction);

	if(isStartOfTick && northKeyDown)
		northKeyStartedDown = true;

	if (isStartOfTick && eastKeyDown)
		eastKeyStartedDown = true;

	if (isStartOfTick && southKeyDown)
		southKeyStartedDown = true;

	if (isStartOfTick && westKeyDown)
		westKeyStartedDown = true;

	
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			gameWindow.gameMaster.setNextMove(MoveType::North);
			northKeyDown = true;
			break;

		case SDLK_a:
			gameWindow.gameMaster.setNextMove(MoveType::West);
			westKeyDown = true;
			break;

		case SDLK_s:
			gameWindow.gameMaster.setNextMove(MoveType::South);
			southKeyDown = true;
			break;

		case SDLK_d:
			gameWindow.gameMaster.setNextMove(MoveType::East);
			eastKeyDown = true;
			break;

		case SDLK_f:
			interactionKeyDown = true;
			break;

		default:
			gameWindow.gameMaster.setNextMove(MoveType::NoAction);
			break;
		}
	}

	if (e.type == SDL_KEYUP)
	{
		//Select surfaces based on key press
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			if (northKeyDown) {
				if (northKeyStartedDown) {
					gameWindow.gameMaster.setNextMove(MoveType::NoAction);
				}
				else {
					gameWindow.gameMaster.setNextMove(MoveType::North);
				}
				northKeyDown = false;
			}
			break;

		case SDLK_a:
			if (westKeyDown) {
				if (westKeyStartedDown) {
					gameWindow.gameMaster.setNextMove(MoveType::NoAction);
				}
				else {
					gameWindow.gameMaster.setNextMove(MoveType::West);
				}
				westKeyDown = false;
			}
			break;

		case SDLK_s:
			if (southKeyDown) {
				if (southKeyStartedDown) {
					gameWindow.gameMaster.setNextMove(MoveType::NoAction);
				}
				else {
					gameWindow.gameMaster.setNextMove(MoveType::South);
				}
				southKeyDown = false;
			}
			break;

		case SDLK_d:
			if (westKeyDown) {
				if (westKeyStartedDown) {
					gameWindow.gameMaster.setNextMove(MoveType::NoAction);
				}
				else {
					gameWindow.gameMaster.setNextMove(MoveType::West);
				}
				westKeyDown = false;
			}
			break;

		case SDLK_f:
			if (interactionKeyDown) {
				gameWindow.gameMaster.setNextMove(MoveType::Interact);
				interactionKeyDown = false;
			}
			break;

		default:
			gameWindow.gameMaster.setNextMove(MoveType::NoAction);
			break;
		}
	}
	
}
