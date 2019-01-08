#include "GameWindow.h"
#include "ClipCode.h"




GameWindow::GameWindow(GameMap& map, GameMaster& master, Window& mainWindow)
	:map{ map }, gameMaster{ master }, mainWindow{ mainWindow }, Screen(mainWindow), texture{Texture("textures/tiles.png",*(mainWindow.canvas))}
{
	this->mainWindow.screens.push_back(this);
	init();
	this->addKeyPressHandler(KeyPressHandler);
	this->xPosition = 0;
	this->yPosition = 0;
	this->width = SCREEN_WIDTH;
	this->xPosition = SCREEN_HEIGHT;
}


GameWindow::~GameWindow()
{
}

//Adds clip locations for each tile/entity/item/object
void GameWindow::init() {
	
	texture.addClip(0, 0, 16, 16, ClipCode::GRASS);
	texture.addClip(16, 0, 16, 16, ClipCode::TREE);
	texture.addClip(32, 0, 16, 16, ClipCode::MAN);
	texture.addClip(48, 0, 16, 16, ClipCode::WOMAN);
	texture.addClip(64, 0, 16, 16, ClipCode::LOG);

}

//displays map on terminal based upon the camera's x and y coords
void GameWindow::drawScreen(int x, int y, Canvas& c) {

	int topLeftXCoord = cameraXcoord - MAP_DISPLAY_WIDTH / 2;
	int topRightXCoord = topLeftXCoord + MAP_DISPLAY_WIDTH;
	int topLeftYCoord = cameraYcoord - MAP_DISPLAY_HEIGHT / 2;
	int bottomLeftYCoord = topLeftYCoord + MAP_DISPLAY_HEIGHT;
	int currentRow = 0;
	int currentCol = 0;
	bool validCoord = false;

	map.mapMutex->lock();
	for (int i = topLeftYCoord, screenYindex = 0; i < bottomLeftYCoord; i++, screenYindex++) {
		for (int j = topLeftXCoord, screenXindex = 0; j < topRightXCoord; j++, screenXindex++) {
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				
				c.draw(screenXindex * 16, screenYindex * 16,texture, getClipCode(map.get(j, i)));
				if (map.get(j, i)->object != nullptr) {
					c.draw(screenXindex * 16, screenYindex * 16, texture, getClipCode(map.get(j, i)->object.get()));
				}
				if ((int)map.get(j, i)->items.size() > 0) {
					c.draw(screenXindex * 16, screenYindex * 16, texture, getClipCode(map.get(j, i)->items.back().get()));
				}
				if (map.get(j, i)->entity != nullptr) {
					c.draw(screenXindex * 16, screenYindex * 16, texture, getClipCode(map.get(j, i)->entity.get()));
				}
				
			}
		}
	}
	map.mapMutex->unlock();
}

//Returns the texture clip code used for a tile
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

//Returns the texture clip code used for am object
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


//Returns the texture clip code used for am entity
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



//Returns the texture clip code used for an Item
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



void KeyPressHandler(Screen& window, SDL_Event* e){
	if (e == nullptr)
		return;
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	
	GameWindow& gameWindow = static_cast<GameWindow&>(window);
	gameWindow.map.mapMutex->lock();
	static bool interactionKeyDown = false;


	if(keyboard[SDL_SCANCODE_W])
		gameWindow.gameMaster.setNextMove(MoveType::North);
	else if (keyboard[SDL_SCANCODE_A])
		gameWindow.gameMaster.setNextMove(MoveType::West);
	else if (keyboard[SDL_SCANCODE_S])
		gameWindow.gameMaster.setNextMove(MoveType::South);
	else if (keyboard[SDL_SCANCODE_D])
		gameWindow.gameMaster.setNextMove(MoveType::East);
	else
		gameWindow.gameMaster.setNextMove(MoveType::NoAction);


	if (e->type == SDL_KEYDOWN) {
		switch (e->key.keysym.sym)
		{
		case SDLK_f:
			interactionKeyDown = true;
			break;
		}
	}
	if (e->type == SDL_KEYUP)
	{
		switch (e->key.keysym.sym)
		{
		case SDLK_f:
			gameWindow.gameMaster.setNextMove(MoveType::Interact);
			interactionKeyDown = false;
			break;
		}
	}
	gameWindow.map.mapMutex->unlock();
}
