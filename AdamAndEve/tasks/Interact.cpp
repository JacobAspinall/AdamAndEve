#include "Interact.h"
#include "Entity.h"
#include "GameMap.h"
#include "Object.h"




Interact::~Interact()
{
}

int Interact::run() {

	if (map.tileInFrontof(entity)->object != nullptr) {
		return map.tileInFrontof(entity)->object->interact(entity, map);
	}
	else {
		return map.tileInFrontof(entity)->interact(entity, map);
	}


}