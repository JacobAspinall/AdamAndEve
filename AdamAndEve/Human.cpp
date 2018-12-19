#include "Human.h"


Human::Human() {

}

Human::Human(bool gender)
	:gender(gender)
{
	type = EntityType::Human;
}


Human::~Human()
{
}
