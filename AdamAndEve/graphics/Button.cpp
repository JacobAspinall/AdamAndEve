#include "Button.h"



Button::Button(Screen& s, std::string text) : Element(80, 16, s), contents{TextDisplayBox(80,16,s)}
{
	this->contents.content = text;
}


Button::~Button()
{
}

void Button::drawElement(int x, int y, Canvas& c) {


	contents.backgroundColor = Color::BLACK;
	contents.drawElement(x, y, c);

}

void Button::mouseClickHandler(int x, int y, SDL_Event* e) {
	notify();

}
