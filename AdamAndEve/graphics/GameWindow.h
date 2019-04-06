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
#include "ItemBar.h"
#include "RightClickMenu.h"



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
	void drawScreen(int x, int y, Canvas& c);

	void panCameraNorth();
	void panCameraEast();
	void panCameraSouth();
	void panCameraWest();
	int cameraXcoord = 0;
	int cameraYcoord = 0;
	int cameraInnerXcoord = 15;
	int cameraInnerYcoord = 15;
	std::weak_ptr<Player> player;
	bool startOfTick = false;
	

	
	Texture texture;
	GameMap& map;
	GameMaster& gameMaster;
	Window& mainWindow;
	ItemBar itemBar;
	std::unique_ptr<RightClickMenu> menu;

private:
	int getClipCode(Tile* t);
	int getClipCode(Object* o);
	int getClipCode(Entity* e);
	int getClipCode(Item* i);

	std::vector<Tile> lastMove;
	std::vector<Tile> thisMove;
};

void KeyPressHandler(Screen& window, SDL_Event* e);
void GameWindowMouseClickHandler(Screen& window, SDL_Event* e);
int getClipCode(ItemType i);

