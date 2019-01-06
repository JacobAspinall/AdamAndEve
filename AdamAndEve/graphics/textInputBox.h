#pragma once
class Canvas;
#include "Element.h"
#include "Texture.h"
#include "Screen.h"
#include "Window.h"

class TextInputBox:
	public Element
{
public:
	TextInputBox(int width, int height, Screen& s) : Element(width, height, s), fontTexture{ Texture("textures/fonts/OpenSans-SemiBold.ttf",*(screen.parentWindow.canvas)) }{};
	~TextInputBox();

	void drawElement(int x, int y, Canvas& c);
	void appendText(std::string text);
	std::string content = "";
	Texture fontTexture;
};
