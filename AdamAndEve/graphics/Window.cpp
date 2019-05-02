#include "Window.h"




Window::Window()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Adam and Eve", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
	TTF_Init();
	canvas = new Canvas(*this);
}


Window::~Window()
{
}


void Window::init() {

	
}


void Window::drawWindow() {
	SDL_RenderClear(canvas->renderer);
	for (Screen* s : screens) {
		s->drawScreen(s->xPosition, s->yPosition, *canvas);
	}

	SDL_RenderPresent(canvas->renderer);
}

void Window::handleEvent(SDL_Event* e) {
	if(e == NULL || e->type == SDL_KEYDOWN || e->type == SDL_KEYUP || e->type == SDL_TEXTINPUT || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEWHEEL)
		screens.back()->handleEvent(e);
}
