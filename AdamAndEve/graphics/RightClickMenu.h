#pragma once
#include "Element.h"
#include "GameMaster.h"
#include "Screen.h"

class RightClickMenu :
	public Element
{
public:
	RightClickMenu(Screen& s, GameMaster& g);
	~RightClickMenu();

	GameMaster& g;

	void drawElement(int x, int y, Canvas& c);
	void mouseClickHandler(int x, int y, SDL_Event* e);
	bool coordIsNearby(int x, int y);
};

