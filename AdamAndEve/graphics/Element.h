#pragma once
class Canvas;
class Screen;
#include "SDL.h"
#include "Constants.h"

class Element
{
public:
	Element(int width, int height, Screen& s);
	~Element();

	int width;
	int height;
	int xPos;
	int yPos;

	Screen& screen;

	virtual void drawElement(int x, int y, Canvas& c);
	virtual void mouseClickHandler(int x, int y, SDL_Event* e) {};
	virtual bool coordIsInsideElement(int x, int y);
};

