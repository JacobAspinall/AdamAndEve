#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Constants.h"
#include <vector>
#include "Screen.h"
#include "Renderable.h"
class Window
{
public:
	Window();
	virtual ~Window();
	std::vector<Screen*> screens;
	SDL_Window* window;
	SDL_Renderer* renderer;

	void init();
	void render();
	void handleEvent(SDL_Event &e);

};

