#include "Screen.h"
#include "Window.h"



Screen::Screen(Window& window)
	:renderer{ *(window.renderer) }, texture{Texture(*(window.renderer))}
{

}


Screen::~Screen()
{
}


void Screen::loadTexture(std::string fileName) {
	texture.loadImage(fileName);
}

void Screen::createTextureClip(int x, int y, int width, int height, int clipCode) {
	clipMap[clipCode] = Clip(x,y,width,height);
}

void Screen::draw(int x, int y, int clipCode) {
	Clip thisClip = clipMap[clipCode];
	SDL_Rect clipLocation = { thisClip.x, thisClip.y, thisClip.width, thisClip.height };
	texture.render(x, y, &clipLocation);
}

void Screen::render() {

}

void Screen::addKeyPressHandler(void (*funcPtr)(Screen& s, SDL_Event& e)) {
	keyPressHandler = funcPtr;
}


void Screen::handleEvent(SDL_Event& e) {

	if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
		if (keyPressHandler != nullptr) {
			keyPressHandler(*this, e);
		}
	}
}

Screen::Clip::Clip() {

}
Screen::Clip::Clip(int x, int y, int width, int height)
	:x{ x }, y{ y }, width{ width }, height{ height }
{

}
Screen::Clip::~Clip() {

}