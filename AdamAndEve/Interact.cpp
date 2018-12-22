#include "Interact.h"
#include "Entity.h"
#include "GameMap.h"
#include "Object.h"




Interact::~Interact()
{
}

int Interact::run() {
	if (map.tileInFrontof(entity) == nullptr || map.tileInFrontof(entity)->object == nullptr) {
		entity.endCurrentTask();
		return 1;
	}
	else {
		return map.tileInFrontof(entity)->object->interact(entity, map);
	}

}