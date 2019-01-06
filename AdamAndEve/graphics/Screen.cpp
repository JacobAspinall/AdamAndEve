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

void Screen::addKeyPressHandler(void (*funcPtr)(Screen& s, SDL_Event& e)) {
	keyPressHandler = funcPtr;
}


void Screen::handleEvent(SDL_Event& e) {

	////if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP ) {
		if (keyPressHandler != nullptr) {
			keyPressHandler(*this, e);
		}
	//}
}

