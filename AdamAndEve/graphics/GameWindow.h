#pragma once
#include "curses.h"
#include "GameMap.h"
#include "GameMaster.h"
#include "Player.h"
#include "Color.h"
#include <unordered_map>
#include <memory>
#include "SDL.h"
#include "Texture.h"
#include "SDL_image.h"


//Renders the game map onto the terminal
//
//Example:
//		GameMap g = GameMap();
//		GameWindow g = GameWindow(map);
//		g.init();
//		while(1){
//			//update map
//			...
//			g.render();
//		}
class GameWindow
{
public:
	GameWindow(GameMap& map, GameMaster& master);
	~GameWindow();
	void init();
	void render();

	void panCameraNorth();
	void panCameraEast();
	void panCameraSouth();
	void panCameraWest();
	void displayInventory(Human& h);
	int cameraXcoord = 0;
	int cameraYcoord = 0;
	bool devConsoleEnabled = false;
	std::weak_ptr<Player> player;

	void KeyPressHandler(SDL_Event& e,  bool isStartOfTick);

	GameMap& map;
	GameMaster& gameMaster;
	//////
	SDL_Window* mainWindow = NULL;
	SDL_Renderer* renderer = NULL;
	Texture texture;

	///////
	std::unordered_map<int, int> colorPairs;
private:
	int getTextureLocation(Tile* t);
	int getTextureLocation(Object* o);
	int getTextureLocation(Entity* e);
	int getTextureLocation(Item* i);
};

