#include "TextDisplayBox.h"
#include "Screen.h"






TextDisplayBox::~TextDisplayBox()
{
}

void TextDisplayBox::drawElement(int x, int y, Canvas& c){

	std::vector<std::string> delimitedContent = splitString(content, "\n");
	c.drawRectangle(x, y, width, height);
	for (int i = 0; i < static_cast<int>(delimitedContent.size()); i++) {
		fontTexture.loadText(delimitedContent[i], SDL_Color{ 0x00, 0x00, 0x00 });
		c.draw(x + 10, y + 10 + i*14, fontTexture, -1);
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
