#pragma once
class Window;
#include "SDL.h"
#include "Texture.h"
#include <string>
#include <unordered_map>

class Screen
{
public:
	Screen(Window& window);
	~Screen();

	int xPosition = 0;
	int yPosition = 0;
	int width = 0;
	int height = 0;

	bool isVisible = true;

	void loadTexture(std::string fileName);
	void draw(int x, int y, int clipCode);
	void createTextureClip(int x, int y, int width, int height, int clipCode);
	virtual void render();
	void addKeyPressHandler(void(*funcPtr)(Screen& s, SDL_Event& e));
	void handleEvent(SDL_Event& e);


	void (*keyPressHandler)(Screen& s, SDL_Event& e) = nullptr;

private:
	SDL_Renderer& renderer;

	Texture texture;
	class Clip;
	std::unordered_map<int,Clip> clipMap;

	class Clip {
	public:
		Clip();
		Clip(int x, int y, int width, int height);
		~Clip();

		int x;
		int y;
		int width;
		int height;

	};

};

