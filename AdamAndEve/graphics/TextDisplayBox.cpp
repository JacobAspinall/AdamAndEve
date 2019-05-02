#include "TextDisplayBox.h"
#include "Screen.h"






TextDisplayBox::~TextDisplayBox()
{
}

void TextDisplayBox::drawElement(int x, int y, Canvas& c){

	std::vector<std::string> delimitedContent = splitString(content, "\n");
	c.drawRectangle(x, y, width, height, backgroundColor);
	for (int i = 0; i < static_cast<int>(delimitedContent.size()); i++) {
		fontTexture.loadText(delimitedContent[i], SDL_Color{ static_cast<Uint8>(textColor.red), static_cast<Uint8>(textColor.green), static_cast<Uint8>(textColor.blue) });
		c.draw(x + 2, y + 2 + i*16, fontTexture, -1);
	}

}

std::vector<std::string> splitString(const std::string input, std::string delimiter) {
	std::string s = std::string(input);
	std::vector<std::string> splitString;
	int pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		splitString.push_back(s.substr(0, pos));
		s.erase(0, pos + 1);
	}
	splitString.push_back(s);
	return splitString;
}
