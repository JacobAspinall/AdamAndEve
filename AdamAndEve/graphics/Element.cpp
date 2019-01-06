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