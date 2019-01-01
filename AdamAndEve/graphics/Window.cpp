#include "Window.h"




Window::Window()
{
}


Window::~Window()
{
}


void Window::init() {

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Adam and Eve", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
}


void Window::render() {
	SDL_RenderClear(renderer);
	for (Screen* s : screens) {
		s->render();
	}
	
	SDL_RenderPresent(renderer);
}

void Window::handleEvent(SDL_Event &e) {
	
	screens.front()->handleEvent(e);
}
