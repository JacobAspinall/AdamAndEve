#pragma once
#include "Task.h"
#include "Entity.h"
#include "GameMap.h"

std::unique_ptr<Task> getInteractTask(Entity& e, GameMap& myMap);
