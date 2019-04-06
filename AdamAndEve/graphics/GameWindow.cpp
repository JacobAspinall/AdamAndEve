#include "GameWindow.h"
#include "ClipCode.h"
#include "MoveInStraightLine.h"
#include "RightClickMenu.h"




GameWindow::GameWindow(GameMap& map, GameMaster& master, Window& mainWindow)
	:map{ map }, gameMaster{ master }, mainWindow{ mainWindow }, Screen(mainWindow), texture{ Texture("textures/tiles.png",*(mainWindow.canvas)) }, itemBar{ ItemBar(320,40,*this, texture, gameMaster) }
{
	this->mainWindow.screens.push_back(this);
	init();
	this->addKeyPressHandler(KeyPressHandler);
	this->addMouseClickHandler(GameWindowMouseClickHandler);
	this->xPosition = 0;
	this->yPosition = 0;
	this->width = SCREEN_WIDTH;
	this->xPosition = SCREEN_HEIGHT;
	this->elements.push_back(static_cast<Element*>(&itemBar));
}


GameWindow::~GameWindow()
{
}

//Adds clip locations for each tile/entity/item/object
void GameWindow::init() {
	
	texture.addClip(0, 0, 32, 32, ClipCode::GRASS);
	texture.addClip(32, 0, 32, 32, ClipCode::TREE);
	texture.addClip(64, 0, 32, 32, ClipCode::MAN);
	texture.addClip(96, 0, 32, 32, ClipCode::WOMAN);
	texture.addClip(128, 0, 32, 32, ClipCode::LOG);

}

//displays map on terminal based upon the camera's x and y coords
void GameWindow::drawScreen(int x, int y, Canvas& c) {

	int topLeftXCoord = (0 - SCREEN_WIDTH / 2) / 32 + cameraXcoord;
	if (SCREEN_WIDTH / 2 % 32 != 0)
		topLeftXCoord--;
	int topRightXCoord = topLeftXCoord + SCREEN_WIDTH / 32 + 2;

	int topLeftYCoord = (0 - SCREEN_HEIGHT / 2) / 32 + cameraYcoord;
	if ((SCREEN_HEIGHT/ 2  - cameraInnerYcoord)% 32 != 0)
		topLeftYCoord--;
	int bottomLeftYCoord = topLeftYCoord + SCREEN_HEIGHT / 32 + 2;
	int currentRow = 0;
	int currentCol = 0;
	bool validCoord = false;

	int startingYOffset = (SCREEN_HEIGHT / 2) - ((cameraYcoord - topLeftYCoord + 1) * 32 - (31 - cameraInnerYcoord));
	int startingXOffset = (SCREEN_WIDTH / 2) - ((cameraXcoord - topLeftXCoord + 1) * 32 - (31 - cameraInnerXcoord));

	map.mapMutex->lock();
	for (int i = topLeftYCoord, screenYindex = startingYOffset; i < bottomLeftYCoord; i++, screenYindex+=32) {
		for (int j = topLeftXCoord, screenXindex = startingXOffset; j < topRightXCoord; j++, screenXindex+=32) {
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {
				c.draw(screenXindex, screenYindex,texture, getClipCode(map.get(j, i)));
			}
		}
	}

	for (int i = topLeftYCoord, screenYindex = startingYOffset; i < bottomLeftYCoord; i++, screenYindex+=32) {
		for (int j = topLeftXCoord, screenXindex = startingXOffset; j < topRightXCoord; j++, screenXindex+=32) {
			if (i >= 0 && i < MAP_WIDTH && j >= 0 && j < MAP_WIDTH) {

				if (map.get(j, i)->object != nullptr) {
					c.draw(screenXindex, screenYindex, texture, getClipCode(map.get(j, i)->object.get()));
				}
				if ((int)map.get(j, i)->items.size() > 0) {
					c.draw(screenXindex, screenYindex, texture, getClipCode(map.get(j, i)->items.back().get()));
				}
				if (map.get(j, i)->entity != nullptr) {
					static double prevTileX = map.get(j, i)->entity->tileXCoord;
					static double prevTileY = map.get(j, i)->entity->tileYCoord;

					double currentTileX = map.get(j, i)->entity->tileXCoord;
					double currentTileY = map.get(j, i)->entity->tileYCoord;

					int prevTileXInt = std::lround(prevTileX);
					int prevTileYInt = std::lround(prevTileY);
					int currentTileXInt = std::lround(currentTileX);
					int currentTileYInt = std::lround(currentTileY);

					/*if (std::abs(currentTileX - prevTileX) == std::abs(currentTileY - prevTileY)) {
						if (currentTileXInt != prevTileXInt && currentTileYInt != prevTileYInt)
							c.draw(screenXindex + (currentTileXInt - 15), screenYindex + (currentTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
						else
							c.draw(screenXindex + (prevTileXInt - 15), screenYindex + (prevTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
					}
					else if (std::abs(currentTileX - prevTileX) > std::abs(currentTileY - prevTileY)) {
						if(currentTileXInt != prevTileXInt)
							c.draw(screenXindex + (currentTileXInt - 15), screenYindex + (currentTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
						else
							c.draw(screenXindex + (prevTileXInt - 15), screenYindex + (prevTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
					}
					else if (std::abs(currentTileX - prevTileX) < std::abs(currentTileY - prevTileY)) {
						if (currentTileYInt != prevTileYInt)
							c.draw(screenXindex + (currentTileXInt - 15), screenYindex + (currentTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
						else
							c.draw(screenXindex + (prevTileXInt - 15), screenYindex + (prevTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
					}
					else {
						c.draw(screenXindex + (currentTileXInt - 15), screenYindex + (currentTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
					}

					if (currentTileX != prevTileX || currentTileY != prevTileY) {
						prevTileX = map.get(j, i)->entity->tileXCoord;
						prevTileY = map.get(j, i)->entity->tileYCoord;
						std::cout << prevTileXInt << ", " << prevTileYInt << std::endl;
					}*/
					c.draw(screenXindex + (currentTileXInt - 15), screenYindex + (currentTileYInt - 15), texture, getClipCode(map.get(j, i)->entity.get()));
				}

			}
		}
	}
	
	//draw itemBar
	itemBar.drawElement(SCREEN_WIDTH / 2 - itemBar.width / 2, SCREEN_HEIGHT - itemBar.height - 20, c);

	//Draw right click menu
	if (menu != nullptr)
		menu->drawElement(menu->xPos, menu->yPos, c);
	

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

//Returns the texture clip code used for an Item
int getClipCode(ItemType i) {

	switch (i) {
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

	if(keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_D] && !(keyboard[SDL_SCANCODE_S] && keyboard[SDL_SCANCODE_A]))
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(std::sin(45 * (180/M_PI)),std::sin(-45 * (180 / M_PI)))));
	else if (keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_A] && !(keyboard[SDL_SCANCODE_S] && keyboard[SDL_SCANCODE_D]))
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(std::sin(-45 * (180 / M_PI)), std::sin(-45 * (180 / M_PI)))));
	else if (keyboard[SDL_SCANCODE_S] && keyboard[SDL_SCANCODE_D] && !(keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_A]))
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(std::sin(45 * (180 / M_PI)), std::sin(45 * (180 / M_PI)))));
	else if (keyboard[SDL_SCANCODE_S] && keyboard[SDL_SCANCODE_A] && !(keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_D]))
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(std::sin(-45 * (180 / M_PI)), std::sin(45 * (180 / M_PI)))));
	else if(keyboard[SDL_SCANCODE_W])
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(0, -1)));
	else if (keyboard[SDL_SCANCODE_A])
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(-1, 0)));
	else if (keyboard[SDL_SCANCODE_S])
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(0, 1)));
	else if (keyboard[SDL_SCANCODE_D])
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(1, 0)));
	else
		gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Move, MovementVector(std::sin(0), std::sin(0))));


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
			gameWindow.gameMaster.setNextMove(PlayerMove(MoveType::Interact));
			interactionKeyDown = false;
			break;
		}
	}
	gameWindow.map.mapMutex->unlock();
}


