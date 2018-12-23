#include "Texture.h"


Texture::Texture()
{
}

Texture::Texture(SDL_Renderer* r)
{
	renderer = r;
	loadImage("textures/tiles.png");
}


Texture::~Texture()
{
}

void Texture::loadImage(std::string path) {
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

}

void Texture::render(int x, int y, SDL_Rect* clip) {

	SDL_Rect renderQuad = { x, y, 16, 16 };




	//Render texture to screen
	SDL_RenderCopy(renderer, texture, clip, &renderQuad);


}


