#pragma once
class Window;
#include "SDL.h"
#include "Texture.h"
#include <string>
#include <unordered_map>
#include "Element.h"

class Screen
{
public:
	Screen(Window& window);
	~Screen();
	Window& parentWindow;

	int xPosition = 0;
	int yPosition = 0;
	int width = 0;
	int height = 0;

	bool isVisible = true;

	std::vector<Element*> elements;

	void loadTexture(std::string fileName);
	virtual void drawScreen(int x, int y, Canvas& c);
	virtual void render();
	void addKeyPressHandler(void(*funcPtr)(Screen& s, SDL_Event* e));
	void handleEvent(SDL_Event* e);


	void (*keyPressHandler)(Screen& s, SDL_Event* e) = nullptr;

private:
	

	Texture texture;
	

};

