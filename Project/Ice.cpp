#include "Ice.h"

Ice::Ice()
{
}

Ice::Ice(b2World * world, int width, sf::Vector2f postion)
	: Wall(world, width, postion)

{
	// Graphics::getInstance().
}


Ice::~Ice()
{
}

void Ice::coillision()
{
}
