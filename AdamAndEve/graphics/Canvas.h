#pragma once
class Window;
#include "SDL.h"
#include "Texture.h"
#include "Color.h"

class Canvas
{
public:
	Canvas(Window& window);
	~Canvas();



	void draw(int x, int y, Texture& t, int clipCode);
	void drawRectangle(int x, int y, int width, int height, Color::Color c = Color::RED);
	SDL_Renderer* renderer;
private:
	Window& parentWindow;
	
	int width;
	int height;
};

