#include "ItemBar.h"
#include "Screen.h"
#include <vector>
#include "GameWindow.h"


ItemBar::ItemBar(int width, int height, Screen& s,Texture& itemTexture, GameMaster& g) : Element(width, height, s), texture{ Texture("textures/itemBar.png",*(screen.parentWindow.canvas)) }, itemTexture{itemTexture}, g{g}
{
	texture.addClip(0, 0, 320, 40, 1);
	texture.addClip(320, 0, 36, 36, 2);
}



ItemBar::~ItemBar()
{
}

void ItemBar::drawElement(int x, int y, Canvas& c) {
	xPos = x;
	yPos = y;
	c.draw(x, y, texture, 1);
	std::vector<ItemType> inventory = g.getPlayerInventory();

	for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
		c.draw(x + 4 + 40*i, y + 4, itemTexture, getClipCode(inventory.at(i)));
	}

	if (selectedPosition != -1) {
		int xDrawPosition = x + 4 + 40 * selectedPosition - 2;
		int yDrawPosition = y + 2;
		c.draw(xDrawPosition, yDrawPosition, texture, 2);

	}
}

void ItemBar::mouseClickHandler(int x, int y, SDL_Event* e) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		x = x - xPos;
		y = y - yPos;
		if (x > 4 && x < 326 && y > 4 && y < 36) {
			if (x % 40 < 32) {
				selectedPosition = x / 40;
				g.setSelectedItem(selectedPosition);
			}
			
		}
	}
}

void ItemBar::setSelectedPosition(int position) {
	selectedPosition = position;
	g.setSelectedItem(selectedPosition);
}
