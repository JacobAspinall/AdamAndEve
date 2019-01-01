#pragma once
#include "Window.h"
#include "GameMaster.h"
#include "Constants.h"
class DevConsole :
	public Window
{
public:
	DevConsole();
	~DevConsole();
	void KeyPressHandler(SDL_Event& e);
	void render();

};

