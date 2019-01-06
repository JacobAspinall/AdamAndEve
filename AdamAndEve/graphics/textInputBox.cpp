#include "textInputBox.h"
#include "Canvas.h"


TextInputBox::~TextInputBox()
{
}

void TextInputBox::drawElement(int x, int y, Canvas& c) {
	c.drawRectangle(x, y, width, height);
	fontTexture.loadText(">" + content, SDL_Color{ 0x00, 0x00, 0x00 });
	c.draw(x + 2, y + 2, fontTexture, -1);
}

void TextInputBox::appendText(std::string text) {
	content.append(text);
}
