#pragma once
#include "Button.h"
#include "GameObject.h"
#include "GameObjectAction.h"
class RightClickMenuButton :
	public Button
{
public:
	RightClickMenuButton(Screen& s, std::string contents, GameObject& object, GameObjectAction a);
	~RightClickMenuButton();

	GameObject& gameObject;
	GameObjectAction action;
};

