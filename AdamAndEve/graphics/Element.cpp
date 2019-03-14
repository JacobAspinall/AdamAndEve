#include "Element.h"
#include "Screen.h"
#include "Canvas.h"


Element::Element(int width, int height, Screen& s)
	:width{ width }, height{ height }, screen{ s }
{
}


Element::~Element()
{
}


void Element::drawElement(int x, int y, Canvas& c) {

}

bool Element::coordIsInsideElement(int x, int y) {
	if (x >= xPos && x <= xPos + width) {
		if (y >= yPos && y <= yPos + height) {
			return true;
		}
	}
	return false;
}