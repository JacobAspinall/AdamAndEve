#pragma once
#include "curses.h"
#include "GameMap.h"
#include "Color.h"
#include <unordered_map>
class GameWindow
{
public:
	GameWindow(GameMap map);
	~GameWindow();
	void init();
	void refresh();

	void panNorth();
	void panEast();
	void panSouth();
	void panWest();
	int centerXCoord = 0;
	int centerYCoord = 0;

	GameMap map;

	std::unordered_map<int, int> colorPairs;
private:
	int getColor(TileType t);
	int getColor(ObjectType t);
	char getSymbol(ObjectType t);
};

