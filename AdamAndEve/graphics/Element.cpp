#include "Element.h"
#include "Screen.h"
#include "Canvas.h"


Element::Element(int width, int height, Screen& s)
	:width{ width }, height{ height }, screen{ s }
{
}


Element::~Element()
{
}


void Element::drawElement(int x, int y, Canvas& c) {

}

bool Element::coordIsInsideElement(int x, int y) {
	if (x >= xPos && x <= xPos + width) {
		if (y >= yPos && y <= yPos + height) {
			return true;
		}
	}
	return false;
}

void Element::handleEvent(SDL_Event* e) {

	if (e == nullptr || e->type == SDL_KEYDOWN || e->type == SDL_KEYUP || e->type == SDL_TEXTINPUT) {
		//Element key press handler
	}
	else if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP/* || e->type == SDL_MOUSEMOTION*/) {
			bool clickedOnElement = false;
			int x, y;
			SDL_GetMouseState(&x, &y);
			for (Element *element : elements) {
				if (element->coordIsInsideElement(x, y) && !clickedOnElement && element->isVisible) {
					element->handleEvent(e);
					clickedOnElement = true;
				}
			}
			if (!clickedOnElement)
				mouseClickHandler(x,y, e);
	}
}