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
	GameWindow(GameMap map);
	~GameWindow();
	void init();
	void render();

	void panCameraNorth();
	void panCameraEast();
	void panCameraSouth();
	void panCameraWest();
	int cameraXcoord = 0;
	int cameraYCoord = 0;

	GameMap map;

	std::unordered_map<int, int> colorPairs;
private:
	int getColor(std::shared_ptr<Tile> t);
	int getColor(std::shared_ptr<Object> o);
	char getSymbol(std::shared_ptr<Object> o);
	int getColor(std::shared_ptr<Entity> e);
	char getSymbol(std::shared_ptr<Entity> e);
};

