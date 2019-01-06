#include "Texture.h"
#include "Canvas.h"



Texture::Texture(std::string path, Canvas& c)
	:renderer {c.renderer}
{
	if (path.substr(path.length() - 4, std::string::npos) == ".png") {
		loadImage(path);
	}
	else if (path.substr(path.length() - 4, std::string::npos) == ".ttf") {
		loadFontFile(path);
	}
}

Texture::Texture(const Texture& obj) 
	:renderer{obj.renderer}, texture{obj.texture}
{


}


Texture::~Texture()
{
}

void Texture::loadImage(std::string path) {
	SDL_DestroyTexture(texture);
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	width = 16;
	height = 16;
	texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

}

void Texture::loadFontFile(std::string path) {
	font = TTF_OpenFont(path.c_str(), 12);

}

void Texture::loadText(std::string textureText, SDL_Color textColor) {
	SDL_DestroyTexture(texture);
	texture = NULL;
	if (textureText.length() > 0) {
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
		width = textSurface->w;
		height = textSurface->h;
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
}

void Texture::addClip(int x, int y, int width, int height, int clipCode) {
	clipMap[clipCode] = Clip(x, y, width, height);
}


SDL_Rect Texture::getClip(int clipCode) {
	if (clipCode >= 0) {
		Clip clip = clipMap[clipCode];
		return SDL_Rect{ clip.x,clip.y,clip.width,clip.height };
	}
	else {
		return SDL_Rect{ 0,0,width,height };
	}
}

Texture::Clip::Clip() {

}
Texture::Clip::Clip(int x, int y, int width, int height)
	:x{ x }, y{ y }, width{ width }, height{ height }
{}

Texture::Clip::~Clip() {

}





