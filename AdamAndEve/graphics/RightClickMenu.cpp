#include "RightClickMenu.h"
#include "Canvas.h"



RightClickMenu::RightClickMenu(Screen& s, GameMaster& g) : Element(80, 60, s), g{ g }
{
}


RightClickMenu::~RightClickMenu()
{
}


void RightClickMenu::drawElement(int x, int y, Canvas& c) {

	c.drawRectangle(x, y, 80, 60);

}


void RightClickMenu::mouseClickHandler(int x, int y, SDL_Event* e) {



}

bool RightClickMenu::coordIsNearby(int x, int y) {
	int nearbyOffset = 10;
	if (x > xPos - nearbyOffset && x < xPos + width + nearbyOffset) {
		if (y > yPos - nearbyOffset && y < yPos + height + nearbyOffset) {
			return true;
		}
	}

	return false;
}