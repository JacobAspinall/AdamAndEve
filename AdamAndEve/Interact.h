#pragma once
#include "Task.h"
#include "Entity.h"
#include "GameMap.h"

std::unique_ptr<Task> getInteractTask(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap);
