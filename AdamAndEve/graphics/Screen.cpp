#include "Screen.h"
#include "Window.h"



Screen::Screen(Window& window)
	:texture{Texture("textures/tiles.png",*(window.canvas))}, parentWindow{window}
{

}


Screen::~Screen()
{
}


void Screen::loadTexture(std::string fileName) {
	texture.loadImage(fileName);
}




void Screen::drawScreen(int x, int y, Canvas& c) {

}



void Screen::render() {

}

void Screen::addKeyPressHandler(void (*funcPtr)(Screen& s, SDL_Event* e)) {
	keyPressHandler = funcPtr;
}

void Screen::addMouseClickHandler(void(*funcPtr)(Screen& s, SDL_Event* e)) {
	mouseClickHandler = funcPtr;
}


void Screen::handleEvent(SDL_Event* e) {

	if (e == nullptr || e->type == SDL_KEYDOWN || e->type == SDL_KEYUP || e->type == SDL_TEXTINPUT) {
		if (keyPressHandler != nullptr) {
			keyPressHandler(*this, e);
		}
	}
	else if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEMOTION) {
		if (mouseClickHandler != nullptr) {
			bool clickedOnElement = false;
			for (Element *element : elements) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (element->coordIsInsideElement(x, y) && !clickedOnElement) {
					element->mouseClickHandler(x, y, e);
					clickedOnElement = true;
				}
			}
			if(!clickedOnElement)
				mouseClickHandler(*this, e);
		}
	}
}

