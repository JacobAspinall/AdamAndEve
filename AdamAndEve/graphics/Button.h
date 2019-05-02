#pragma once
#include "Element.h"
#include "Canvas.h"
#include "TextDisplayBox.h"
#include "Subject.h"
class Button :
	public Element, public Subject
{
public:
	Button(Screen& s, std::string contents);
	~Button();

	TextDisplayBox contents;
	bool isHighlighted = false;

	void drawElement(int x, int y, Canvas& c);
	void mouseClickHandler(int x, int y, SDL_Event* e);
};

