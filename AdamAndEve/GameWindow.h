#pragma once
#include "curses.h"
#include "GameMap.h"
#include "Color.h"
#include <unordered_map>
#include <memory>


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
	GameWindow(GameMap& map);
	~GameWindow();
	void init();
	void render();

	void panCameraNorth();
	void panCameraEast();
	void panCameraSouth();
	void panCameraWest();
	int cameraXcoord = 0;
	int cameraYcoord = 0;

	GameMap& map;

	std::unordered_map<int, int> colorPairs;
private:
	int getColor(Tile* t);
	int getColor(Object* o);
	char getSymbol(Object* o);
	int getColor(Entity* e);
	char getSymbol(Entity* e);
};

