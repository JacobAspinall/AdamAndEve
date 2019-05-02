#pragma once
#include "Element.h"
#include "GameMaster.h"
#include "Screen.h"
#include "RightClickMenuButton.h"
#include <vector>

class RightClickMenu :
	public Element, Observer
{
public:
	RightClickMenu(Screen& s, GameMaster& g);
	~RightClickMenu();

	GameMaster& g;

	void drawElement(int x, int y, Canvas& c);
	void mouseClickHandler(int x, int y, SDL_Event* e);
	bool coordIsNearby(int x, int y);
	void addButton(std::string contents, GameObject& o, GameObjectAction a);
	void addListOfActions(std::vector<ActionDescription> actions);
	void clearButtons() { options.clear(); elements.clear(); }
	void update(Subject& changedSubject);
	std::vector<RightClickMenuButton> options;

};

