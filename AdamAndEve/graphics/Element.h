#pragma once
class Canvas;
class Screen;
#include "Constants.h"

class Element
{
public:
	Element(int width, int height, Screen& s);
	~Element();

	int width;
	int height;

	Screen& screen;

	virtual void drawElement(int x, int y, Canvas& c);
};

