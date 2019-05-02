#pragma once
#include "Element.h"
#include "Texture.h"
#include "Screen.h"
#include "Window.h"
#include "GameMaster.h"
#include "Texture.h"
#include "SDL.h"
class ItemBar :
	public Element
{
public:
	ItemBar(int width, int height, Screen& s, Texture& itemTexture, GameMaster& g);
	~ItemBar();

	Texture texture;
	Texture& itemTexture;
	GameMaster& g;


	void drawElement(int x, int y, Canvas& c);
	void mouseClickHandler(int x, int y, SDL_Event* e);
	void setSelectedPosition(int position);
	int getSelectedPosition() { return selectedPosition; };

private:
	int selectedPosition = 0;
};

