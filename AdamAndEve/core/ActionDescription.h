#pragma once
class GameObject;
#include <string>
#include "GameObjectAction.h"

class ActionDescription {

public:
	ActionDescription(std::string name, GameObject& o, GameObjectAction a) : name{ name }, object{ o }, action{ a } {};
	~ActionDescription() {};
	
	std::string name;
	GameObject& object;
	GameObjectAction action;

};