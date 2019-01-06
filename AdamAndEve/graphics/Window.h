#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Constants.h"
#include <vector>
#include "Screen.h"
#include "Renderable.h"
#include "Canvas.h"
class Window
{
public:
	Window();
	virtual ~Window();
	std::vector<Screen*> screens;
	SDL_Window* window;
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;
	Canvas* canvas;


	void init();
	void drawWindow();
	void handleEvent(SDL_Event* e);

};

