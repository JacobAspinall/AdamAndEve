#pragma once
class Canvas;
#include "SDL.h"
#include <string>
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <unordered_map>

class Texture
{
public:
	Texture(std::string path, Canvas& c);
	Texture(const Texture& obj);
	~Texture();


	void loadImage(std::string path);
	void loadFontFile(std::string path);
	void loadText(std::string textureText, SDL_Color textColor);
	void addClip(int x, int y, int width, int height, int clipCode);
	SDL_Rect getClip(int clipCode);


	TTF_Font* font;
	int width;
	int height;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	class Clip;
	std::unordered_map<int, Clip> clipMap;

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
private:

	



};