void GameWindowMouseClickHandler(Screen& window, SDL_Event* e) {
	GameWindow& gameWindow = static_cast<GameWindow&>(window);
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		
		int xCoord, yCoord, innerXCoord, innerYCoord;
		if (x < SCREEN_WIDTH / 2 + (31 - gameWindow.cameraInnerXcoord)) {
			xCoord = (x - (SCREEN_WIDTH / 2 - 1 + (31 - gameWindow.cameraInnerXcoord))) / 32 + gameWindow.cameraXcoord;
			innerXCoord = 31 + (x - (SCREEN_WIDTH / 2 - 1 + (31 - gameWindow.cameraInnerXcoord))) % 32;
		}
		else {
			xCoord = (x - (SCREEN_WIDTH / 2 + (31 - gameWindow.cameraInnerXcoord))) / 32 + gameWindow.cameraXcoord + 1;
			innerXCoord = (x - (SCREEN_WIDTH / 2 + (31 - gameWindow.cameraInnerXcoord))) % 32;
		}

		if (y < SCREEN_HEIGHT / 2 + (31 - gameWindow.cameraInnerYcoord)) {
			yCoord = (y - (SCREEN_HEIGHT / 2 - 1 + (31 - gameWindow.cameraInnerYcoord))) / 32 + gameWindow.cameraYcoord;
			innerYCoord = 31 + (y - (SCREEN_HEIGHT / 2 - 1 + (31 - gameWindow.cameraInnerYcoord))) % 32;
		}
		else {
			yCoord = (y - (SCREEN_HEIGHT / 2 + (31 - gameWindow.cameraInnerYcoord))) / 32 + gameWindow.cameraYcoord + 1;
			innerYCoord = (y - (SCREEN_HEIGHT / 2 + (31 - gameWindow.cameraInnerYcoord))) % 32;
		}	
		
		std::cout << xCoord << ", " << yCoord << "    " << innerXCoord << ", " << innerYCoord << std::endl;
		if (e->button.button == SDL_BUTTON_LEFT) {

			if (gameWindow.menu != nullptr) {
				gameWindow.menu = nullptr;
			}

			if (gameWindow.gameMaster.hasObject(xCoord, yCoord, innerXCoord, innerYCoord) && gameWindow.gameMaster.tileIsNextToPlayer(xCoord, yCoord)) {
				gameWindow.gameMaster.facePlayerTowards(xCoord, yCoord, innerXCoord, innerYCoord);
				gameWindow.gameMaster.interactWithObject(xCoord, yCoord, innerXCoord, innerYCoord);
			}
			else {
				gameWindow.gameMaster.movePlayerToCoords(xCoord, yCoord, innerXCoord, innerYCoord);
			}
		}
		else if (e->button.button == SDL_BUTTON_RIGHT) {
			
			gameWindow.menu = std::make_unique<RightClickMenu>(gameWindow, gameWindow.gameMaster);
			gameWindow.menu->xPos = x;
			gameWindow.menu->yPos = y;

		}
	}
	else if (e->type == SDL_MOUSEMOTION) {
		if (gameWindow.menu != nullptr) {
			int x, y;
			SDL_GetMouseState(&x, &y);

			if (!gameWindow.menu->coordIsNearby(x, y)) {
				gameWindow.menu = nullptr;
			}
		}
	}



}
