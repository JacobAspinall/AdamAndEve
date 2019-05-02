#include "RightClickMenu.h"
#include "Canvas.h"
#include "Subject.h"



RightClickMenu::RightClickMenu(Screen& s, GameMaster& g) : Element(80, 60, s), g{ g }
{
	isVisible = false;

}


RightClickMenu::~RightClickMenu()
{
}

void RightClickMenu::addButton(std::string contents, GameObject& o, GameObjectAction a) {
	RightClickMenuButton b = RightClickMenuButton(screen, contents, o, a);
	b.attach(*this);
	options.push_back(b);
	elements.clear();
	for (Button& b : options) {
		elements.push_back(&b);
	}

}


void RightClickMenu::drawElement(int x, int y, Canvas& c) {

	c.drawRectangle(x, y, 82, 16 * options.size() + 2, Color::BLUE);

	int buttonIndex = 0;
	for (Button& b : options) {
		b.xPos = x + 1;
		b.yPos = y + 1 + 16 * buttonIndex;
		b.drawElement(b.xPos, b.yPos, c);
		buttonIndex++;

	}

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

void RightClickMenu::update(Subject& changedSubject) {
	RightClickMenuButton& b = static_cast<RightClickMenuButton&>(changedSubject);

	//b.gameObject.executeAction(g.player, g.map, b.action);
}

void RightClickMenu::addListOfActions(std::vector<ActionDescription> actions) {
	for (ActionDescription a : actions) {
		this->addButton(a.name, a.object, a.action);
	}

}