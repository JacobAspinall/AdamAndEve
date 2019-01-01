#pragma once
#include "curses.h"
#include "GameMap.h"
#include "GameMaster.h"
#include "Player.h"
#include "Color.h"
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Window.h"
#include "Screen.h"
#include "Renderable.h"



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
class GameWindow:
	public Screen
{
public:
	GameWindow(GameMap& map, GameMaster& master, Window& mainWindow);
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
	std::weak_ptr<Player> player;
	bool startOfTick = false;

	

	GameMap& map;
	GameMaster& gameMaster;
	Window& mainWindow;

private:
	int getClipCode(Tile* t);
	int getClipCode(Object* o);
	int getClipCode(Entity* e);
	int getClipCode(Item* i);
};

void KeyPressHandler(Screen& window, SDL_Event& e);

