#pragma once
#include <string>
#include "Element.h"
#include <SDL_ttf.h>
#include "Texture.h"
#include "Screen.h"
#include "Window.h"
#include <vector>
#include "Color.h"

class TextDisplayBox:
	public Element
{
public:
	TextDisplayBox(int width, int height, Screen& s) : Element(width, height, s), fontTexture{Texture("textures/fonts/OpenSans-SemiBold.ttf",*(screen.parentWindow.canvas))}{};
	~TextDisplayBox();

	void drawElement(int x, int y, Canvas& c);
	
	Texture fontTexture;
	std::string content = "";
	Color::Color backgroundColor = Color::BLACK;
	Color::Color textColor = Color::WHITE;
	
};

std::vector<std::string> splitString(const std::string input, std::string delimiter);