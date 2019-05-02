#pragma once
class Canvas;
class Screen;
#include "SDL.h"
#include "Constants.h"
#include <vector>

class Element
{
public:
	Element(int width, int height, Screen& s);
	~Element();

	int width;
	int height;
	int xPos;
	int yPos;
	bool isVisible = true;

	Screen& screen;

	std::vector<Element*> elements;

	virtual void drawElement(int x, int y, Canvas& c);
	virtual void mouseClickHandler(int x, int y, SDL_Event* e) {};
	virtual bool coordIsInsideElement(int x, int y);
	virtual void handleEvent(SDL_Event* e);
};

