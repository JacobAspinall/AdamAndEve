#pragma once
#include "SDL.h"
#include <string>
#include "SDL_image.h"
class Texture
{
public:
	Texture();
	Texture(SDL_Renderer* r);
	~Texture();

	void loadImage(std::string path);

	void render(int x, int y, SDL_Rect* clip);
	SDL_Renderer* renderer;
private:

	SDL_Texture* texture;


};

